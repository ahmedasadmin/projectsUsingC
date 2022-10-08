#include <stdio.h>
#include <graphics.h>
#include <string.h>
using namespace std;

int main()
{
     int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "c:\\TC\\BGI");
/*
    // bar3d() function
    bar3d(100, 100, 300, 300, 100, 0);

    outtextxy(0, 20, "Press any key to close graph .");

*


    int points[8]= {100, 100, 200, 200, 100, 200, 100, 100};
    setfillstyle(XHATCH_FILL, RED);
    fillpoly(4, points);
*
   // ellipse(300, 200, 0, 360, 200, 100);
    setfillstyle(XHATCH_FILL, RED);

    fillellipse(400, 200, 40, 80);
*
    char x = 5;
    char arr[20];
    memcpy(arr, &x, 4);
    printf("the value of x is %d", arr[0]);
   // sprintf(arr, "value of x is %d: ", x);
     //outtextxy(200, 200, arr);
*

    bar(20, 20, 200, 30);
    setfillstyle(LINE_FILL, GREEN);
    bar(150, 150, 300, 300);
*
      setfillstyle(SOLID_FILL, BLUE);
      rectangle(100, 100, 300, 300);
      setfillstyle(LINE_FILL, YELLOW);
      floodfill(200, 200, WHITE);
*
      setcolor(YELLOW);
      circle(300, 300, 100);
      setfillstyle(SOLID_FILL, YELLOW);
      floodfill(300, 300, YELLOW);
*


    char text[100];
    int drawingColor = getcolor();

    sprintf(text, "%d", drawingColor);
    outtextxy(100, 100, text);

     setcolor(4);
      drawingColor = getcolor();

    sprintf(text, "%d", drawingColor);
    outtextxy(1, 100, text);
*
    char arr[100];
    struct arccoordstype act;


    arc(200, 200, 0, 180, 150);
    getarccoords(&act);

    sprintf(arr, "Center of arc is x= %d and y= %d",act.x, act.y);

    outtextxy(200, 100, arr);

*
    char arr[100];
    int maxColor = getmaxcolor();
    sprintf(arr, "%d", maxColor);
    outtextxy(10, 10, arr);
*
    int i = 0;
    for (i; i<=11; i++)
  {
       settextstyle(i, HORIZ_DIR, 2);
      outtextxy(0, i*25 , "ahmed MO");
  }
*

    char a[50];
    int counter_down;


    printf("Enter the number of second left: ");
    scanf("%d", &counter_down);

    settextstyle(7, HORIZ_DIR, 5);


    for (int i= counter_down; i>0; i--){

        sprintf(a, "NEW YEAR IN %d seconds ", i);
        outtextxy(0, 210, a);
        delay(1000);     // equal 1 second..
        cleardevice();

    } // end for.

    settextstyle(10, HORIZ_DIR, 6);

    setcolor(6);
    outtextxy(30, 200, "HAPPY NEWYEAR! :-)");


    delay(500);
    setcolor(LIGHTGREEN);
    outtextxy(30, 300, "HAPPY NEWYEAR! :-)");


     delay(500);
     setcolor(LIGHTGREEN);
     outtextxy(30, 100, "HAPPY NEWYEAR! :-)");

I



*/
char c= getchar();
printf("%c\n", c);

 c= getchar();
printf("%c\n", c);

   // getch();
  //  closegraph();

    return 0;
}
