#include <iostream>
#include "ac_int.h"
#include "ac_fixed.h"
#include <stdlib.h>
#include <time.h>

int main(){

  srand (time(NULL));

  //a
  ac_int<8,false> a=43 ,b=142;
  ac_int<9,true> c=-152, d=73;  
  ac_int<18,true> e = a*b + c*d;

  //b
  ac_fixed<5,2,false> f=2.25;
  ac_fixed<5,4,true> g=-6.5;
  ac_fixed<10,6,true> h = f*g;

  std::cout << "INT:" << e << std::endl;
  std::cout << "Float:" << h << std::endl;

  return 0;

}


