//coded by Sud0ck3rs
#include <SFML/Network.hpp>  //include library SFML
#include <termcolor.hpp>
#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>

using namespace std;
using namespace sf;



string shell(const string &cmd){
  FILE *fpipe;
  char c = 0;
  string std_output = "";

  if (0 == (fpipe = (FILE*)popen(cmd.c_str(), "r")))
    return {};
  else
  {
    while (fread(&c, sizeof c, 1, fpipe))
    {
      std_output += c;
    }
    pclose(fpipe);
    return std_output;
  }
}


bool interface_Exist(const string &interface) {
    string output_link = shell("ip link show");
    if(output_link.find(interface) != string::npos)
      return true;
    else
      return false;
}


string HostToIP(const string &host) {
  hostent* hostname = gethostbyname(host.c_str());
  if(hostname)
    return std::string(inet_ntoa(**(in_addr**)hostname->h_addr_list));
  return {};
}


string get_IP_Interface(const string &interface){
  int fd;
  struct ifreq ifr;

  fd = socket(AF_INET, SOCK_DGRAM, 0);
  ifr.ifr_addr.sa_family = AF_INET;

  strncpy(ifr.ifr_name, interface.c_str(), IFNAMSIZ-1);
  ioctl(fd, SIOCGIFADDR, &ifr);
  close(fd);
  string ip_address = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
  return ip_address;
}


int main()
{
  IpAddress IP_Local;
  IpAddress IP_Public;
  string host_Portmap = "Sud0ck3rs-31536.portmap.io";
  string port_Forward = "31536 => 1234";

  cout << termcolor::red << "--------------------------------------------------------------" << termcolor::reset << endl;
  cout << termcolor::green << "IP Local: " << termcolor::yellow << IP_Local.getLocalAddress() 
  << termcolor::reset << endl;
  
  cout << termcolor::green << "IP Public: " << termcolor::yellow << IP_Public.getPublicAddress()
  << termcolor::reset << endl;

  if(interface_Exist("tun0"))
    cout << termcolor::green << "IP OpenVPN: " << termcolor::yellow << get_IP_Interface("tun0")
    << termcolor::reset << endl;
  
  cout << termcolor::green << "IP Portmap.io: " << termcolor::yellow << HostToIP(host_Portmap)
  << termcolor::green << " Open Port Forward: " << termcolor::yellow  << port_Forward << termcolor::reset << endl;
  cout << termcolor::red << "--------------------------------------------------------------" << termcolor::reset << endl;

  return EXIT_SUCCESS;
}
