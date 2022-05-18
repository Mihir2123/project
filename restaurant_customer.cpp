#include<iostream>
#include<string>
#include"restaurant_customer.h"
using namespace std;

void restaurant_customer::allocatedish(){
    
}
void restaurant_customer::printcustomer(){ // have to write get and set methods
    cout << "Customer's name: " << getcusName() << endl;
    cout << "Customer's ID: " << getcusId() << endl;
    cout << "Customer's phone: " << getcusPhone() << endl;
    if(selectchoice() == 1){
        cout << "Status: Dine in!"  << endl;
    }
    else if (selectchoice() == 2){
        cout << "Status: Staying at hotel!" << endl;
    }  
}
void restaurant_customer::viewtotalbill(){

}