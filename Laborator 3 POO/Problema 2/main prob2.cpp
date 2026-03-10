#include <iostream>
#include "Canvas.h"

int main()
{
	Canvas canvas(50, 40);
	canvas.DrawLine(0, 0, 19, 9, '*');
	canvas.DrawRect(2, 2, 17, 7, '#');
	canvas.FillRect(4, 4, 15, 5, '@');
	canvas.DrawCircle(10, 5, 3, 'o');
	canvas.FillCircle(10, 5, 2, 'x');
	canvas.Print();
	return 0;
}