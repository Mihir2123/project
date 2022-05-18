#ifndef dish_h
#define dish_h
#include <string>
using namespace std;


class Dish{
    private:
        string dishName;
        float price;
        int id;
        static int amount;
    public:
        Dish();
        Dish(string Name,float price,int id);
        
        static int getamount();
        string getdishname();
        float getdishprice();
        static Dish* adddish();
        void getdish();
        void changedishinfo();
        ~Dish();
};

#endif