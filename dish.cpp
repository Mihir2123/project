#include <iostream>
#include <string>
#include "dish.h"
using namespace std;

int Dish::amount=0;
//default deconstructor where the dishname is null and price is 0.
Dish::Dish(){
  dishName="";
  price=0;
}
//constuctor with inputs for the dish name,price and it's id/
Dish::Dish(string Name,float _price,int id){
    dishName=Name;
    price=_price;
    id=amount;
}
//This function returns the amount.
int Dish::getamount(){
  return amount;
}
//This function returns the dish name
string Dish::getdishname(){
  return dishName;
}
//This function returns the price.
float Dish::getdishprice(){
  return price;
}

Dish* Dish::adddish(){
  //the use of new to create an array of dishes.
  Dish* newdish = new Dish;
  amount++;
  //aks for the input for the dish such as it's name and price.
  string dname;
  cout<<"Dish name:";
  cin>>dname;
  newdish->dishName=dname;
  float dprice;
  cout<<"Dish price:";
  cin>> dprice;
  newdish->price=dprice;
  newdish->id=amount;
  //the message that will be displayed when the dish is added.
  cout<<"Dish added! The menu has "<< amount << " dishes now"<< endl;
  return newdish;
}
//this function will be used to dish the dish info
void Dish::changedishinfo(){
                string x;
                // the original info will be displayed 
                cout<<"Original Dish name is "<< dishName <<endl<<"Enter the new Dish name:";
                cin>>x;
                //then the user will be asked to change the info.
                dishName=x;
                float newprice;
                cout<<"Original Dish price is $"<< price <<endl<<"Enter the new Dish price:";
                do {
                        if (cin >> newprice) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                price=newprice;

}

//This function will be used to display a dish.
void Dish::getdish(){
    cout<<"Dish name: "<<dishName<<endl;
    cout<<"Dish price: "<<price<<endl;
}
//Default deconstructor
Dish::~Dish(){
  delete this;
}

