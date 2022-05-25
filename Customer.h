/****
 
 This is the customer file contains the template for the customer class and the information for the customer with 
 the construcotr and deconstructors 

**/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
using namespace std;

class Customer{
private:
    // this data type will be used for the customer Name
    string cusName;
    // this data type will be used to give them thier id
    string cusId;
     //this data type will used for their phone 
    int cusPhone;
    //this data type will be used for the status. i.e/ which type of custoemr they are
    int Status;
public:
   // default constructor 
    Customer();
    // this function will be used to set the data of a particular customer with thier name and phone number etc
    void setData(string cus_name, int cus_phone);
     // this function will be used to store what they are doing in the hotel such as are they staying in the hotel or dining in
    int selectchoice();
       // this function will print the customer's detail
    void printcustomer();
    // this function will output the customer's name
    string getcusName();
     // this function will output the customer's id 
    string getcusId();
    // this function will output the customer's phone numbe
    int getcusPhone();
     //this function will output their status. I.e/ which type of customer they are
    int getStatus();
    //This function will be used to change the customer status 
    void changestatus(int x);
     // these are the virtual function that are used in the different types of customer 
    virtual int viewtotalbill() = 0;
    virtual void allocateroom(int roomid) =0;
    virtual void allocatedish(int dishid)=0;
    virtual void checkout() = 0;
    virtual int viewroom() = 0;
    virtual int viewdish() = 0;
    //Defualt deconstructor 
    ~Customer();
};
#endif

