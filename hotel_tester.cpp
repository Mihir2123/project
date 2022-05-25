#include <iostream>
#include <string>
#include "hotel.h"
int Room::roomid=0;
int main(){
    Hotel *r= new Hotel("Taj","Adelaide");

    if(r->gethoteladdress()!="Adelaide"){
        std::cout<<"Test Failed"<<std::endl;
    }
    else{
        cout<<"pass1"<<endl;
    }

    if(r->gethotelname()!="Taj"){
        std::cout<<"Test Failed"<<std::endl;
    }
    else{
        cout<<"pass2"<<endl;
    }
    
}