  // cohen sutherland line clipping algorithm

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
int xmin = 80;
int ymin = 60;
int xmax = 560;
int ymax = 420;
int udlr(int, int);
int lineclip(int, int, int, int);
void main()
{
  clrscr();
  int g = DETECT, m;
  initgraph(&g, &m, "C://turboc3//bgi");
  rectangle(80, 60, 560, 420);

  int X0, Y0, X1, Y1;
     cout << " Enter the coordinate : X0 : Y0 :  X1 : Y1 : = ";
      cin >> X0 >> Y0 >> X1 >> Y1;
     line(X0, Y0, X1, Y1);

  setcolor(RED);
   lineclip(X0, Y0, X1, Y1);

  getch();
  closegraph();
}

int lineclip(int x, int y, int X, int Y)
{
  int p = udlr(x, y);
  int q = udlr(X, Y);
  // case 1  line is completly visible
  if (p == 0 && q == 0)
  {
    line(x, y, X, Y);
    return 0;
  }
  // case 2  line is completly invisible
  if (p & q)
    return 0;

  // case 3 line is partially visible

  // Atlest one end point of the line is outside the window

  float m = (Y - y) / ((X - x) * 1.0); // slope of the line

  // xc = x + ( ym - y) / m; where ym is ymin or ymax
  // yc = y + ( xm - x ) * m; where xm is xmin or xmax
  if (p)
  {
    if (p & 8)
    {
      x = x + (ymax - y) / m;
      y = ymax;
    }
    else if (p & 4)
    {
      x = x + (ymin - y) / m;
      y = ymin;
    }
    else if (p & 1)
    {
      y = y + m * (xmax - x);
      x = xmax;
    }
    else if (p & 2)
    {
      y = y + m * (xmin - x);
      x = xmin;
    }
  }
  if (q)
  {
    if (q & 8)
    {
      X = x + (ymax - y) / m;
      Y = ymax;
    }
    else if (q & 4)
    {
      X = x + (ymin - y) / m;
      Y = ymin;
    }
    else if (q & 1)
    {
      Y = y + m * (xmax - x);
      X = xmax;
    }
    else if (q & 2)
    {
      Y = y + m * (xmin - x);
      X = xmin;
    }
  }

  line(x, y, X, Y);
  return 0;
  // now  we move outside point to the intersection point
}

int udlr(int x, int y)
{
  int r = 0;
  if (x < xmin)
    r += 2;
  if (x > xmax)
    r += 1;
  if (y < ymin)
    r += 4;
  if (y > ymax)
    r += 8;
  return r;
}