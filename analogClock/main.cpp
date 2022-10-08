#include <graphics.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[])
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    // Time related variable
    int coordsForHourx[12] = {50, 86, 100, 87, 50, 0, -50, -87, -100, -87, -50, 0};
    int coordsForHoury[12] = {-87, -50, 0, 50, 87, 100, 87, 50, 0, -50, -87, -100};

    int coordsForMinSecx[60] = {0, 18, 35, 53, 69, 85, 100, 114, 126, 138,
                                147, 155, 162, 166, 169, 170, 169, 166, 162, 155,
                                147, 138, 126, 114, 100, 85, 69, 53, 35, 10,
                                0, -18, -35, -53, -69, -85, -100, -114 , -126, -138,
                                -147, -155, -162, -166, -169, -170, -169, -166, -162, -155,
                                -147, -138, -126, -114, -100, -85, -69, -53, -35, -18};

   int coodsForMinSecy[60] =  {-170, -196, -166, -162, -155, -147, -138, -126, -114, -100,
                                -85, -69, -53, -35, -18, 0, 18, 35, 53, 69,
                                85, 100, 114, 126, 138, 147, 155, 162, 166, 169,
                                170, 169, 166, 162, 155, 147, 138, 126, 114, 100,
                                85, 69, 53, 35, 18, 0, -18, -35, -53, -69,
                                -85, -100, -114, -126, -138, -147, -155, -162, -166, -169};


    time_t rawTime;
    char a[100];
    struct tm *currentTime;

    // To get mid point of graph
    int midx = getmaxx()/2;
    int midy = getmaxy()/2;
while(1){
    // Variable for storing hours, minutes, seconds info
    int IMS;
// Time related to function
    rawTime = time(NULL);
    currentTime = localtime(&rawTime);
    setcolor(WHITE);

    // Drawing the circle ....
    circle(midx, midy, 200);
    outtextxy(midx+95, midy-165, "1");
    outtextxy(midx+165, midy-95, "2");
    outtextxy(midx+190, midy+0, "3");
    outtextxy(midx+165, midy+95, "4");
    outtextxy(midx+95, midy+165, "5");
    outtextxy(midx-0, midy+190, "6");
    outtextxy(midx-95, midy+165, "7");
    outtextxy(midx-165, midy+95, "8");
    outtextxy(midx-190, midy-0, "9");
    outtextxy(midx-165, midy-95, "10");
    outtextxy(midx-95, midy-165, "11");
    outtextxy(midx-0, midy-190, "12");



    strftime(a, 100,"%I",currentTime);
    sscanf(a, "%d", &IMS);
    setcolor(RED);
    line(midx, midy, midx + coordsForHourx[IMS-1], midy+coordsForHoury[IMS-1]);


    strftime(a, 100, "%M", currentTime);
    sscanf(a, "%d", &IMS);
    setcolor(YELLOW);
    line(midx, midy, midx+coordsForMinSecx[IMS], midy+coodsForMinSecy[IMS]);


    strftime(a, 100, "%S", currentTime);
    sscanf(a, "%d", &IMS);
    setcolor(GREEN);
    line(midx, midy, midx+coordsForMinSecx[IMS], midy+coodsForMinSecy[IMS]);
delay(1000);
cleardevice();
    }
    getch();
    closegraph();

    return 0;
}
