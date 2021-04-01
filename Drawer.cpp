#include "Drawer.h"

#include <cmath>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Map.h"

void Drawer::GoToYX(int y, int x)
{
	static HANDLE h = nullptr;
	if(!h)
	{
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = { x,y };
	SetConsoleCursorPosition(h, c);
}

void Drawer::TextColor(int color)
{
    const HANDLE mColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mColor, color);
	
}

int Drawer::GetThingColor(char c)
{
	if(c == '/' || c == '\\')
	{
		return 11;
	}
	else if(c == '|')
	{
		return 14;
	}
	else if(c == '-')
	{
		return 10;
	}
	else
	{
		return 15;
	}
}

char Drawer::MapThing(int y, int x, int maxY, int maxX)
{
	if (y == 0 && x == 0) {

		return '/';
	}
	else if (y == 0 && x == maxX - 1) {

		return '\\';
	}
	else if (y == maxY - 1 && x == 0) {

		return '\\';
	}
	else if (y == maxY - 1 && x == maxX - 1) {

		return '/';
	}
	else if (x % 7 == 0) {

		return '|';
	}
	else if (y % 2 == 0) {

		return '-';
	}
	else {

		return ' ';
	}
}

int Drawer::GetValColor(int val)
{
	int key = log(val) / log(2);

	switch (key) {

	case 1:
		return 15;

	case 2:
		return 14;

	case 3:
		return 14;

	case 4:
		return 14;

	case 5:
		return 13;

	case 6:
		return 13;

	case 7:
		return 13;

	case 8:
		return 12;

	case 9:
		return 12;

	case 10:
		return 10;

	case 11:
		return 10;
	}
	return 0;
}

void Drawer::PrintScore(int score, int size)
{
    std::string sc_str = std::to_string(score);
	TextColor(11);
	GoToYX(size * 2 + 3, 0);
    std::cout << "Score: " << score;
	TextColor(0);
}

void Drawer::Draw(Map& map)
{
	GoToYX(1, 0);

	int maxY = map.GetSize() * 2 + 1;
	int maxX = map.GetSize() * 6 + map.GetSize() + 1;

	for (int i = 0; i < maxY; i++) {

		for (int j = 0; j < maxX; j++) {

			char m = MapThing(i, j, maxY, maxX);
			TextColor(GetThingColor(m));
            std::cout << m;
		}
        std::cout << std::endl;
	}

	for (int i = 0; i < map.GetSize(); i++) {

		for (int j = 0; j < map.GetSize(); j++) {

			int val = map.GetValue(i, j);
            std::string val_str = std::to_string(val);
			if (val_str == "0") val_str = " ";

			if (val_str.length() < 4) {

				int l = val_str.length();
				for (int k = 0; k < 4 - l; k++) {
					val_str = " " + val_str;
				}
			}
			TextColor(GetValColor(val));
			GoToYX(i * 2 + 1 + 1, j * 7 + 1 + 1);
            std::cout << val_str;
		}
	}
	TextColor(7);
}
