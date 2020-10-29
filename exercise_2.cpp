#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ac_int.h"

const int W = 10;

void csd_encode(ac_int<W,true> &num, ac_int<W,false> &x_p, ac_int<W,false> &x_m){
  
  int i = 0;
  int carry = 0;
  
  while(i<W-1){
    
    if(carry==0){
      if(num[i] == 0 && num[i+1] == 0){
        x_p[i] = 0;
	x_m[i] = 0;
	carry  = 0; 
      }else if(num[i+1] == 1 && num[i] == 0){
        x_p[i] = 0;
	x_m[i] = 0;
	carry  = 0;
      }else if(num[i+1] == 0 && num[i] == 1){
        x_p[i] = 1;
	x_m[i] = 0;
	carry  = 0;
      }else if(num[i+1] == 1 && num[i] == 1){
        x_p[i] = 0;
	x_m[i] = 1;
	carry  = 1;
      }  
    }else{
      if(num[i+1] == 0 && num[i] == 1){
        x_p[i] = 0;
	x_m[i] = 0;
	carry  = 1;
      }else if(num[i+1] == 1 && num[i] == 1){
	x_p[i] = 0;
	x_m[i] = 0;
	carry  = 1;
      }else if(num[i+1] == 0 && num[i] == 0){
        x_p[i] = 1;
	x_m[i] = 0;
	carry  = 0;
      }else if(num[i+1] == 1 && num[i] == 0){
        x_p[i] = 0;
	x_m[i] = 1;
	carry  = 1;
      }

    }

    i++;
  }
   
}


int main(){

  ac_int<W,true> a = 29;
  ac_int<W,false> x,c;

  csd_encode(a,x,c);

  std::cout<< "a:" << a <<",x:" << x << ",c:" << c << std::endl;
  return 0;
}

