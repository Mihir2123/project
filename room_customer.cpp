#include<iostream>
#include<string>
#include"room_customer.h"
using namespace std;

Room_customer::Room_customer(){ 
    room=0;
    changestatus(1);
}
int Room_customer::viewroom(){
    return room;
}
int Room_customer::viewdish(){
    cout << "No dish for room customer"<<endl;
    return 0;
}
int Room_customer::viewtotalbill(){
    viewroom();
}
void Room_customer::allocateroom(int roomid){
    room=roomid;
    cout << "Room has been allocated for restaurant customer!" << endl;
}
void Room_customer::allocatedish(int dishid){
    cout << "Restaurant can not be booked for room customer!" << endl;
}
void Room_customer::checkout(){
    cout << "Goodbye!" << endl;
    room=0;
}