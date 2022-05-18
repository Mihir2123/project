#include <iostream>
#include <string>
#include "hotel.h"

using namespace std;
        void Hotel::mainmenu(){
            cout<<endl<<"-------------- Welcom to "<<hotelname<<" management system -------------- "<<endl;
            cout<<"----------------- What do you want to do ? ----------------" <<endl;
            cout<<"--------- 1.Search Room       2.Search Restaurant ---------"<<endl;
            cout<<"--------- 3.Book Room         4.Book Restaurant   ---------"<<endl;
            cout<<"--------- 5.Change Room info  6.Change Restaurant info ----"<<endl;
            cout<<"--------- 7.Check In          8.Check Out -----------------"<<endl;
            cout<<"--------- 9.Search Customer   10.Log Out ------------------"<<endl;
            string x;
            cin>>x;
            while(!(x=="1"||x=="2"||x=="3"||x=="4"||x=="5"||x=="6"||x=="7"||x=="8"||x=="9"||x=="10")){
                cout<<"--------- Invalid input. Please enter again:"<<endl;
                cin>>x;
            }
            int num = stoi(x);
            switch(num){
                case 1:
                {
                    int one;
                    cout<<"Search room number:";
                    cin>>one;
                    if(one<=returnroomid()&&one>0){
                        searchroom(one-1);
                        cout<<endl<<endl;
                        mainmenu();
                    }else{
                        cout<<"Invalid Room Number"<<endl;
                    }
                    break;
                }
                case 2:
                {
                    string two;
                    cout<<"Enter '1' to check the restaurant info or '2' to check the menu or '3' to check a specific dish:";
                    cin>>two;
                    while(!(two=="1"||two=="2"||two=="3")){
                        cout<<"--------- Invalid input. Please enter again:"<<endl;
                        cin>>two;
                    }
                    if(two=="1"){
                        
                    }else if(two=="2"){
                        restaurant.getmenu();
                        mainmenu();
                    }
                    else{
                        int id;
                        cout<<"Search dish number:";
                        cin>>id;
                        if(id<=getamount()&&id>0){
                            restaurant.getdishes()[id-1]->getdish();
                            cout<<endl<<endl;
                            mainmenu();
                        }else{
                            cout<<"Invalid Dish Number"<<endl;
                        }
                    }
                    break;
                }
                case 3:
                {
                    break;
                }
                case 4:
                {
                    break;
                }
                case 5:
                {
                    string five;
                    cout<<"Enter '1' to change existing room or '2' to add new room:";
                    cin>>five;
                    while(!(five=="1"||five=="2")){
                        cout<<"--------- Invalid input. Please enter again:"<<endl;
                        cin>>five;
                    }
                    if(five=="1"){
                        int id;
                        cout<<"Change room info (enter the room number):";
                        cin>>id;
                        if(id<=returnroomid()&&id>0){
                            rooms[id-1]->changeroominfo();
                            mainmenu();
                        }else{
                            cout<<"Invalid Room Number"<<endl;
                        }
                    }else if(five=="2"){
                        rooms.push_back(addroom());
                        cout<<endl<<endl;
                        mainmenu();
                    }
                    break;
                }
                case 6:
                {
                    string six;
                    cout<<"Enter '1' to change the restaurant info or '2' to add a dish or '3' to change the info of a dish:";
                    cin>>six;
                    while(!(six=="1"||six=="2"||six=="3")){
                        cout<<"--------- Invalid input. Please enter again:"<<endl;
                        cin>>six;
                    }
                    if(six=="1"){
                        restaurant.changerestinfo();
                        cout<<endl<<endl;
                        mainmenu();

                    }else if(six=="2"){
                        restaurant.dishes.push_back(adddish());
                        cout<<endl<<endl;
                        mainmenu();
                    }else{
                        if(getamount()==0){
                            cout<<"There are no dish data in the system"<<endl;
                            mainmenu();
                        }
                        int id;
                        cout<<"Change dish number:";
                        cin>>id;
                        if(id<=getamount()&&id>0){
                            restaurant.getdishes()[id-1]->changedishinfo();
                            cout<<endl<<endl;
                            mainmenu();
                        }else{
                            cout<<"Invalid Dish Number"<<endl;
                        }
                    }
                    break;
                }
                case 7:
                {
                    break;
                }
                case 8:
                {
                    break;
                }
                case 9:
                {
                    break;
                }
                case 10:
                {
                    cout<<endl<<endl<<endl<<"Adios!!"<<endl;
                    break;
                }
            }
        }

        Hotel::Hotel(string _hotelname,string _hoteladdress){
            hotelname=_hotelname;
            hoteladdress=_hoteladdress;
            mainmenu();
        }
        Hotel::Hotel(){
            string reply;
            hotelname="empty";
            hoteladdress="empty";
            cout<<"----------- Welcome to hotel management system --------------- "<<endl;
            cout<<"---- Please fill in the  hotel infomation to start to use ---- "<<endl;
            cout<<"--- Press 'y' to fill in now or press 'n' to fill in later ---"<<endl;
            cin>>reply;
            while(!(reply=="y"||reply=="Y"||reply=="n"||reply=="N")){
                cout<<"--- Press 'y' to fill in now or press 'n' to fill in later ---"<<endl;
                cin>>reply;
            }
            if(reply=="Y"||reply=="y"){
                changeinfo();
            }else{
                cout<<"--------------- Hotel management system closeed --------------"<<endl;
            }

        }
        void Hotel::changeinfo(){
            string _hotelname;
            string _hoteladdress;
            cout<<"--- Enter the hotel name: ";
            cin>>_hotelname;
            cout<<"--- Enter the hotel address: ";
            cin>>_hoteladdress;
            hotelname=_hotelname;
            hoteladdress=_hoteladdress;
            mainmenu();
        }
        string Hotel::gethotelname(){
            return hotelname;
        }
        string Hotel::gethoteladdress(){
            return hoteladdress;
        }
        /*void Hotel::sethotel(Restaurant r,int size,Room rs[]){
            restaurant=r;
            size=size;
            room=new Room[size];
            for(int i=0;i<size;i++){
                room[i]=rs[i];
            }      
        }
        void Hotel::searchRoom(int noRoom){
            for(int i=0;i<size;i++){
                if(room[i].noRoom=noRoom){
                    std::cout<<room[i].noRoom<<std::endl;
                    std::cout<<room[i].roomtype<<std::endl;
                    std::cout<<room[i].price<<std::endl;
            }
            }
        }*/

        
        void Hotel::searchroom(int no){
            cout<<"Room Number:"<<rooms[no]->returnnoRoom()<<endl;
            cout<<"Room Type:"<<rooms[no]->returnroomtype()<<endl;
            cout<<"Room Price:"<<rooms[no]->returnprice()<<endl;
            cout<<"Room Status:"<<rooms[no]->returnstatus()<<endl;
        }


        Hotel::~Hotel(){

        }
