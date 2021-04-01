#pragma once

#include <vector>

class Map
{
public:
    
    Map(int size);

    void SetSize(int newSize);
    int GetSize();

    void ResetMap();
  
    void SetValue(int y, int x, int val);

    int GetValue(int y, int x);

    void RandomSpawn();

    int MoveLeft();
    int MoveRight();
    int MoveUp();
    int MoveDown();

    bool operator != (Map& otherMap);

    void Print();

private:
    std::vector<std::vector<int>> map;

    int size;
};
