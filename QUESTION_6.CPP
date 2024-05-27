// CODED BY SUBHU

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

class polygon
{
private:
    int i;           // iterater
    int X, Y;        // center of the polygon
    int n;           // size of the polygon
    int Tx, Ty, deg; // sotre all the veritices of the polygon
    int poly[10][2];
    float Sx, Sy;

public:
    // function take take all the deatial of the polygon  the display the polygon
    polygon();
    void translate();
    void scale();
    void rotate();
    void display();
};

void main()
{

    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c://turboc3//bgi");
    polygon *p = new polygon();
    cout << " Enter  1 ----> Translate  2 ----> Scale    3 ----> Rotate   ";
    int task;
    cin >> task;
    if (task == 1)
        p->translate();
    else if (task == 2)
        p->scale();
    else
        p->rotate();
    getch();
    closegraph();
}

// allcate memeory for the polygon class  object
polygon::polygon()
{
    cout << " Enter the center of polygon : ";
    cin >> X >> Y;

    cout << " Ente  number of vertices in the polygon : ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << " Enter  V" << i + 1 << " :";
        cin >> poly[i][0] >> poly[i][1];
    }

    display();
}

//    function to perform  tanslation
//  function to perform tansalation
void polygon::translate()
{
    cout << " Enter Tx and Ty :";
    cin >> Tx >> Ty;
    for (int i = 0; i < n; i++)
    {
        poly[i][0] += Tx;
        poly[i][1] += Ty;
    }
    display();
}
//    function to perform scaling
void polygon::scale()
{
    cout << " Enter the scalling factor  Sx and Sy: ";
    cin >> Sx >> Sy;
    for (i = 0; i < n; i++)
    {
        poly[i][0] = (int)(poly[i][0] * Sx);
        poly[i][1] = (int)(poly[i][1] * Sy);
    }
    display();
}

// function to perform rotation
void polygon::rotate()
{
    cout << " Enter  angle  in degree : ";
    cin >> deg;
    float PI = 3.1415;
    float v = PI / 180;
    float sing = sin(deg * v);
    float cosi = cos(deg * v);
    for (i = 0; i < n; i++)
    {
        int x = poly[i][0];
        int y = poly[i][1];
        poly[i][0] = x * cosi - y * sing;
        poly[i][1] = y * cosi + x * sing;
    }
    display();
}

// function displya the polygon ;
void polygon::display()
{
    clrscr();
    for (i = 0; i < n; i++)
    {
        int k = (i + 1) % n;
        line(X + poly[i][0], Y + poly[i][1], X + poly[k][0], Y + poly[k][1]);
    }
}