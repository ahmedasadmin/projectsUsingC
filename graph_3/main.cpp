#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <windows.h>
//using namespace std;

int main()
{
    /*int gd = DETECT;
    int gm;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    /*

    calculator in graphic mode.gh

    *
     char a[100];
     double number_1, number_2, ans;
     std::string op;

     outtextxy(10, 10, "Enter the 1ere and 2eme number for the operation");
     std::cin>>number_1 ; std:: cin >> op; std::cin >> number_2;

     if      (op == "+") ans = number_1 + number_2;
     else if (op == "-") ans = number_1 - number_2;
     else if (op == "*") ans = number_1 * number_2;
     else if (op == "/") ans = number_1 / number_2;


     settextstyle(8, HORIZ_DIR, 5);
     sprintf(a, "%.2f %s %.2f = %.2f", number_1, op.c_str(), number_2, ans);

     int midx = getmaxx()/2;
     int midy = getmaxy()/2;
     int width = textwidth(a);
     int height = textheight(a);

    outtextxy(midx-width/2, midy-height/2, a);
       getch();
    closegraph();
    int win1 = initwindow(700, 600, "graphics with C++ ",10, 10, false, false);
      int win2 = initwindow(500, 500, "graphic for fun and learn purpose", 30, 20, false, true);

      setcurrentwindow(win1);
      setcolor(YELLOW);
      circle(350, 300, 50);
      setcurrentwindow(win2);
      setcolor(GREEN);
      bar3d(110, 50, 200, 200, 75, 1);

*
        DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
        DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);


        initwindow(screenWidth, screenWidth, "", -3, -3);

        POINT cursorPosition;


        while(true){
                 GetCursorPos(&cursorPosition);
            circle(cursorPosition.x, cursorPosition.y, 100);
            delay(10);
        }
        initwindow(1600, 900, "", -3, -3);
            int barX = 200;
            int page = 0;
            while(1){
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();
                bar(barX++, 200, barX+300, 500);
                bar(barX, 600, barX+300, 700);
                page = 1 - page;
                delay(5);
            }
*    //-------------------building awesome animation with car-------------------------------------
        DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
        DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
        POINT cursorPosition;
        int mX, mY;
        initwindow(screenWidth, screenWidth, "", -3, -3);

        while(true){
            GetCursorPos(&cursorPosition);
            mX = cursorPosition.x;
            mY = cursorPosition.y;
                    if(GetAsyncKeyState(VK_LBUTTON)) bar(mX, mY, mX+200, mY+200);
        }
*

        DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
        DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
        initwindow(screenWidth, screenWidth, "", -3, -3);

        int rectPosX = 100, cir1PosX = 200, cir2PosX = 500, speed = 2;
 while(1){
        // buid car using rectangle and two circle
        setcolor(RED);
       for (int i=0; i<=19; i++) rectangle(rectPosX-i, 300-i, rectPosX+500+i, 511+i);

        setcolor(BLUE);
        for (int i=50; i<=69; i++){
        circle(cir1PosX, 600, i);
        circle(cir2PosX, 600, i);
        }
        setcolor(GREEN);
       for (int i = 670; i<= 689; i++) line(0, i, screenWidth, i);

            if(GetAsyncKeyState(VK_LEFT)){
            rectPosX -= speed;
            cir1PosX -= speed;
            cir2PosX -= speed;
            delay(10);
            cleardevice();
       }   // end if left key
       if(GetAsyncKeyState(VK_RIGHT)){
            rectPosX += speed;
            cir1PosX += speed;
            cir2PosX += speed;
            delay(10);
            cleardevice();
             }


       } // end of infinite w__loop
*/

             //-------------------building awesome animation with car-------------------------------------


        DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
        DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
        initwindow(screenWidth, screenWidth, "", -3, -3);

        int rectPosX = 100, cir1PosX = 200, cir2PosX = 500, speed = 10;
        int page = 0;
 while(1){
        // buid car using rectangle and two circle
        setactivepage(page);
        setvisualpage(1-page);

            cleardevice();

        setcolor(RED);
       for (int i=0; i<=19; i++) rectangle(rectPosX-i, 300-i, rectPosX+500+i, 511+i);

        setcolor(BLUE);
        for (int i=50; i<=69; i++){
        circle(cir1PosX, 600, i);
        circle(cir2PosX, 600, i);
        }
        setcolor(GREEN);
       for (int i = 670; i<= 689; i++) line(0, i, screenWidth, i);

            if(GetAsyncKeyState(VK_LEFT)){
            rectPosX -= speed;
            cir1PosX -= speed;
            cir2PosX -= speed;

       }   // end if left key
       if(GetAsyncKeyState(VK_RIGHT)){
            rectPosX += speed;
            cir1PosX += speed;
            cir2PosX += speed;
             }
             page = 1 - page;

       } // end of infinite w__loop
          getch();
    closegraph();


    return 0;
}
