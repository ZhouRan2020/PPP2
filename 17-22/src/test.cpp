#include <iostream>
//#include <stop_token>
//#include <stop_token>
#include "Lines_window.h"
#include "Point.h"
int main(){
    std::cout<<"hello.\n";
    int y=000;
   // in rrrr=9kfs;
 //   std::stop_token st{};
  gl::Point lu{100,100};
  Lines_window lw{lu,800,800,"lw"};
  return gl::gui_main();
}