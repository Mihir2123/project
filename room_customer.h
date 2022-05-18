#ifndef ROOM_CUSTOMER_H
#define ROOM_CUSTOMER_H
#include<string>
#include"room_customer.h"
using namespace std;

class Room_customer{
private:
    double bill;
    // Dish d;
    int bookstatus;
    int customertype;
public:    
    void printcustomer();
    void allocateroom();
    void viewtotalbill();
};
#endif