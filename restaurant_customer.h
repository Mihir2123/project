
/****
 
 This is the restaurant_customer.h file that has infomration for the restaurant customer which inherits stuff from the
 customer class.

**/



#ifndef RESTAURANT_CUSTOMER_H
#define RESTAURANT_CUSTOMER_H
#include<string>
#include"Customer.h"
#include"dish.h"
using namespace std;

class Restaurant_customer : public Customer{
private:
    // this data type will used for the bill.
    double bill;
    //this data type will be used to allocate a dish
    int dish;
public:
    //default constructor
    Restaurant_customer();
    //this function will return the total bill
    int viewtotalbill();
    //this function will be used to allocate a dish
    void allocatedish(int dish);
    //this function will be used to allocate a room
    void allocateroom(int room);
    //this will return the room info
    int viewroom();
    //this will return the dish info.
    int viewdish();
    //this will be used to check the customer out.
    void checkout();
};
#endif