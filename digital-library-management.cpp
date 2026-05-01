#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <fstream> 
#include <ctime> 

using namespace std;
void issueBook(const string& bookName) {

    cout << "\nBook'" << bookName << "' issued successfully!\n";

    time_t now = time(nullptr);
    char* issueTime = ctime(&now);

    ofstream file("issued_books.txt", ios::app);
    if(file) {
        file << "Book Issued :" << bookName
             << "| Issued At: " << issueTime << '\n';
        file.close();
        cout << " Book issue recorded successfully.\n";
    } else {
        cout << " Error recording issue time.\n";
    }

}

class Library{
public:
    int id;
    char name[100];
    char author[100];
    char student[100];
    int price;
    int pages;
    bool isAvailable;
    Library() {
        isAvailable = true;
    }
};

int main(){
    Library lib[20];
    int input = 0;
    int count = 0;

    while(input!=4){
        cout << "\n==============================\n";
        cout<<"Enter 1 to input details like Id, Name, Author, Student, Price, Pages"<<endl;
        cout<<"Enter 2 to display details"<<endl;
        cout<<"Enter 3 search for a book"<<endl;
        cout<<"Enter 4 to quit"<<endl;
        cin>>input;
        cin.ignore();

        switch(input){
            case 1:
                start:
                cout<<"Enter Book Id"<<endl;
                cin>>lib[count].id;
                cin.ignore();

                cout<<"Enter Book Name"<<endl;
                //cin>>lib[count].name;
                cin.getline(lib[count].name, 100);
                cout<<"Enter Book Author"<<endl;
                //cin>>lib[count].author;
                cin.getline(lib[count].author, 100);
                cout<<"Enter Student Name"<<endl;
                //cin>>lib[count].student;
                cin.getline(lib[count].student, 100);
                cout<<"Enter Book Price"<<endl;
                cin>>lib[count].price;
                cout<<"Enter Book Pages"<<endl;
                cin>>lib[count].pages;

                int action;
                cout << "\nEnter 1 to issue this book, or 2 to buy it: ";
                cin >> action;
                cin.ignore();

                if (action == 1) {
                    issueBook(lib[count].name);
                    lib[count].isAvailable = false; 
                }
                else if (action == 2){
                    time_t now = time(nullptr);
                    char* buyTime = ctime(&now);

                    ofstream file ("purchased_books.txt", ios::app);
                    if(file) {
                        file << "Book Purchased " << lib[count].name
                             << "| Price: $" << lib[count].price
                             << "| Purchased At: " << buyTime << '\n';
                        file.close();
                        lib[count].isAvailable = false;
                        cout << " Book purchase recorded successfully.\n";
                    }else {
                        cout << "⚠️ Error recording purchase.\n";
                    }
                }
                else {
                    cout << "Invalid choice. Skipping action.\n";
                }

                count++;
                break;
            case 2:
                for(int i=0;i<count;i++){
                    cout<<"Book ID : "<<lib[i].id<<endl;
                    cout<<"Book Name : "<<lib[i].name<<endl;
                    cout<<"Book Author : "<<lib[i].author<<endl;
                    cout<<"Book Student : "<<lib[i].student<<endl;
                    cout<<"Book Price : "<<lib[i].price<<endl;
                    cout<<"Book Pages : "<<lib[i].pages<<endl;
                    cout<<"Status : "
                        << (lib[i].isAvailable ? "Available" : "❌ Not Available")
                        << endl;
                }
                break;

            case 3:
                 
                {
                    char searchName[100];
                    cout << "Enter Book Name to search: ";
                    cin.ignore();
                    cin.getline(searchName, 100);
                    bool found = false;

                    for(int i = 0; i < count; i++){
                        if(strcmp(lib[i].name, searchName) == 0) {
                            cout << "\n Book Found:\n";
                            cout << "Author: " << lib[i].author << endl;
                            cout << "Price: " << lib[i].price << endl;
                            cout << "Pages: " << lib[i].pages << endl;
                            cout << "Status: "
                                 << (lib[i].isAvailable ? "✅ Available" : "❌ Not Available") 
                                 << endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found) cout << "Book not found.\n";
                }
                break;

            case 4:
                cout << "\n📚 Exiting Library System. Thank you!\n"; // [ADDED EXIT MESSAGE]
                return 0;
                 

            default:
                cout<< "You have entered wrong value, please try again" << endl;
                break;
        }

    }

}