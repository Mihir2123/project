#include <iostream>
#include <string>
#include "dish.h"
using namespace std;

int Dish::amount=0;

Dish::Dish(){
  dishName="";
  price=0;
}

Dish::Dish(string Name,float price,int id){
    dishName=Name;
    price=price;
    id=amount;
}
int Dish::getamount(){
  return amount;
}
string Dish::getdishname(){
  return dishName;
}
float Dish::getdishprice(){
  return price;
}

Dish* Dish::adddish(){
  Dish* newdish = new Dish;
  amount++;
  string dname;
  cout<<"Dish name:";
  cin>>dname;
  newdish->dishName=dname;
  float dprice;
  cout<<"Dish price:";
  cin>> dprice;
  newdish->price=dprice;
  newdish->id=amount;
  cout<<"Dish added! The menu has "<< amount << " dishes now"<< endl;
  return newdish;
}

void Dish::changedishinfo(){
                string x;
                cout<<"Original Dish name is "<< dishName <<endl<<"Enter the new Dish name:";
                cin>>x;
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

void Dish::getdish(){
    cout<<"Dish name: "<<dishName<<endl;
    cout<<"Dish price: "<<price<<endl;
}

Dish::~Dish(){

}

