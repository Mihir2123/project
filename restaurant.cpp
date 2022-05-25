#include <iostream>
#include <string>
#include "restaurant.h"

using namespace std;
        // default constructor 
        Restaurant::Restaurant(){
             
        }
        //default deconstructor 
        Restaurant::~Restaurant(){
          

        }
        
        void Restaurant::displayMenu(){

        }
        // this function will display a particular dish
        void Restaurant::display(Dish){

        }
        //this function will be used to change dish info.
        void Restaurant::changerestinfo(){

        }
        // this function returns the dishes from the dish array from the dish.cpp
        vector<Dish*> Restaurant::getdishes(){
                return dishes;
        }
        // this function will get the menu from the dish array and display its name and price.
        void Restaurant::getmenu(){
                cout<<"----------- Menu -----------"<<endl;
                for(int x = 0;x<getamount();x++){
                        cout<<x+1<<". "<<dishes[x]->getdishname()<<"  $"<<dishes[x]->getdishprice()<<endl;
                }
                cout<<"-----------------------------"<<endl;
        }