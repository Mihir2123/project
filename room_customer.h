#ifndef ROOM_CUSTOMER_H
#define ROOM_CUSTOMER_H
#include"Customer.h"
#include<string>
using namespace std;

class Room_customer:public Customer{
private:
    // this data type will be used for the bill of the customer 
    double bill;
    // this data type will be used for the room number
    int room;
public:
    // default constructor 
    Room_customer(); 
    //this function will return the total bill   
    int viewtotalbill();
    //this function will allocate the room 
    void allocateroom(int roomid);
    //a message will be displayed when the user try to give them a dish.
    void allocatedish(int dishid);
    //the room info will be displayed.
    int viewroom();
    //the dish info won't presented instead a message will come.
    int viewdish();
    //this function will be used to check a customer out.
    void checkout();
};
#endif