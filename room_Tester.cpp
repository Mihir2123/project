#include <iostream>
#include <string>
#include "room.h"

int Room::roomid=0;
int main(){
     Room *m=new Room(1, 100, 1);

     if(m->returnprice()!=100){
         std::cout<<"test Failed"<<std::endl;
     }else{
          cout<<"pass1"<<endl;
     }

     if (m->returnroomtype()!=1){
          std::cout<<"test Failed"<<std::endl;
     }else{
          cout<<"pass2"<<endl;
     }
     if (m->returnstatus()!=1){
          std::cout<<"test Failed"<<std::endl;
     }else{
          cout<<"pass3"<<endl;
     }
       
     if (m->returnnoRoom()!=1){
          std::cout<<"test Failed"<<std::endl;
     }else{
          cout<<"pass4"<<endl;
     }

}