#include<iostream>
#include<string>
#include"Customer.h"
using namespace std;

Customer::Customer(){  
    cusName;
    cusId;
    cusPhone = 0;
    Status;
}
void Customer::setData(string cus_name, string cus_id, int cus_phone, string status){
    cusName = cus_name;
    cusId = cus_id;
    cusPhone = cus_phone;
    Status = status;
}
int Customer::selectchoice(){
    int choice = 0;
    cout << "Select 1 to 'dine in' and 2 to 'stay': ";
    cin >> choice;
    return choice;
}
void Customer::printcustomer(){
    cout << "Customer's name: " << cusName << endl;
    cout << "Customer's ID: " << cusId << endl;
    cout << "Customer's phone: " << cusPhone << endl;
    if(selectchoice() == 1){
        cout << "Status: Dine in!"  << endl;
    }
    else if (selectchoice() == 2){
        cout << "Status: Staying at hotel!" << endl;
    }        
}
string Customer::getcusName(){
    return cusName;
}
string Customer::getcusId(){
    return cusId;
}
int Customer::getcusPhone(){
    return cusPhone;
}
string Customer::getStatus(){
    return Status;
}
Customer::~Customer(){

}
