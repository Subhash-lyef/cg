// coded by subhu

// sutherland hodgeman polygon clipping program
#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#define N = 20;
int suthhodgclip(int polygon[][2], int, int window[][2]);
void display(int polygon[][2], int);

int x_intersect(int, int, int, int, int, int, int, int);
int y_intersect(int, int, int, int, int, int, int, int);

void main()
{
    clrscr();

    int g = DETECT, m;
    initgraph(&g, &m, "c://turboc3//bgi");
    int window[][2] = {{80, 60}, {80, 420}, {560, 420}, {560, 60}};
    display(window, 4);
    int n = 7;                                                                                           // size of the polygon ;
    int polygon[][2] = {{60, 70}, {200, 10}, {200, 200}, {600, 300}, {400, 440}, {100, 300}, {60, 200}}; // all the cordinate of the polygon

    //	display(polygon, n);
    n = suthhodgclip(polygon, n, window);

    setcolor(YELLOW);
    display(polygon, n);
    getch();
}

int suthhodgclip(int polygon[][2], int n, int window[][2])
{
    for (int i = 0; i < 4; i++)
    {

        int j = (i + 1) % 4;
        int wx1 = window[i][0];
        int wy1 = window[i][1];
        int wx2 = window[j][0];
        int wy2 = window[j][1];
        int newpoly[20][2];
        int size = 0;
        for (int k = 0; k < n; k++)
        {
            int m = (k + 1) % n;

            int x1 = polygon[k][0];
            int y1 = polygon[k][1];
            int x2 = polygon[m][0];
            int y2 = polygon[m][1];

            // Calculating position of first point

            int kpos = (wx2 - wx1) * (y1 - wy1) - (wy2 - wy1) * (x1 - wx1);

            // Calculating position of second point

            int mpos = (wx2 - wx1) * (y2 - wy1) - (wy2 - wy1) * (x2 - wx1);

            // both point are inside
            if (kpos < 0 && mpos < 0)
            { //  only second point is added

                newpoly[size][0] = x2;
                newpoly[size][1] = y2;
                size++;
            }
            // first point is outside and second is inside
            else if (kpos >= 0 && mpos < 0)
            { // point of the intersection with widow edge and second point is added;

                newpoly[size][0] = x_intersect(wx1, wy1, wx2, wy2, x1, y1, x2, y2);
                newpoly[size][1] = y_intersect(wx1, wy1, wx2, wy2, x1, y1, x2, y2);
                size++;

                newpoly[size][0] = x2;
                newpoly[size][1] = y2;

                size++;
            }
            // first point is inside and the second point is outside
            else if (kpos < 0 && mpos >= 0)
            { //    only point of intesection is added

                newpoly[size][0] = x_intersect(wx1, wy1, wx2, wy2, x1, y1, x2, y2);
                newpoly[size][1] = y_intersect(wx1, wy1, wx2, wy2, x1, y1, x2, y2);
                size++;
            }
            // when both the point are outside .........nothing to do

            // copying new obtain poiint into original array
            // and changinh the size of the polygon
        }

        for (int p = 0; p < size; p++)
        {
            polygon[p][0] = newpoly[p][0];
            polygon[p][1] = newpoly[p][1];
        }
        n = size;
    }
    return n;
}

int x_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int num = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
    int den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    return num / den;
}
int y_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int num = (x1 * y2 - y1 * x2) * (y3 - y4) - (x3 * y4 - y3 * x4) * (y1 - y2);
    int den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    return num / den;
}

// unction take all the vertices of the polygon and size of the polygon , then display into bgi
void display(int polygon[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = (i + 1) % n;
        line(polygon[i][0], polygon[i][1], polygon[k][0], polygon[k][1]);
    }
}
