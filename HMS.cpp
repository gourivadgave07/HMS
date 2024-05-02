#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream> 
#define max 100
using namespace std;

// Class Customer
class Customer
{
public:
    char name[100];
    char address[100];
    char phone[12];
    char from_date[20];
    char to_date[20];
    char verification_type[20];
    float payment_advance;
};

class Room
{
protected:
    char stype;
    char ac;
   
public:
	int roomNumber;
	int status;
	int rent;
	int rno;
	 
    void displayRoom(Room);

    class Customer cust;
    class Room addRoom(int);
};

// Global Declarations
class Room rooms[max];
int count = 0;

Room Room::addRoom(int rno)
{
    class Room room;
    room.roomNumber = rno;
    
     ofstream outFile;
	 outFile.open("D:\\file.txt");
    cout << "\nType AC/Non-AC (A/N) : ";
    cin >> room.ac;
    cout << "\nType Size (B/S) : ";
    cin >> room.stype;
    cout << "\nDaily Rent : ";
    cin >> room.rent;
    room.status = 0;
    
     outFile<<room.roomNumber<<room.ac<<room.stype<<room.rent;
    outFile.close();

    cout << "\n Room Added Successfully!";
    getch();
    return room;
    
    
}

void Room::displayRoom(Room tempRoom)
{
	char str;
	ifstream infile;
	infile.open("D:\\file.txt");
	infile>>str;
    cout << "\nRoom Number: \t" << tempRoom.roomNumber;
    cout << "\nType AC/Non-AC (A/N) " << tempRoom.ac;
    cout << "\nType Size (B/S) " << tempRoom.stype;
    cout << "\nRent: " << tempRoom.rent;
    infile.close();
}

// hotel management class
class HotelMgnt : public Room
{
public:
    void checkIn();
    void checkOut(int);
    void getAvailRoom();
    void searchRoom(int rno);
};



// hotel management reservation of room
void HotelMgnt::checkIn()
{
	
    int i, found = 0, rno;
    
     ofstream outFile;
	 outFile.open("D:\\file.txt");

    class Room room;
    cout << "\nEnter Room number : ";
    cin >> rno;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].roomNumber == rno)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        if (rooms[i].status == 1)
        {
            cout << "\nRoom is already Booked";
            getch();
            return;
        }

        cout << "\nEnter Customer Name (First Name): ";
        cin >> rooms[i].cust.name;

        cout << "\nEnter Address (only city): ";
        cin >> rooms[i].cust.address;

        cout << "\nEnter Phone: ";
        cin >> rooms[i].cust.phone;

        cout << "\nEnter From Date: ";
        cin >> rooms[i].cust.from_date;

        cout << "\nEnter to  Date: ";
        cin >> rooms[i].cust.to_date;

        cout << "\nVerification type: ";
        cin >> rooms[i].cust.verification_type;

        cout << "\nEnter Advance Payment: ";
        cin >> rooms[i].cust.payment_advance;
        
        outFile<<cust.name<<cust.address<<cust.phone<<cust.from_date<<cust.to_date<<cust.verification_type<<cust.payment_advance;
   		outFile.close();

        rooms[i].status = 1;

        cout << "\n Customer Checked-in Successfully..";
        getch();
    }
}

// hotel managemt generates the bill of the expenses
void HotelMgnt::checkOut(int roomNum)
{
    int i, found = 0, days, rno;
    float billAmount = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "\nEnter Number of Days:\t";
        cin >> days;
        billAmount = days * rooms[i].rent;

        cout << "\n\t######## CheckOut Details ########\n";
        cout << "\nCustomer Name : " << rooms[i].cust.name;
        cout << "\nRoom Number : " << rooms[i].roomNumber;
        cout << "\nAddress : " << rooms[i].cust.address;
        cout << "\nPhone : " << rooms[i].cust.phone;
        cout << "\nTotal Amount Due : " << billAmount << " /";
        cout << "\nAdvance Paid: " << rooms[i].cust.payment_advance << " /";
        cout << "\n*** Total Payable: " << billAmount - rooms[i].cust.payment_advance << "/ only";

        rooms[i].status = 0;
    }
    getch();
}
// hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
    int i, found = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].status == 0)
        {
            displayRoom(rooms[i]);
            cout << "\n\nPress enter for next room";
            found = 1;
            getch();
        }
    }
    if (found == 0)
    {
        cout << "\nAll rooms are reserved";
        getch();
    }
}

void HotelMgnt::searchRoom(int rno)
{
    int i, found = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].roomNumber == rno)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "Room Details\n";
        if (rooms[i].status == 1)
        {
            cout << "\nRoom is Reserved";
        }
        else
        {
            cout << "\nRoom is available";
        }
        displayRoom(rooms[i]);
        getch();
    }
    else
    {
        cout << "\nRoom not found";
        getch();
    }
}

// managing rooms (adding and searching available rooms)
void addRooms()
{
    class Room room;
    int opt, rno, i, flag = 0;
    char ch;
   
        system("cls");
        cout << "\n1. Add Room";
      
            cout << "\nEnter Room Number: ";
            cin >> rno;
            i = 0;
            for (i = 0; i < count; i++)
            {
                if (rooms[i].roomNumber == rno)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                cout << "\nRoom Number is Present.\nPlease enter unique Number";
                flag = 0;
                getch();
            }
            else
            {
                rooms[count] = room.addRoom(rno);
                count++;
            }
            
}
using namespace std;
int main()
{
    class HotelMgnt hm;
    int i, j, opt, rno;
    char ch;
    char pname[100];

    system("cls");

    do
    {
        system("cls");
        cout << "HOTEL MANAGEMENT SYSTEM \n";
        cout << "\n1. Add Room";
        cout << "\n2. Check-In Room";
        cout << "\n3. Check-Out Room";
        cout << "\n4. Available Rooms";
        cout << "\n5. Search Rooms";
		cout << "\n6. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            addRooms();
            break;
        case 2:
            if (count == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                getch();
            }
            else
                hm.checkIn();
            break;
        case 3:
             if (count == 0)
            {
                cout << "\nRooms are not available.\nPlease add the rooms first.";
                getch();
            }
            else
            {
                cout << "Enter Room Number : ";
                cin >> rno;
                hm.checkOut(rno);
            }
            break;
            
        case 4:
          if (count == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                getch();
            }
            else
                hm.getAvailRoom();
            break;
            
        case 5:
        	 if (count == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                getch();
            }
            else
                hm.searchRoom(rno);
            break;
        	
        case 6:
            cout << "\nThank you for using this software";
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 6);

    getch();
}
