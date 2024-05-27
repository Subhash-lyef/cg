// coded by subhu
#include <iostream.h>
#include <graphics.h>

void bresenham(int, int, int, int);
void main()
{

	int g = DETECT, m;
	initgraph(&g, &m, "C://turboc3//bgi");
	int X0, Y0, X1, Y1;
	cout << " Enter the coordinate : X0 , Y0 :";
	cin >> X0 >> Y0;
	cout << " Enter the coordinate : X1 , Y1:";
	cin >> X1 >> Y1;

	bresenham(X0, Y0, X1, Y1);
	closegraph();
}
void bresenham(int x, int y, int X, int Y)
{
	int dx = X - x, dy = Y - y;
	if (dx >= dy)
	{
		int p = 2 * dy - dx;
		while (x <= X)
		{
			putpixel(x++, y, RED);
			if (p > 0)
				y++;
			p += 2 * dy - (p > 0 ? 2 * dx : 0);
		}
	}
	else
	{
		int p = 2 * dx - dy;
		while (y <= Y)
		{
			putpixel(x, y++, RED);
			if (p > 0)
				x++;
			p += 2 * dx - (p > 0 ? 2 * dy : 0);
		}
	}
}
