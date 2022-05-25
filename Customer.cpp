#include<iostream>
#include<string>
#include"Customer.h"
using namespace std;

// default constructor. This will be printed when no input is given
Customer::Customer(){  
    cusName = "No name entered";
    cusId  = "No ID entered";
    cusPhone = 0;
    Status = 0;
}
// this function takes the input of the customer's name and phoen number and stores it.
void Customer::setData(string cus_name, int cus_phone){
    cusName = cus_name;
    cusPhone = cus_phone;
}

int Customer::selectchoice(){
     // takes the input of the customer through cin.
    int choice = 0;
    cout << "Select 1 to 'dine in' or 2 to 'stay': ";
    cin >> choice;
    return choice;
}
void Customer::printcustomer(){
    // prints out the customer details such as their name, id and number 
    cout << "Customer's name: " << cusName << endl;
    cout << "Customer's ID: " << cusId << endl;
    cout << "Customer's phone: " << cusPhone << endl;
      // it will also print out what type of guest they are 
    if(selectchoice() == 1){
        cout << "Status: Dine in!"  << endl;
    }
    
    else if (selectchoice() == 2){
        cout << "Status: Staying at hotel!" << endl;
    }        
}
string Customer::getcusName(){
      // returns the cusotmer name 
    return cusName;
}
string Customer::getcusId(){
     //returns customer id 
    return cusId;
}
int Customer::getcusPhone(){
    // returns the customer's number
    return cusPhone;
}
int Customer::getStatus(){
     // returns what type of custoemr they are.
    return Status;
}
void  Customer::changestatus(int x){

    Status=x;
}
//default deconstructor 

Customer::~Customer(){

}
