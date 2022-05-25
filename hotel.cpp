#include <iostream>
#include <string>
#include <fstream>
#include "hotel.h"

using namespace std;
        // this is the default constructor for the hotel class.
        Hotel::Hotel(){
            //the intial name and address is empty
            string reply;
            hotelname="empty";
            hoteladdress="empty";
            // the user will be asked to add the information for the hotel
            cout<<"----------- Welcome to hotel management system --------------- "<<endl;
            cout<<"---- Please fill in the  hotel infomation to start to use ---- "<<endl;
            cout<<"--- Press 'y' to fill in now or press 'n' to fill in later ---"<<endl;
            //prompoted to reply with a yes or no
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
        //There is also a constuctor that the user can use to set the hotel name and address
        Hotel::Hotel(string _hotelname,string _hoteladdress){
            hotelname=_hotelname;
            hoteladdress=_hoteladdress;
            for(int x = 0 ; x<10 ;x++){
                restaurantcus[x]=nullptr;
            }
            mainmenu();
        }
        //this will be the usermenu that the user will see when they use our system.
        //They have 11 options as seen below.
        void Hotel::mainmenu(){
            cout<<endl<<"-------------- Welcom to "<<hotelname<<" management system -------------- "<<endl;
            cout<<"----------------- What do you want to do ? ----------------" <<endl;
            cout<<"--------- 1.Search Room       2.Search Restaurant ---------"<<endl;
            cout<<"--------- 3.Book Room         4.Book Restaurant   ---------"<<endl;
            cout<<"--------- 5.Change Room info  6.Change Restaurant info ----"<<endl;
            cout<<"--------- 7.View Bill         8.Check Out -----------------"<<endl;
            cout<<"--------- 9.Import Room Data   10.Export Room Data --------"<<endl;
            cout<<"----------11.Search Customrer  12.Log out -----------------"<<endl;
            string x;
            cin>>x;
            //error
            while(!(x=="1"||x=="2"||x=="3"||x=="4"||x=="5"||x=="6"||x=="7"||x=="8"||x=="9"||x=="10"||x=="11"||x=="12")){
                cout<<"--------- Invalid input. Please enter again:"<<endl;
                cin>>x;
            }
            int num = stoi(x);
            //case
            switch(num){
                //search room
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
                //search restaurant
                case 2:
                {
                    string two;
                    cout<<"Enter '1' to check the menu or '2' to check a specific dish:";
                    cin>>two;
                    while(!(two=="1"||two=="2")){
                        cout<<"--------- Invalid input. Please enter again:"<<endl;
                        cin>>two;
                    }if(two=="1"){
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
                    //case 3 will be used to book a room under a customer.
                    cout<<"Book for new customer (0) or old customer (1)?";
                    int choice;
                    cin>>choice;
                    
                    //the user's choice will be checked.
                    while(!(choice==1||choice==0)){
                        cout<<"Invaild input"<<endl;
                        cin >> choice;
                    }
                     // this if statement will check if the customer wants to also dine in and stay at the hotel
                    if(customers.size()==0&&choice==1){
                        cout<<"No customer data in the system"<<endl;
                        cout<<"Adding a new customer:"<<endl;
                        choice=0;
                    }
                    if(choice == 0){
                        cout<<"Will the customer also dine?enter 'y' if yes"<<endl;
                        string choice;
                        cin >> choice;
                        if (choice == "y"){
                            //a customer array will be created both customers that are both types of customers.
                            Customer* x = new Restaurant_and_room_customer;
                            customers.push_back(x);

                            // user will be asked to fill in the customer's info
                            string name;
                            cout<<"name"<<endl;
                            cin>>name;
                            
                            int phone;
                            cout<<"phone"<<endl;
                            cin>>phone;
                            x->setData(name,phone);
                            int bookroom;
                            cout<<"room id"<<endl;
                            cin>>bookroom;
                            if(rooms.size()>bookroom-1){
                                if(rooms[bookroom-1]->returnstatus()!=0){
                                    cout<<"The room is booked"<<endl;
                                }
                                else{
                                    x->allocateroom(bookroom);
                                    rooms[bookroom-1]->changestatus(1);
                                }
                            }else{
                                cout<<"no this room"<<endl;
                            }
                        }
                        else{
                            
                            // if the customer just wants to stay at the hotel then 
                            //they will be added to the room customer array
                            Customer* x = new Room_customer;
                            customers.push_back(x);

                            // the user will be asked to fill in the info of the customer
                            string name;
                            cout<<"name"<<endl;
                            cin>>name;
                            
                            int phone;
                            cout<<"phone"<<endl;
                            cin>>phone;
                            x->setData(name,phone);
                            int bookroom;
                            cout<<"room id"<<endl;
                            cin>>bookroom;
                            if(rooms.size()>bookroom-1){
                                if(rooms[bookroom-1]->returnstatus()!=0){
                                    cout<<"The room is booked"<<endl;
                                }
                                else{
                                    x->allocateroom(bookroom);
                                    rooms[bookroom-1]->changestatus(1);
                                }
                            }else{
                                cout<<"no this room"<<endl;
                            }
                        }
                        
                    }
                    else if (choice == 1){
                        //this option will be used to check if a restuarant customer tries to book a room
                        cout<<"What is the customer id?"<<endl;
                        int id;
                        // customer id will be asked
                        cin>>id;
                        while(!(id<=customers.size()&&id>0)){
                            cout<<"No this customer.Please enter again:"<<endl;
                            cin>>id;
                        }
                        if(customers[id-1]->getStatus()==1||customers[id-1]->getStatus()==3){
                            int bookroom;
                            cout<<"room id"<<endl;
                            cin>>bookroom;
                            if(rooms.size()>bookroom-1){
                                if(rooms[bookroom-1]->returnstatus()!=0){
                                    cout<<"The room is booked"<<endl;
                                }
                                else{
                                    customers[id-1]->allocateroom(bookroom);
                                    rooms[bookroom-1]->changestatus(1);
                                }
                            }else{
                                cout<<"no this room"<<endl;
                            }
                        }
                        else{
                            cout<<"cant book a room for restaurant customer"<<endl;
                        }
                    }
                    mainmenu();
                    break;
                }
                case 4:
                {   
                    // this case will be used for the dine in customers 
                    // the customer could alreayd be staying in the hotel 
                    // and wants to dine in.
                    cout<<"Book for new customer (0) or old customer (1)?";
                    int choice1;
                    cin>>choice1;
                    // the choice validation will be checked.
                    while(!(choice1==1||choice1==0)){
                        cout<<"Invaild input"<<endl;
                        cin >> choice1;
                    }
                    if(customers.size()==0&&choice1==1){
                        cout<<"No customer data in the system"<<endl;
                        cout<<"Adding a new customer:"<<endl;
                        choice1=0;
                    }
                    // if the customer is a new customer then 
                    // there data will be added to the system
                    if(choice1 == 0){
                        cout<<"Will the customer also stay?enter 'y' if yes"<<endl;
                        string choice;
                        cin >> choice;
                        if (choice == "y"){
                            Customer* cus = new Restaurant_and_room_customer;
                            customers.push_back(cus);

                            string name;
                            cout<<"name"<<endl;
                            cin>>name;
                            
                            int phone;
                            cout<<"phone"<<endl;
                            cin>>phone;
                            cus->setData(name,phone);
                            for(int x = 0;x<10;x++){
                                if(restaurantcus[x]==nullptr){
                                    restaurantcus[x]= cus;
                                    cout<<"which set does they want?enter in set id."<<endl;
                                    int set;
                                    cin >> set;
                                    while(!(set<=getamount()&&set>0)){
                                        cout<<"Invalid Dish Number"<<endl;
                                        cin >> set;
                                    }
                                    cus->allocatedish(set);
                                    cout<<"Restaurant Booked!"<<endl;
                                    
                                    mainmenu();
                                }
                            }
                            cout<<"Restaurant fulled!"<<endl;
                        }
                        else{
                        Customer* cus = new Restaurant_customer;
                        customers.push_back(cus);

                        string name;
                        cout<<"name"<<endl;
                        cin>>name;
                        
                        int phone;
                        cout<<"phone"<<endl;
                        cin>>phone;
                        cus->setData(name,phone);
                        for(int x = 0;x<10;x++){
                            if(restaurantcus[x]==nullptr){
                                restaurantcus[x]= cus;
                                cout<<"which set does they want?enter in Dish id."<<endl;
                                int set;
                                cin >> set;
                                while(!(set<=getamount()&&set>0)){
                                    cout<<"Invalid Dish Number"<<endl;
                                    cin >> set;
                                }
                                cus->allocatedish(set);
                                cout<<"Restaurant Booked!"<<endl;
                                mainmenu();
                            }
                        }
                        cout<<"Restaurant fulled!"<<endl;
                        }
                    }
                    else if (choice1 == 1){
                        cout<<"What is the customer id?"<<endl;
                        int id;
                        cin>>id;
                        while(!(id<=customers.size()&&id>0)){
                            cout<<"No this customer.Please enter again:"<<endl;
                            cin>>id;
                        }
                        if(customers[id-1]->getStatus()==2||customers[id-1]->getStatus()==3){
                            int bookdish;
                            cout<<"Dish id"<<endl;
                            cin>>bookdish;
                            if(bookdish<=getamount()&&bookdish>0){
                                    customers[id-1]->allocatedish(bookdish);
                                
                            }else{
                                cout<<"no this dish"<<endl;
                            }
                        }
                        else{
                            // if the customer is a room customer and doesn't have access to the restaurant this will 
                            //printed.
                            cout<<"cant book restaurant for room customer"<<endl;
                        }
                    }
                    mainmenu();
                    break;
                }
                case 5:
                {   // case 5 will be used to change the room info
                    string five;
                    // if the user want to change a existing room or add a room
                    cout<<"Enter '1' to change existing room or '2' to add new room:";
                    cin>>five;
                    // the user's input will be checked
                    while(!(five=="1"||five=="2")){
                        // if the user input is wrong then this will be displayed.
                        cout<<"--------- Invalid input. Please enter again:"<<endl;
                        cin>>five;
                    }
                    if(five=="1"){
                        // if the user input is right and they want to change an existing room then
                        // they will be taken here.
                        int id;
                        // the room id will be asked
                        cout<<"Change room info (enter the room number):";
                        cin>>id;
                        // user input will be checked
                        if(id<=returnroomid()&&id>0){
                            //if input is correct then they will directed to the changeroominfo function in room class.
                            rooms[id-1]->changeroominfo();
                            mainmenu();
                        }else{
                            //if the input is wrong, then this will be printed.
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
                {   // case 6 will be used to add a dish or change dish info
                    string six;
                    cout<<"'1' to add a dish or '2' to change the info of a dish:";
                    cin>>six;
                    //user input will be checked
                    while(!(six=="1"||six=="2")){
                        // if user input is wrong this will be printed.
                        cout<<"--------- Invalid input. Please enter again:"<<endl;
                        cin>>six;
                    }
                    if(six=="1"){
                        //if user chooses to add a dish then they will be directed to add dish function in restaurant class.
                        restaurant.dishes.push_back(adddish());
                        cout<<endl<<endl;
                        mainmenu();
                    }else{
                        //else if they want change the info of exisiting dish they will be directed here
                        //if there are no dishes then this will be printed.
                        if(getamount()==0){
                            cout<<"There are no dish data in the system"<<endl;
                            mainmenu();
                        }
                        //if there are dish then the user will asked to input the dish id 
                        int id;
                        cout<<"Change dish number:";
                        cin>>id;
                        //user input will be checked.
                        if(id<=getamount()&&id>0){
                            //if the input is valid, they will be directed to changedishinfo function in restaurant.
                            restaurant.getdishes()[id-1]->changedishinfo();
                            cout<<endl<<endl;
                            mainmenu();
                        }else{
                            //this will be printed if the input is invalid.
                            cout<<"Invalid Dish Number"<<endl;
                        }
                    }
                    break;
                }
                case 7:
                {   //case 7 will be used to view the bill of the customer.
                    int cusid;
                    cout<<"what is the cusid"<<endl;
                    // the customer id will be asked.
                    cin>>cusid;
                    if(!(customers.size()>cusid-1)){
                        // the input will be checked.
                        cout<<"no this cus"<<endl;
                    }
                    else{
                        if(customers[cusid-1]->getStatus()==1){
                            //if the customer is a room customer then they bill be
                            //here. the bill will be maded in the customer class already.
                            //it will only be displayed here.
                            int roomid = customers[cusid-1]->viewtotalbill();
                            if(roomid!=0){
                                
                                float price = rooms[roomid-1]->returnprice();
                                cout << "$" << price << endl;
                            }
                            else{
                                cout << "$0" << endl;
                            }
                        }else if(customers[cusid-1]->getStatus()==2){
                            //if the customer is a restaurant customer then they bill be
                            //here. the bill will be maded in the customer class already.
                            //it will only be displayed here.
                            int dishid = customers[cusid-1]->viewtotalbill();
                            if(dishid!=0){
                                float price = restaurant.getdishes()[dishid-1]->getdishprice();
                                cout << "$" << price << endl;
                            }
                            else{
                                cout << "$0" << endl;
                            }
                            
                        }
                        else if(customers[cusid-1]->getStatus()==3){
                            //if the customer is a room and resstaurant customer then they bill be
                            //here. the bill will be maded in the customer class already.
                            //it will only be displayed here.
                            float priceroom;
                            int roomid = customers[cusid-1]->viewroom();
                            if(roomid==0){
                                priceroom=0;
                            }
                            else{
                                priceroom = rooms[roomid-1]->returnprice();
                            }
                            float pricedish;
                            int dishid = customers[cusid-1]->viewdish();
                            if(dishid==0){
                                pricedish=0;
                            }
                            else{
                                pricedish = restaurant.getdishes()[dishid-1]->getdishprice();
                            }
                            float price = pricedish + priceroom;
                            cout << "$" << price << endl;
                        }
                        else{
                            cout << "this customer has no booking"<< endl;
                        }
                    }
                    mainmenu();
                    break;
                    
                }
                case 8:
                {   // case 8 will be used to check a cusotmer out.
                    int cusid;
                    cout<<"cusid"<<endl;
                    cin>>cusid;
                    if(!(customers.size()>cusid-1)){
                        cout<<"no this cus"<<endl;
                    }
                    
                    else{
                        //if the customer is room customer then their status of the room 
                        //they stayed in will be changed.
                        if(customers[cusid-1]->getStatus()==1){
                            int roomid = customers[cusid-1]->viewtotalbill();
                            rooms[roomid-1]->changestatus(0);
                            customers[cusid-1]->checkout();
                        }
                        //if the customer is restaurant customer then their data will be removed
                        // from the restuarant array.
                        else if(customers[cusid-1]->getStatus()==2){
                            for(int x =0;x<10;x++){
                                if(restaurantcus[x]->getcusId()==customers[cusid-1]->getcusId()){
                                    restaurantcus[x]->checkout();
                                    delete restaurantcus[x];
                                }
                            }
                        }
                        else if(customers[cusid-1]->getStatus()==3){
                            int roomid = customers[cusid-1]->viewtotalbill();
                            if(roomid!=0){
                                rooms[roomid-1]->changestatus(0);
                                customers[cusid-1]->checkout();
                            }
                            for(int x =0;x<10;x++){
                                if(restaurantcus[x]->getcusId()==customers[cusid-1]->getcusId()){
                                    restaurantcus[x]->checkout();
                                    delete restaurantcus[x];
                                }
                            }
                        }
                        else{
                            cout << "this customer has no booking"<< endl;
                        }
                    }
                    mainmenu();
                    break;
                }
                case 9:
                {   //case 9 will be used to search a customer.
                    ifstream inFile;
                    inFile.open("Dataimport.txt");
                    if (!inFile) {
                        cout << "Unable to open file";
                        mainmenu();
                    }
                    char x;
                    int added=0;
                    while (inFile >> x) {
                        int type;
                        float price;
                        inFile>>type;
                        inFile>>price;
                        rooms.push_back(importroom(type,price));
                        added+=1;
                    }
                
                    cout<< added <<" rooms added!";
                    mainmenu();
                    break;
                }
                case 10:
                {   //case 10 will be used as a data base. 
                    // it will store the room that are in the hotel with information
                    // such as it's type, price and if they are vacant or not.
                    ofstream myfile;
                    myfile.open ("Data.txt");
                    myfile << "Room Number:\tRoom type\tPrice\tStatus"<<endl;
                    for(int x = 0; x <rooms.size();x++){
                        myfile << rooms[x]->returnnoRoom() <<":\t";
                        myfile << rooms[x]->returnroomtype() <<"\t";
                        myfile << rooms[x]->returnprice() <<"\t";
                        myfile << rooms[x]->returnstatus() <<endl;
                    }
                    myfile.close();

                    ofstream ofs;
                    ofs.open("Dataimport.txt", std::ofstream::out | std::ofstream::trunc);
                    for(int x = 0; x <rooms.size();x++){
                        ofs << "a\n";
                        ofs << rooms[x]->returnroomtype() <<"\n";
                        ofs << rooms[x]->returnprice();
                        if(x!=rooms.size()-1){
                            ofs<<"\n";
                        }
                    }
                    ofs.close();
                    
                    mainmenu();
                    break;
                }
                case 11:
                {
                    int id;
                    cout<<"Search customer id:";
                    cin>>id;
                    if(!(customers.size()>id-1)){
                        cout<<"no this cus"<<endl;
                    }
                    else{
                        cout<<"Name: "<<customers[id-1]->getcusName()<<endl;
                        cout<<"Phone: "<<customers[id-1]->getcusPhone()<<endl;
                    }
                    mainmenu();
                    break;
                }
                case 12:
                {
                    cout<<endl<<endl<<endl<<"Adios!!"<<endl;
                    break;
                }
            }
        }

        
        void Hotel::changeinfo(){
            // this function will be used to change the information of the hotel.
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

        
        // this function will be used to seearch the room.
        void Hotel::searchroom(int no){
            cout<<"Room Number:"<<rooms[no]->returnnoRoom()<<endl;
            cout<<"Room Type:"<<rooms[no]->returnroomtype()<<endl;
            cout<<"Room Price:"<<rooms[no]->returnprice()<<endl;
            cout<<"Room Status:"<<rooms[no]->returnstatus()<<endl;
        }

        int Hotel::viewtotalbill(){};
        void Hotel::allocateroom(int roomid){};
        void Hotel::checkout(){};

        Hotel::~Hotel(){

        }
