#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "ac_channel.h"
#include "ac_int.h"

void runlength_encode(ac_channel<ac_int<4,false> > &in, ac_channel<ac_int<4,false> > &out){

  int data,new_data,count;
  data=-1; 
  
  if(in.available(10)){
    for(int i=0;i<10;i++){  
      new_data = in.read();

      if(new_data == data){
        count++;
      }else{
        if(data!=-1){    
          out.write(data);
          out.write(count);
        }
        count = 1;
        data = new_data;
      }
        
    } 
  }

}

int main(){
  
  int next_num,data,data_n,count;   
  ac_channel<ac_int<4,false> > data_in;
  ac_channel<ac_int<4,false> > data_out;

  srand(time(NULL));

  for(int i=0;i<10;i++){
    next_num = rand() % 15;
    data_in.write(next_num);
    std::cout<<next_num<<std::endl;     
  }

    
  runlength_encode(data_in,data_out);
  

  do{  
    std::cout << data_out.read() << std::endl;
  }while(data_out.available(1));
  std::cout<< data_out.read() << std::endl;



  return 0;
}
