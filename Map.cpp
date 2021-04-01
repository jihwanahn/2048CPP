#include "Map.h"

#include <iostream>

Map::Map(int size)
{
    this->size = size;
}

void Map::SetSize(int newSize)
{
    this->size = newSize;
}

int Map::GetSize()
{
    return this->size;
}

void Map::ResetMap()
{
    for (int i = 0; i < size; i++)
    {
        std::vector<int> row;
        row.reserve(size);
        for (int j = 0; j < size; j++)
        {
            row.push_back(0);
        }
        map.push_back(row);
    }
}

void Map::SetValue(int y, int x, int val)
{
    map.at(y).at(x) = val;
}

int Map::GetValue(int y, int x)
{
    return map.at(y).at(x);
}

void Map::RandomSpawn()
{
    int i = rand() % size;
    int j = rand() % size;

    while (0 != GetValue(i, j))
    {
        i = rand() % size;
        j = rand() % size;
    }

    int k = rand() % 100 + 1;

    if (k > 20)
    {
        SetValue(i, j, 2);
    }
    else
    {
        SetValue(i, j, 4);
    }
}

int Map::MoveLeft()
{
    int addingScore = 0;
    for(int i = 0 ; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(GetValue(i,j) > 0)
            {
                int x = j;
                while(x >= 1)
                {
                    if(GetValue(i, x -1) == 0)
                    {
                        SetValue(i, x - 1, GetValue(i, x));
                        SetValue(i, x, 0);
                    }
                    else if(GetValue(i, x - 1) == GetValue(i, x))
                    {
                        int newValue = GetValue(i, x) * 2;
                        SetValue(i, x - 1, newValue);
                        SetValue(i, x, 0);
                        addingScore += newValue;
                        break;
                    }
                    x--;
                }
            }
        }
    }
    return addingScore;
}

int Map::MoveRight()
{
    int addingScore = 0;

    for (int i = 0; i < size; i++) {

        for (int j = size - 1; j >= 0; j--) {

            if (GetValue(i, j) > 0) {

                int x = j;
                while (x < size - 1) {

                    if (GetValue(i, x + 1) == 0) {

                        SetValue(i, x + 1, GetValue(i, x));
                        SetValue(i, x, 0);
                    }
                    else if (GetValue(i, x + 1) == GetValue(i, x)) {

                        int newValue = GetValue(i, x) * 2;
                        SetValue(i, x + 1, newValue);
                        SetValue(i, x, 0);
                        addingScore += newValue;
                        break;
                    }
                    x++;
                }
            }
        }
    }
    return addingScore;
}

int Map::MoveUp()
{
    int addingScore = 0;

    for (int j = 0; j < size; j++) {

        for (int i = 0; i < size; i++) {

            if (GetValue(i, j) > 0) {

                int y = i;
                while (y > 0) {

                    if (GetValue(y - 1, j) == 0) {

                        SetValue(y - 1, j, GetValue(y, j));
                        SetValue(y, j, 0);
                    }
                    else if (GetValue(y - 1, j) == GetValue(y, j)) {

                        int newValue = GetValue(y, j) * 2;
                        SetValue(y - 1, j, newValue);
                        SetValue(y, j, 0);
                        addingScore += newValue;
                        break;
                    }
                    y--;
                }
            }
        }
    }
    return addingScore;
}

int Map::MoveDown()
{
    int addingScore = 0;

    for (int j = 0; j < size; j++) {

        for (int i = size - 2; i >= 0; i--) {

            if (GetValue(i, j) > 0) {

                int y = i;
                while (y < size - 1) {

                    if (GetValue(y + 1, j) == 0) {

                        SetValue(y + 1, j, GetValue(y, j));
                        SetValue(y, j, 0);
                    }
                    else if (GetValue(y + 1, j) == GetValue(y, j)) {
                        const int newValue = GetValue(y, j) * 2;
                        SetValue(y + 1, j, newValue);
                        SetValue(y, j, 0);
                        addingScore += newValue;
                        break;
                    }
                    y++;
                }
            }
        }
    }
    return addingScore;
}

bool Map::operator!=(Map& otherMap)
{
    if(this->size != otherMap.size)
    {
        return true;
    }
    for(int i = 0; i < this->size; i++)
    {
        for(int j = 0 ; j < this->size; j++)
        {
            if(this->GetValue(i,j) != otherMap.GetValue(i,j))
            {
                return true;
            }
        }
    }
    return false;
}

void Map::Print()
{
    for(int i = 0 ; i < size ; i++)
    {
        for (int j = 0; j < size;j++)
        {
            std::cout << GetValue(i, j);
        }
        std::cout << std::endl;
    }
}
