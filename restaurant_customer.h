#ifndef RESTAURANT_CUSTOMER_H
#define RESTAURANT_CUSTOMER_H
#include<string>
#include"Customer.h"
//#include"dish.h"
using namespace std;

class Restaurant_customer : public Customer{
private:
    double bill;
    //Dish d;
    int bookstatus;
    int customertype;
public:
    void allocatedish();
    void printcustomer();
    void viewtotalbill();
};
#endif