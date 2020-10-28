#include <iostream>
#include "ac_int.h"
#include "ac_fixed.h"
#include <stdlib.h>
#include <time.h>

int main(){

  srand (time(NULL));

  
  //a
  ac_int<8,false> a ,b;
  ac_int<9,true> c, d;  
  ac_int<18,true> e ;

  //b
  ac_fixed<5,2,false> f;
  ac_fixed<5,4,true> g;
  ac_fixed<10,6,true> h;
  
  for(int i=0;i<19;i++){
    a = rand() % 255;
    b = rand() % 255;

    c = (rand() % 1023) - 512;
    d = (rand() % 1023) - 512;

    e = a*b+c*d;
    
    std::cout << "a:" << a << ",b:" << b << ",c:" << c << ",d:" << d << std::endl;
    std::cout << "INT:" << e << std::endl;

    std::cout << "******************************" << std::endl; 

    f = 3.875 * ((((float) rand())/ (float)  RAND_MAX));
    g = (7.5 - (-8))*((((float) rand())/(float) RAND_MAX)) + (-8);
    
    h = f*g;
    
    std::cout << "f:" << f << ",g:" << g << std::endl;
    std::cout << "Float:" << h << std::endl;

    std::cout << "******************************" << std::endl;
  }


  return 0;

}


