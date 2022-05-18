#include <iostream>
#include <string>
#include "restaurant.h"

using namespace std;
        Restaurant::Restaurant(){
            
        }
        Restaurant::~Restaurant(){

        }
        void Restaurant::displayMenu(){

        }
        void Restaurant::display(Dish){

        }
        void Restaurant::changerestinfo(){

        }
        vector<Dish*> Restaurant::getdishes(){
                return dishes;
        }
        void Restaurant::getmenu(){
                cout<<"----------- Menu -----------"<<endl;
                for(int x = 0;x<getamount();x++){
                        cout<<x+1<<". "<<dishes[x]->getdishname()<<"  $"<<dishes[x]->getdishprice()<<endl;
                }
                cout<<"-----------------------------"<<endl;
        }