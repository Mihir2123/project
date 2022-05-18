#include <iostream>
#include <string>
#include "room.h"

using namespace std;
        Room::Room(int _roomtype, int _price, int _status){
                roomid++;
                roomtype=_roomtype;
                noRoom=roomid;
                price=_price;
                status=_status;
        }

        Room::Room(){
                roomid++;
                roomtype=-1;
                noRoom=roomid;;
                price=-1;
                status=0;
        }
       
        int Room::returnroomtype(){
                return roomtype;
        }
        int Room::returnnoRoom(){
                return noRoom;
        }
        float Room::returnprice(){
                return price;
        }
        int Room::returnstatus(){
                return status;
        }
        int Room::returnroomid(){
                return roomid;
        }


        Room* Room::addroom(){
                float x;
                Room* a = new Room;
                cout<<"Room type:";
                do {
                        if (cin >> x) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                a->roomtype=x;

                a->noRoom=roomid;

                cout<<"Room price:";
                do {
                        if (cin >> x) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                a->price=x;
                
                a->status=0;
                cout<<"Room added!";
                cout<<"The systemn have "<<roomid<<" room data now";
                cout<<"e"<<endl;
                return a;
        }

        bool Room::isVacant(Room r){

                if(r.status==1){
                        return false;
                }
                else{
                        return true;
                }
                

        }

        void Room::vacatRoom(int){

        }
        void Room::displayRoom(Room){

        }
        void Room::changeroominfo(){
                float x;
                cout<<"Original Room type is "<< roomtype <<endl<<"Enter the new Room type:";
                do {
                        if (cin >> x) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                roomtype=x;

                cout<<"Original Room price is "<< price <<endl<<"Enter the new Room price:";
                do {
                        if (cin >> x) break;
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input.Try again:";
                }
                while (true);
                price=x;

        };
        Room::~Room(){

        }
