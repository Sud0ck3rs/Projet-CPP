#include <iostream>
#include <string.h>

using namespace std;


int main()
{
  system("clear");
  cout << "input strings: ";
  string String = "";
  getline(cin, String);
  cout << "number char = " << strlen(String.c_str());
  return EXIT_SUCCESS;
}
