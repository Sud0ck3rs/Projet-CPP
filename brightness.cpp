#include <iostream>
#include <termcolor.hpp>
#include <conio.h>
#include <sstream>

#define TOUCH_ESC 27
#define TOUCH_ADD 43
#define TOUCH_SUBTRACT 45
#define BRIGHTNESS_MAX 1.3
#define BRIGHTNESS_MIN 0.4

using namespace std;


int main()
{
    string header_Shell = "xrandr --output DP-0 --brightness "; //change output screen
    string command_Shell = "";
    stringstream ss;
    char touch;
    double brightness = 0.5;

    system("clear");
    while(int(touch) != TOUCH_ESC)
    {
        cout << "press" << termcolor::yellow << " + " << termcolor::reset << "or" << termcolor::yellow << " - " << termcolor::reset 
        << "for" << termcolor::yellow << " UP/DOWN " << termcolor::reset << "brightness" << endl;
        cout << "brightness: " << (brightness*100) << "%" << endl;
        touch = getch();
        system("clear");
        if(int(touch) == TOUCH_ADD)
        {
            if(brightness < (BRIGHTNESS_MAX-0.1))
            {
                brightness += 0.1;
                ss << brightness;
                command_Shell = header_Shell + ss.str();
                system(command_Shell.c_str());
            }
        }

        else if(int(touch) == TOUCH_SUBTRACT)
        {
            if(brightness > BRIGHTNESS_MIN)
            {
                brightness -= 0.1;
                ss << brightness;
                command_Shell = header_Shell + ss.str();
                system(command_Shell.c_str());
            }
        }
        command_Shell = "";
        ss.str("");
        ss.clear();
    }

    return EXIT_SUCCESS;
}
