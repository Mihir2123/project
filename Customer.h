#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
using namespace std;

class Customer{
private:
    string cusName;
    string cusId;
    int cusPhone;
    string Status;
public:
    Customer();
    void setData(string cus_name, string cus_id, int cus_phone, string status);
    int selectchoice();
    void printcustomer();
    string getcusName();
    string getcusId();
    int getcusPhone();
    string getStatus();
    virtual void totalbill() = 0;
    virtual void allocatedish() = 0;
    virtual void allocateroom() = 0;
    virtual void checkout() = 0;
    ~Customer();
};
#endif

