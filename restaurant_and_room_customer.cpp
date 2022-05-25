#include<iostream>
#include<string>
#include"restaurant_and_room_customer.h"
#include"Customer.h"
using namespace std;
//this is a default constructor and initialize the customer to 0.
Restaurant_and_room_customer::Restaurant_and_room_customer(){
    room=0;
    dish=0;
    changestatus(3);
}

//this will return the room
int Restaurant_and_room_customer::viewroom(){
    return room;
}
// this will return the dish
int Restaurant_and_room_customer::viewdish(){
    return dish;
}
// the bill is initialized to 0.
int Restaurant_and_room_customer::viewtotalbill(){
    
}

// The function allocates a dish to the customer 
void Restaurant_and_room_customer::allocatedish(int _dish){
    dish=_dish;
    cout << "Dish has been allocated for restaurant and room customer!" << endl;
}

// this function allocates a room to the customer.
void Restaurant_and_room_customer::allocateroom(int roomid){
    room = roomid;
    cout << "Room has been allocated for restaurant and room customer!" << endl;
}
// this function is the checkout function and gives the bill to the customer.
void Restaurant_and_room_customer::checkout(){
    room=0;
    dish=0;
    cout << "Goodbye!" << endl;

}
