// coded by subhu
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
  //   line(X0, Y0, X1, Y1);
  //  line(X0,Y0,X1,Y1);
  setcolor(RED);
  // lineclip(X0, Y0, X1, Y1);
  lineclip(X0, Y0, X1, Y1);
  getch();
  closegraph();
}

int lineclip(int x, int y, int X, int Y)
{
  if (x == X && y == Y)
  {
    putpixel(x, y, RED); // if the line have only one point
    return 0;
  }
  if (x + 1 == X || x == X + 1 || y + 1 == Y || y == Y + 1) // condition to stop infilne recursion

    return 0;

  int p = udlr(x, y);
  int q = udlr(X, Y);
  if (p == 0 && q == 0)
  {
    line(x, y, X, Y);
    return 0;
  }
  if (p & q)
    return 0;

  int xmid = (x + X) / 2;
  int ymid = (y + Y) / 2;

  lineclip(x, y, xmid, ymid);
  lineclip(xmid, ymid, X, Y);
  return 0;
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