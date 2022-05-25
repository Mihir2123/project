

/****
 
 This is the dish file contains the template for the dish class and the information for what information must be given to 
 to create a dish such as it's price and name with 
 the construcotr and deconstructors 

**/




#ifndef dish_h
#define dish_h
#include <string>
using namespace std;


class Dish{
    private:
        //this data type will be used to store the dishname
        string dishName;
        //this data type will be used to store the price
        float price;
        //this data type will used to give an id to a dish.
        int id;
        //this data type will be used to store the number of dishes that will be stored.
        //For example if one dish will added then this should return one.
        static int amount;
    public:
        // default constructor
        Dish();
        // This constructor will be used to allocate name,price and id to the dish.
        Dish(string Name,float price,int id);
        //This function will return the amount of dishes in the array.
        static int getamount();
        //This function will return the dish name.
        string getdishname();
        //This function will return the dish price.
        float getdishprice();
        //This function will be used to add the dish.
        static Dish* adddish();
        //This function will be used to return the dish that are in the array.
        void getdish();
        //This function will be used to change the information of the dish. For example, you could change a price of a dish.
        void changedishinfo();
        //Default deconstructors
        ~Dish();
};

#endif