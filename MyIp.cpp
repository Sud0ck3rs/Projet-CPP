//coded by Sud0ck3rs
#include <SFML/Network.hpp>  //include library SFML
#include <iostream>

using namespace std;
using namespace sf;


int main()
{
  IpAddress IP_Local;
  IpAddress IP_Public;

  cout << "------------------------------------" << endl;
  cout << "IP Local: " << IP_Local.getLocalAddress() << endl;
  cout << "IP Public: " << IP_Public.getPublicAddress() << endl;
  cout << "------------------------------------" << endl;

  return EXIT_SUCCESS;
}
