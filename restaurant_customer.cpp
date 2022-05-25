#include<iostream>
#include<string>
#include"restaurant_customer.h"
#include"Customer.h"
using namespace std;
// this is a default constructor and make ths customertype and bill as 0.
Restaurant_customer::Restaurant_customer(){
    dish=0;
    changestatus(2);
}
//this function will be used to display a message that a restuarant customer can't book a room
int Restaurant_customer::viewroom(){
    cout << "No room for restaurant customer"<<endl;
    return 0;
}
// this would return the dish that the customer is having.
int Restaurant_customer::viewdish(){
    return dish;
}
//this will return the dish that the customer is having.
int Restaurant_customer::viewtotalbill(){
    viewdish();
}
//this will allocate the dish 
void Restaurant_customer::allocatedish(int _dish){
    dish=_dish;
    cout << "Dish has been allocated for restaurant customer!" << endl;
}

void Restaurant_customer::allocateroom(int room){
    cout << "Room has not been allocated for restaurant customer!" << endl;
}
//this will be used to check a customer out.
void Restaurant_customer::checkout(){
    cout << "Goodbye!" << endl;
    dish=0;
}