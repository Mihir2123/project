#ifndef restaurant_h
#define restaurant_h
#include <string>
#include <vector>
#include "dish.h"
using namespace std;



class Restaurant: public Dish{
    public:
        vector<Dish*> dishes;
    public:
        Restaurant();
        ~Restaurant();
        vector<Dish*> getdishes();
        void displayMenu();
        void display(Dish);
        void changerestinfo();
        void getmenu();
};

#endif