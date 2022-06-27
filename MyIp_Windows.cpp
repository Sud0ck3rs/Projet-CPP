//coded by Sud0ck3rs
#include <SFML/Network.hpp>  //include library SFML
#include <iostream>
#include <termcolor.hpp>

using namespace std;
using namespace sf;


int main()
{
  IpAddress IP_Local;
  IpAddress IP_Public;

  cout << termcolor::red << "------------------------------------" << termcolor::reset << endl;
  cout << termcolor::green << "IP Local: " << termcolor::yellow << IP_Local.getLocalAddress() 
  << termcolor::reset << endl;

  cout << termcolor::green << "IP Public: " << termcolor::yellow << IP_Public.getPublicAddress()
  << termcolor::reset << endl;
  cout << termcolor::red << "------------------------------------" << termcolor::reset << endl;

  return EXIT_SUCCESS;
}
