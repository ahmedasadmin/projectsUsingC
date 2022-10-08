#include <graphics.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int gd = DETECT;
    int gm;

    initgraph(&gd, &gm, "C:\\TC\\BGI");


    std::string input = "";
    int x=10, y=10;
    outtextxy(x, y, "Hello, How can i help you ?");

   // body of code...
    while(1){

    std::getline(std::cin, input);

   if( input  == "How are you?" ||input == "how are you?" || input == "how are you" || input == "how are you " ||
      input == "How r you?" || input == "How r you" || input == "how r you"
       || input == "how r u?" || input == "how re u?" || input == "how re u"
       || input == "how do you do?" || input == "what's up?" ||input == "what's up" ||input == "are you ok?")
        outtextxy(x, y+=30, "i am fine. Thank you.");
    else if(input == "who are you?" || input == "who are you " || input == "who are you?"  || input == "who re you"
            || input == "who re u" || input == "who r u" || input == "who re u " || input == "who re u?" ||
            input == "WHO are yo" || input == "who are you?")

             outtextxy(x, y+=30, "i am u roboie ");
    else if (input == "ex" || input == "exit" || input == "q" || input == "quit" || input == "bye" ||
             input == "bye bye " || input == "see you later" || input == "see you again MR roboie")
                 {outtextxy(x, y+=30, "i am glad to see you and talk. you can shutdown your terminal"); delay(2000); return 1; }
    else{
         outtextxy(x, y+=30, "speak English, plz");
    }

    } // end while loop






    closegraph();

}
