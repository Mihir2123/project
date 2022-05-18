#ifndef hotel_h
#define hotel_h
#include <string>
#include <vector>
#include "room.h"
#include "restaurant.h"
using namespace std;


class Hotel:public Room,public Restaurant{
    private:
        string hotelname;
        string hoteladdress;
        Restaurant restaurant;
        vector<Room*> rooms;
    public:
        Hotel(string _hotelname,string _hoteladdress);
        Hotel();
        void changeinfo();
        void sethotel();
        void mainmenu();
        string gethotelname();
        string gethoteladdress();
        void searchroom(int no);
        ~Hotel();
};

#endif