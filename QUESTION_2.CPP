// coded by subhu
#include <graphics.h>
#include <dos.h>
#include <conio.h>
void drawcircle(int, int, int);
void main()
{

	int g = DETECT, m;
	initgraph(&g, &m, "C://turboc3//bgi");
	circle(320, 240, 200);
	drawcircle(320, 240, 200);
	getch();
	closegraph();
}
void drawcircle(int X, int Y, int R)
{
	int x = 0, y = R;
	int p = 1 - R;
	// int p = 3 - 2 *  R;
	setcolor(RED);
	while (x <= y)
	{
		// first quadrant
		putpixel(X + x, Y + y, RED);
		putpixel(X + y, Y + x, RED);
		// second quadrant
		putpixel(X - x, Y + y, RED);
		putpixel(X - y, Y + x, RED);
		// third quadrant
		putpixel(X - x, Y - y, RED);
		putpixel(X - y, Y - x, RED);
		// fourth quadreant
		putpixel(X + x, Y - y, RED);
		putpixel(X + y, Y - x, RED);

		if (p < 0)
		{
			p += 2 * x + 3;
			//  p += 4 * x + 6;
			x++;
		}
		else
		{
			p += 2 * x + 5 - 2 * y;
			// p += 4 * x - 4 * y + 10;
			x++;
			y--;
		}
		delay(100);
	}
}
