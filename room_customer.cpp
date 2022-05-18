#include<iostream>
#include<string>
#include"restaurant_customer.h"
#include"Customer.h"
using namespace std;

void Customer::printcustomer(){
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
void Room_customer::allocateroom(){
    
}
void Room_customer::viewtotalbill(){

}