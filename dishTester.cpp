
#include <iostream>
#include <string>
#include "dish.h"

using namespace std;

int main()
{

Dish *m= new Dish("Rich",200,1);

if(m->getdishprice()!=200){
    std::cout<<"Test Failed"<<std::endl;
    cout<<m->getdishprice()<<endl;
}
    else{
        cout<<"pass1"<<endl;
    }

if(m->getdishname()!="Rich"){
   std::cout<<"Test Failed"<<std::endl;
}
    else{
        cout<<"pass2"<<endl;
    }

return 0;
}