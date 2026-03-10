#include <iostream>
#include "Canvas.h"

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				matrix[j][i] = ch;
			}
		}
	}
}
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;

	matrix = new char* [height];
	for (int i = 0; i < height; i++)
	{
		matrix[i] = new char[width];

		for (int j = 0; j < width; j++)
		{
			matrix[i][j] = ' ';

		}





	}


}
void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		matrix[y][x] = ch;
	}
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;
	while (true)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;
		int err2 = err * 2;
		if (err2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}
void Canvas::Print()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
}
void Canvas::Clear()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			matrix[i][j] = ' ';
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; ++i)
	{
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
	for (int j = top; j <= bottom; ++j)
	{
		SetPoint(left, j, ch);
		SetPoint(right, j, ch);
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; ++i)
	{
		for (int j = top; j <= bottom; ++j)
		{
			SetPoint(i, j, ch);
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				matrix[j][i] = ch;
			}
		}
	}
}