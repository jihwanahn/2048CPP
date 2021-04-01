#pragma once


class Map;

class Drawer
{
	void GoToYX(int y, int x);
	void TextColor(int color);

	int GetThingColor(char c);
	char MapThing(int y, int x, int maxY, int maxX);
	int GetValColor(int val = 4096);
	void PrintScore(int score, int size);
	void Draw(Map& map);

};

