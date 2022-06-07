//coded by Sud0ck3rs
#include <iostream>
#include <termcolor.hpp>


using namespace std;

int main(int argc, char **argv)
{
  if(argc >= 2)
  {
    string str_Params = argv[1];
    cout << termcolor::green << "Character number: " << termcolor::yellow << str_Params.size()
    << termcolor::reset << endl;
  }
  else
    cout << termcolor::magenta << termcolor::bold << "Usage: StrLen <character string>" 
    << termcolor::reset << endl;

  return EXIT_SUCCESS;
}