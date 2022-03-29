//Coded by Sud0ck3rs
#include "system.hpp"  //using my library
#include <windows.h>
#include <iostream>
#include <thread>
#include <termcolor.hpp>
#include <conio.h>

#define TOUCH_ESC 27

using namespace std;
using namespace OS;
using namespace subprocess;


void cancel(bool &running)
{
    bool start = true;
    while(start)
    {
        int ascii = getch();
        if(ascii == TOUCH_ESC)
        {
            running = false;
            start = false;
            system("type null > ./exit.txt");
        }
    }
}


int main()
{
    ShowWindow(GetConsoleWindow(), false);
    bool running = true;
    System sys;
    thread exit(cancel, ref(running));

    while(running)
        cout << termcolor::red << "Position Cursor: " << termcolor::yellow << 
        sys.get_Cursor_Position() << termcolor::reset << endl;
    
    exit.join();

    return EXIT_SUCCESS;
}