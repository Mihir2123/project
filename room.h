#ifndef room_h
#define room_h
#include <string>
using namespace std;


class Room{
    private:
        // this data tyoe will be used to store the room type.
        int roomtype;
         // this data tyoe will be used to store the room number.
        int noRoom;
         // this data tyoe will be used to store the room price.
        float price;
         // this data tyoe will be used to indicate if a room is booked or not. For example, if it's 0 than it means its not booked.
        int status;
         // this data tyoe will be used to store the room id.
        static int roomid;
    public:
        // this constructor will be used to allocate the room with details such as it's room type, price and status.
        Room(int _roomtype, int _price, int _status);
        // this is a default constructor.
        Room();
        // this function will return theroom type.
        int returnroomtype();
        // this function will return the array of rooms.
        int returnnoRoom();
           // this function will return the room price.
        float returnprice();
            // this function will return the room status. I.e/ if it's booked or not.
        int returnstatus();
             // this function will return the the room id of a particular rooom. I.e/ let's say the first room is added
             //then this function should return it's id as 1. 

        void changestatus(int _status);

        static int returnroomid();
        // this function will be used to change the information of the room such as it's type, price, no and status. Mostly the status.
        void changeroominfo();
        //this function will be used to add the room to any array.
        static Room* addroom();
        
        static Room* importroom(int type,float price);
        // this function will be used to check if a rooom is vacant. For example, if a room is vacant then it should return true or 1.
        bool isVacant(Room r);
        //This function will be used to vaccat a room. I.e change it's status.
        void vacatRoom(int no);
        //This function will be used to display the array of rooms.
        void displayRoom(Room);
        // this is the deconstructor where the array will be deleted.
        ~Room();
};

#endif