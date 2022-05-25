#include <iostream>
#include <string>
#include "room.h"

using namespace std;
        Room::Room(int _roomtype, int _price, int _status){
                //constructor with inputs such as type,price and status.
                roomid++;
                roomtype=_roomtype;
                noRoom=roomid;
                price=_price;
                status=_status;
        }

        Room::Room(){
                //default constructor 
                roomid++;
                roomtype=-1;
                noRoom=roomid;;
                price=-1;
                status=0;
        }
       
        int Room::returnroomtype(){
                // returns the room type.
                return roomtype;
        }
        int Room::returnnoRoom(){
                //this function returns the room no.
                return noRoom;
        }
        float Room::returnprice(){
                //this function returns the price of the room
                return price;
        }
        int Room::returnstatus(){
                //this function will return the status. If someone is staying here or not. 1 for true or 0 for false.
                return status;
        }
        int Room::returnroomid(){
                // returns the roomid which should be the same as the room number
                return roomid;
        }
        void Room::changestatus(int _status){
                //this will be used to change the status of the room. if change it to 1 if someone leaves.
                status=_status;
        }

        Room* Room::addroom(){
                float x;
                // a array of room is created 
                Room* a = new Room;
                cout<<"Room type:";
                do {
                        if (cin >> x) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                // takes the room type from the user maenu and stores it in the room array
                a->roomtype=x;
                // takes the room number from the user maenu and stores it in the room array
                a->noRoom=roomid;

                cout<<"Room price:";
                do {
                        if (cin >> x) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                // takes the room price from the user maenu and stores it in the room array
                a->price=x;
                // the status would intial be 0 as no one is staying in that room.
                a->status=0;
                // this would be dispkayed if the room was successful added
                cout<<"Room added!";
                cout<<"The systemn have "<<roomid<<" room data now";
                cout<<"e"<<endl;
                return a;
        }
        
        Room* Room::importroom(int _type,float _price){
                
                Room* a = new Room;
                a->roomtype=_type;
                a->noRoom=roomid;
                a->price=_price;
                a->status=0;
                return a;
        }
        bool Room::isVacant(Room r){
                // the function will be used to check if someone is staying in a room or not
                if(r.status==1){
                        // if the status is 1 then the function would return 0. I.e/ someone is staying here
                        return false;
                }
                else{   // else it would return 1. I.e/ no one is staying here.
                        return true;
                }
                

        }

        void Room::vacatRoom(int){

        }
        void Room::displayRoom(Room){

        }
        void Room::changeroominfo(){
                // this function will be used to change the information of the room.
                float x;
                cout<<"Original Room type is "<< roomtype <<endl<<"Enter the new Room type:";
                do {
                        if (cin >> x) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                // ask the user to change the room type.
                roomtype=x;

                cout<<"Original Room price is "<< price <<endl<<"Enter the new Room price:";
                do {
                        if (cin >> x) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                // ask the user to change the price.
                price=x;

        };
        // default constructor.
        Room::~Room(){

        }
