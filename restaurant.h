/**
  This is the restaurant.h file that contains the information for the restaurant class.

 **/


#ifndef restaurant_h
#define restaurant_h
#include <string>
#include <vector>
#include "dish.h"
using namespace std;



class Restaurant: public Dish{
    public:
        // this data type will be used to get the dishes that will be in the menu. This will include its name, price and id.
        vector<Dish*> dishes;
    public:
        // this the default constructor 
        Restaurant();
         // this the default deconstructor 
        ~Restaurant();
        //This function will return the dishes that are in the restaurant. I.e/ this should return the particular dish from the array of dishes.
        vector<Dish*> getdishes();
        //This function will return the menu.
        void displayMenu();
        // This function will be used to display a particular dish such as it's price, name and id.
        void display(Dish);
        // This function will be used to change any information.
        void changerestinfo();
        // This function will be used to get the dish array into the restuarant class.
        void getmenu();
};

#endif