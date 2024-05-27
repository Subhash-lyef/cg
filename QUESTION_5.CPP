#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void display(int poly[][2], int n);
void fillpolygon(int poly[][2], int n, int color);
int x_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int num = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
    int den = (y2 - y1) * (x3 - x4);
    return num / den;
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c://turboc3//bgi");

    int n = 7;                                                                                           // size of the polygon ;
    int polygon[][2] = {{60, 70}, {200, 10}, {200, 200}, {600, 300}, {400, 440}, {100, 300}, {60, 200}}; // all the cordinate of the polygon

    display(polygon, n);
    int color = 5;
    fillpolygon(polygon, n, color);

    getch();
    closegraph();
}
void fillpolygon(int poly[][2], int n, int color)
{
    int i;
    // 1 find out the max-Y and Min-Y
    int maxY = 0, minY = 480, x, y;
    for (i = 0; i < n; i++)
    {
        if (minY > poly[i][1])
            minY = poly[i][1];
        if (maxY < poly[i][1])
            maxY = poly[i][1];
    }
    // 2 Start scaning from min-Y to max-Y
    for (y = minY; y <= maxY; y++)
    {
        int intersect[20]; /// Array that store theintersection point
        int m = 0;         /// number of intersection point

        // finding all the intersection point withe at y
        for (int i = 0; i < n; i++)
        {
            int k = (i + 1) % n;
            // Check if the scan line is within the edge
            if (poly[i][1] <= y && poly[k][1] > y || poly[k][1] <= y && poly[i][1] > y)
            {
                intersect[m++] = x_intersect(poly[i][0], poly[i][1], poly[k][0], poly[k][1], 0, y, 640, y);
            }
        }

        // now sort the intersection point
        for (i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1 - i; j++)
                if (intersect[j] > intersect[j + 1])
                {
                    int temp = intersect[j];
                    intersect[j] = intersect[j + 1];
                    intersect[j + 1] = temp;
                }
        //	for(i = 0; i < m; i++)
        //	   cout <<  intersect[i] << "   ";

        // fill the pixel between pair of the intersectin

        for (i = 0; i < m; i += 2)
        {
            if (intersect[i] != intersect[i + 1])
            {
                for (x = intersect[i] + 1; x < intersect[i + 1]; x++)
                {
                    putpixel(x, y, color);
                }
            }
        }
    }
}

void display(int poly[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = (i + 1) % n;
        line(poly[i][0], poly[i][1], poly[k][0], poly[k][1]);
    }
}