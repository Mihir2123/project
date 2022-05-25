#ifndef hotel_h
#define hotel_h
#include <string>
#include <vector>
#include "room.h"
#include "restaurant.h"

#include "room_customer.h"
#include "restaurant_and_room_customer.h"
#include "restaurant_customer.h"

using namespace std;

//,public Restaurant_customer,public Restaurant_and_room_customer
class Hotel:public Room,public Restaurant,public Room_customer,public Restaurant_customer,public Restaurant_and_room_customer{
    private:
        // the data type will be used to store the hotel name.
        string hotelname;
         // the data type will be used to store the hotel address.
        string hoteladdress;
             
        Restaurant restaurant;
        Customer* restaurantcus[10];
        vector<Room*> rooms;
        vector<Customer*> customers;
    public:
        // this function will be used to take input for the name and address. The user could set this via this function or the set hotel function.
        Hotel(string _hotelname,string _hoteladdress);
        //This is the default constructor.
        Hotel();
        //This function will be used to change the information of the hotelname or address.
        void changeinfo();
         //This function will be used to set the hotel name and address.
        void sethotel();
              //This function will be used as the mainmenu of the program which will be used by the user. This is where they can 
              //do certain thing such as change the name, book a room or add a room and etc.
        void mainmenu();
        // This function will return the hotel name.
        string gethotelname();
                // This function will return the hotel address.
        string gethoteladdress();
        //This function will be used to search for a particular room. This should return the room info and the cusotmer info that is staying here.
        void searchroom(int no);
        
        int viewtotalbill();
        void allocateroom(int roomid);
        void checkout();
        //this is the default deconstructor.
        ~Hotel();
};

#endif