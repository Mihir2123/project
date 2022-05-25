

/****
 
 This is the restaurant_room.h file that contains the information for the restaurant customer and the room customer. 
 this class will inherit from the customer class as its a type of a customer.

**/


#ifndef RESTAURANT_AND_ROOM_CUSTOMER_H
#define RESTAURANT_AND_ROOM_CUSTOMER_H
#include"Customer.h"
#include<string>
using namespace std;

class Restaurant_and_room_customer : public Customer{
private:         
    // this data type will be used for the bill
    double bill;
    //this data type will be used for the room number.
    int room;
    // this data type will be used for the type of the customer.  
    int dish;
public:
    // this is the default constructor
    Restaurant_and_room_customer();
    //this function will return the room that the customer is staying in.
    int viewroom();
    //this function will return the dish that the customer is having.
    int viewdish();
    // this function will be used to calculate the total bill of the customer 
    int viewtotalbill();
    // this function will be used to allocate a dish
    void allocatedish(int dish);
    // this function will be used to allocate a room
    void allocateroom(int roomid);
    //this function will be used to checkout.
    void checkout();
};
#endif