#include <iostream>
#include <graphics.h>
using namespace std;

int main(){
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "c:\\TC\\BGI");

/*
    // ** arc **
    arc(200, 200, 0, 360, 100 );
    arc(150, 150, 0, 360, 10 );
    arc(250, 150, 0, 360, 10 );
    arc(200, 200, 0, 360, 5 );
    arc(200, 200, 180, 360, 50 );

*
    bar(200, 200, 400, 300);
    bar(400, 250, 450, 300);
    bar(150, 250, 200, 300);
    arc(200, 320, 0, 360, 20);
    arc(400, 320, 0, 360, 20);

*
    line(0, 0, 400, 400);
    circle(200, 200, 40);
    outtextxy(400, 100, "Lunar Orbit Shape");
     getch();
     cleardevice();
*
    setcolor(GREEN);
    rectangle(200, 200, 400, 300);
   setcolor(YELLOW);
    circle(100, 100, 50);
*
   int x =  getmaxx();

   int y = getmaxy();

   cout << x << endl;
   cout << y << endl;

*/
    int maxx = getmaxx();
    //ROAD
    while(1){
    for (int i=0, color=1; i<maxx; i++, color ++){
    setcolor(DARKGRAY);
    line(0, 370, maxx, 370);
    //SUN
    setcolor(YELLOW);
    circle(80+i, 80, 50);
    //SIGN
    setcolor(WHITE);
    rectangle(520, 250, 535, 370);
    rectangle(480, 200, 580, 250);
    setcolor(color);
    outtextxy(490, 220, "ahmed");


    //BUS
    if(i <= 300){
    setcolor(RED);
    rectangle(100+i, 300, 200+i, 350);
    setcolor(GREEN);
    circle(120+i, 360, 10);
    circle(180+i, 360, 10);
    }else{
    setcolor(RED);
    rectangle(400, 300, 500, 350);
    setcolor(GREEN);
    circle(420, 360, 10);
    circle(480, 360, 10);
    }
    // FLYING BUS
     setcolor(RED);
     rectangle(0+i*5, 50, 50+i*5, 60);

     setcolor(GREEN);
     rectangle(100+i*5, 70, 150+i*5, 80);

     setcolor(CYAN);
     rectangle(200+i*5, 30, 250+i*5, 40);

     setcolor(GREEN);
     rectangle(-400+i*5, 30, -350+i*5, 40);

    setcolor(RED);
    rectangle(-1000+i*5, 70, -950+i*5, 80);

    // PLANE

    setcolor(WHITE);

    //FRONT
    line(450-i, 100, 500-i, 100);
    line(450-i, 100, 440-i, 105);
    line(450-i, 110, 500-i, 110);
    line(450-i, 110, 440-i, 105);

    // TOP FRONT WING
    line(500-i, 100, 520-i, 30);
    line(520-i, 30, 520-i, 100);

    // BOTTOM FRONT WING
    line(500-i, 110, 520-i, 180);
    line(520-i, 180, 520-i, 110);


    // REAR ARAE
    line(520-i, 100, 570-i, 100);
    line(520-i, 110, 570-i, 110);

    //TOP RAER WING
    line(570-i, 100, 580-i, 70);
    line(580-i, 70, 580-i, 100);

    //BOTTOM RAER WING
    line(570-i, 110, 580-i, 140);
    line(580-i, 140, 580-i, 110);

    //LAST ARAE
    line(580-i, 100, 585-i, 100);
    line(580-i, 110, 585-i, 110);
    line(585-i, 110, 585-i, 100);
    if(i==0){
        setcolor(WHITE);
        outtextxy(200, 400, "Press any key to start animation.!");
        getch();
    } // END IF
    //if(color > 15) color = 1;
 delay(20);
    cleardevice();


    } // END FOR
    }// END WHILE
    getch();
    closegraph();


} // end main

