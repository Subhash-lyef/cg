
// sutherland hodgeman polygon clipping program
#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#define N = 20;
long suthhodgclip(long polygon[][2], long, long window[][2]);
void display(long polygon[][2], long);

long x_longersect(long, long, long, long, long, long, long, long);
long y_longersect(long, long, long, long, long, long, long, long);

void main()
{
	clrscr();

	int g = DETECT, m;
	initgraph(&g, &m, "c://turboc3//bgi");
	long window[][2] = {{80, 60}, {80, 420}, {560, 420}, {560, 60}};
	display(window, 4);
	long n = 7;																				  // size of the polygon ;
	long polygon[][2] = {{60, 70}, {200, 10}, {200, 200}, {600, 300},{400,440}, {100, 300}, {60, 200}}; // all the cordinate of the polygon
																							  // 		cout << " before cliping" << endl;
																							  // 	 for (int i = 0; i < n; i++)
																							  //   {
																							  // 	  long k = (i + 1) % n;
																							  // 	  cout << polygon[i][0] << " " << polygon[i][1] << " -----" << polygon[k][0] << "  " << polygon[k][1] << endl;
																							  // 	 }																			   /*    cout << " Before clipping" << endl;
      //	for (long i = 0; i < n; i++)
      //	{
       //		long k = (i + 1) % n;
	//	cout << polygon[i][0] << " " << polygon[i][1] << " -----" << polygon[k][0] << "  " << polygon[k][1] << endl;
     //	}

	     //	display(polygon, n);
	n = suthhodgclip(polygon, n, window);
	// 	cout << " After cliping" << endl;
	// 	 for (i = 0; i < n; i++)
	//   {
	// 	  long k = (i + 1) % n;
	// 	  cout << polygon[i][0] << " " << polygon[i][1] << " -----" << polygon[k][0] << "  " << polygon[k][1] << endl;
	// 	 }
	// 	cout << " n = " << n<<endl;
	setcolor(YELLOW);
	display(polygon, n);
	getch();
}

long suthhodgclip(long polygon[][2], long n, long window[][2])
{
	for (long i = 0; i < 4; i++)
	{

		long j = (i + 1) % 4;
		long wx1 = window[i][0];
		long wy1 = window[i][1];
		long wx2 = window[j][0];
		long wy2 = window[j][1];
		long newpoly[20][2];
		long size = 0;
		for (long k = 0; k < n; k++)
		{
			long m = (k + 1) % n;

			long x1 = polygon[k][0];
			long y1 = polygon[k][1];
			long x2 = polygon[m][0];
			long y2 = polygon[m][1];

			// Calculating position of first polong

			long kpos = (wx2 - wx1) * (y1 - wy1) - (wy2 - wy1) * (x1 - wx1);

			// Calculating position of second polong

			long mpos = (wx2 - wx1) * (y2 - wy1) - (wy2 - wy1) * (x2 - wx1);

			// both polong are inside
			if (kpos < 0 && mpos < 0)
			{	//  only second polong is added
				// cout << " inside inside " <<endl ;
				newpoly[size][0] = x2;
				newpoly[size][1] = y2;
				size++;
			}
			// first polong is outside and second is inside
			else if (kpos >= 0 && mpos < 0)
			{ // polong of the longersection with widow edge and second polong is added;
				// cout << " outside inside " <<endl ;
				newpoly[size][0] = x_longersect(wx1, wy1, wx2, wy2, x1, y1, x2, y2);
				newpoly[size][1] = y_longersect(wx1, wy1, wx2, wy2, x1, y1, x2, y2);
				size++;

				newpoly[size][0] = x2;
				newpoly[size][1] = y2;

				size++;
			}
			// first polong is inside and the second polong is outside
			else if (kpos < 0 && mpos >= 0)
			{ //    only polong of longesection is added
				//    cout << " inside outside " <<endl ;
				newpoly[size][0] = x_longersect(wx1, wy1, wx2, wy2, x1, y1, x2, y2);
				newpoly[size][1] = y_longersect(wx1, wy1, wx2, wy2, x1, y1, x2, y2);
				size++;
			}
			// when both the polong are outside .........nothing to do

			// copying new obtain poilong longo original array
			// and changinh the size of the polygon
		}

		for (long p = 0; p < size; p++)
		{
			polygon[p][0] = newpoly[p][0];
			polygon[p][1] = newpoly[p][1];
		}
		n = size;
	}
	return n;
}

long x_longersect(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4)
{
	long num = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	long den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	return num / den;
}
long y_longersect(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4)
{
	long num = (x1 * y2 - y1 * x2) * (y3 - y4) - (x3 * y4 - y3 * x4) * (y1 - y2);
	long den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	return num / den;
}

// unction take all the vertices of the polygon and size of the polygon , then display longo bgi
void display(long polygon[][2], long n)
{
	for (long i = 0; i < n; i++)
	{
		long k = (i + 1) % n;
		line(polygon[i][0], polygon[i][1], polygon[k][0], polygon[k][1]);
	}
}
