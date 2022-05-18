#ifndef room_h
#define room_h
#include <string>
using namespace std;


class Room{
    private:
        int roomtype;
        int noRoom;
        float price;
        int status;
        static int roomid;
    public:
        Room(int _roomtype, int _price, int _status);
        Room();

        int returnroomtype();
        int returnnoRoom();
        float returnprice();
        int returnstatus();
        static int returnroomid();

        void changeroominfo();
        static Room* addroom();
        bool isVacant(Room r);
        void vacatRoom(int no);
        void displayRoom(Room);

        ~Room();
};

#endif