// /*
// library managment system
// This is done by Parth Maniar 200671
// */
#include<map>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
//#include "lbm.hpp"
using namespace std;

class Date{
    private:
        int days;
        int months;
        int years;
    public:
        Date(void){
            days = 0;
            months = 0;
            years = 0;
        }
       Date(int d, int m, int y){
           days = d;
           months = m;
           years = y;
       }
       //~Date();

       int difference(Date d){
           int monthDays[13]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
           if(years==d.years){
              // cout<<"same year"<<endl;
                if(months==d.months){
                //    cout<<days<<endl;
                //    cout<<d.days<<endl;

                 //   cout<<"days-d.days"<<days-d.days<<endl;
                    return days-d.days;
                } 
                else if(months>d.months){
                     int diff=0;
                     for(int i=d.months;i<months;i++){
                          diff+=monthDays[i];
                     }
                    // cout<<diff+days-d.days<<endl;
                     return diff+days-d.days+1;
                }
              }
            else if(years>d.years){
                int diff=0;
                
                diff=365*(years-d.years);
                if(months==d.months) return diff+days-d.days+1;
                else if(months>d.months){
                     for(int i=d.months;i<months;i++){
                          diff+=monthDays[i];
                     }
                     return diff+days-d.days+1;
                }
              }
       
       }
};

map<string,vector<string>> mp;
map<string, int> fine_db;

class users{
    public:
        string name;
        string password;
        string id;
        int type; // type: 0 for professor, 1 for user, 2 for librarian;
        
        users(){
            name = "";
            password = "";
            id = "";
            type = NULL;
        };
};

class book{
    public:
        string name;
        string author;
        string ISBN;
        string publication;

        bool issued;
        string issued_by;
        Date issued_date;

        book(){
            name = "";
            author = "";
            ISBN = "";
            publication = "";
            issued = false;
            issued_by= "";
            issued_date=Date(0,0,0);
        }
};

vector<users> list_of_users;
vector<book> list_of_books;

string CurrentUser;

class book_database{
    public:
        void add_book(){
            //system("CLS");
            cout<<"Add Book Menu"<<endl;
            book new_book;
            cin.ignore();
            cout<<"Enter the name of the book: ";
            getline(cin, new_book.name);
            cout<<"Enter the author of the book: ";
            getline(cin, new_book.author);
            cout<<"Enter the ISBN of the book: ";
            getline(cin, new_book.ISBN);
            cout<<"Enter the publication of the book: ";
            getline(cin, new_book.publication);
            new_book.issued=false;
            //new_book.issued_by=;
            new_book.issued_date=Date(0,0,0);

            cout<<"Book added successfully!"<<endl;
            list_of_books.push_back(new_book);
        }
        void search_book(){
            //system("CLS");
            cout<<"Search Book Menu"<<endl;
            string search_book;
            cin.ignore();
            cout<<"Enter the name of the book you want to search: ";
            getline(cin, search_book);
            int flag=0;
            for(int i=0; i<list_of_books.size(); i++){
                if(list_of_books[i].name == search_book){
                    cout << "Book found!" << endl;
                    cout << "Name: " << list_of_books[i].name << endl;
                    cout << "Author: " << list_of_books[i].author << endl;
                    cout << "ISBN: " << list_of_books[i].ISBN << endl;
                    cout << "Publication: " << list_of_books[i].publication << endl;
                    cout << "Issued: " << list_of_books[i].issued << endl;
                    if(list_of_books[i].issued == true){
                        cout << "Issued by: " << list_of_books[i].issued_by << endl;
                    }
                    flag=1;
                }
            }
            if(flag==0) cout << "Book not found!" << endl;
        }
        void delete_book(){
            //system("CLS");
            cout<<"Delete Book Menu"<<endl;
            string delete_book_name;
            cin.ignore();
            cout<<"Enter the name of the book you want to delete: ";
            getline(cin, delete_book_name);
            for(int i=0; i<list_of_books.size(); i++){
                if(list_of_books[i].name == delete_book_name){
                    list_of_books.erase(list_of_books.begin()+i);
                    cout << "Book deleted!" << endl;
                    return;
                }
            }
            cout << "Book not found!" << endl;
        }
       void update_book(){
            //system("CLS");
            cout<<"Update Book Menu"<<endl;
            cout<<"Which Field you want to update"<<endl;
            cout<<"1. Name"<<endl;
            cout<<"2. Author"<<endl;
            cout<<"3. ISBN"<<endl;
            cout<<"4. Publication"<<endl;
            cout<<"5. Issued"<<endl;
            
            cout<<"Enter your choice: ";
            int choice;
            cin>>choice;
            cout<<endl;
            if(choice==1){
                    string delete_book_name;
                    cin.ignore();
                    cout<<"Enter the name of the book you want to update: ";
                    getline(cin, delete_book_name);
                    string new_name;
                    cout<<"Enter the new name: ";
                    getline(cin, new_name);
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].name = new_name;
                            cout << "Book updated!" << endl;
                            return;
                        }
                    }
                    cout << "Book not found!" << endl;
            }
            if(choice==2){
                    string delete_book_name;
                    cin.ignore();
                    cout<<"Enter the name of the book you want to update: ";
                    getline(cin, delete_book_name);
                    
                    string new_author;
                    cout<<"Enter the new author: ";
                    getline(cin, new_author);
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].author = new_author;
                            cout << "Book updated!" << endl;
                            return;
                        }
                    }
                    cout << "Book not found!" << endl;
            }
            if(choice==3){
                    string delete_book_name;
                    cin.ignore();
                    cout<<"Enter the name of the book you want to update: ";
                    getline(cin, delete_book_name);
                    
                    string new_ISBN;
                    cout<<"Enter the new ISBN: ";
                    getline(cin, new_ISBN);
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].ISBN = new_ISBN;
                            cout<<"Book updated!"<<endl;
                            return;
                        }
                    }
                    cout<<"Book not found!"<<endl;
            }
            if(choice==4){
                    string delete_book_name;
                    cin.ignore();
                    cout<<"Enter the name of the book you want to update: ";
                    getline(cin, delete_book_name);
                    
                    string new_publication;
                    cout<<"Enter the new publication: ";
                    getline(cin, new_publication);
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].publication = new_publication;
                            cout<<"Book updated!"<<endl;
                            return;
                        }
                    }
                    cout<<"Book not found!"<<endl;
            }
            if(choice==5){
                    string delete_book_name;
                    cin.ignore();
                    cout<<"Enter the name of the book you want to update: ";
                    getline(cin, delete_book_name);
                    
                    bool new_issued;
                    cout<<"Enter the new issued: ";
                    cin>>new_issued;
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].issued = new_issued;
                            cout<<"Book updated!"<<endl;
                            return;
                        }
                    }
                    cout<<"Book not found!"<<endl;
            }
       }
       void show_books(){
            for(int i=0; i<list_of_books.size(); i++){
                cout<<"Book Sr. No."<<i+1<<endl;
                cout << "Name: " << list_of_books[i].name << endl;
                cout << "Author: " << list_of_books[i].author << endl;
                cout << "ISBN: " << list_of_books[i].ISBN << endl;
                cout << "Publication: " << list_of_books[i].publication << endl;
                cout << "Issued: " << list_of_books[i].issued << endl;
                if(list_of_books[i].issued == true){
                    cout << "Issued by: " << list_of_books[i].issued_by << endl;
                }
                cout<<"----------------------------------------"<<endl;
            }
       }
       void issue_book(int type){
            string issue_book_name;
            int y, m, d;

            cout<<"Issue Date (year yyyy): ";
            cin>>y;
            cout<<"Issue Date (month mm): ";
            cin>>m;
            cout<<"Issue Date (day dd): ";
            cin>>d;
            
            Date issue_date(d, m, y);
            cin.ignore();
            cout<<"Enter the name of the book user wants to issue: ";
            getline(cin, issue_book_name);
            int flag=0;

            for(int i=0; i<list_of_books.size(); i++){
                if(list_of_books[i].name == issue_book_name){
                    int flag=1;
                    if(list_of_books[i].issued == true){
                        cout << "Book already issued!" << endl;
                    }
                    else{
                        cout<<type<<" "<<mp[CurrentUser].size()<<endl;
                        if(type==1 && mp[CurrentUser].size()>=5){
                            cout << "Student can't issue more than 5 books!" << endl;
                            return;
                        }
                        list_of_books[i].issued = true;
                        list_of_books[i].issued_by = CurrentUser;
                        list_of_books[i].issued_date = issue_date;
                        mp[CurrentUser].push_back(list_of_books[i].name);
                        cout << "Book issued!" << endl;
                        return;
                    }
                }
            }
            if(flag==0) cout << "Book not found! Try Again" << endl;
            return;
       }
       void return_book(int type){
            string return_book_name;
            cin.ignore();
            cout<<"Enter the name of the book user wants to return: ";
            getline(cin, return_book_name);

            for(int i=0; i<list_of_books.size(); i++){
                if(list_of_books[i].name == return_book_name){
                    if(list_of_books[i].issued == false){
                        cout << "Book not issued!" << endl;
                        return;
                    }
                    else{
                        int d, m, y;
                        cout<<"Return Date (year yyyy): ";
                        cin>>y;
                        cout<<"Return Date (month mm): ";
                        cin>>m;
                        cout<<"Return Date (day dd): ";
                        cin>>d;
                        Date return_date(d, m, y);
                        list_of_books[i].issued = false;
                        //list_of_books[i].issued_by = use;
                        int diff=return_date.difference(list_of_books[i].issued_date);
                        //cout<<diff<<endl;
                        if(type=1 && diff>30){
                            fine_db[CurrentUser] = (diff-30)*2;;
                        }

                        if(type=0 && return_date.difference(list_of_books[i].issued_date)>60){
                            fine_db[CurrentUser] = (diff-60)*5;
                        }
                        
                        list_of_books[i].issued_date = Date(0,0,0);
                        int it=0;
                        for(int j=0; j<mp[CurrentUser].size(); j++){
                            if(mp[CurrentUser][j] == list_of_books[i].name){
                                it = j;
                                break;
                            }
                        }
                        mp[CurrentUser].erase(mp[CurrentUser].begin()+it);
                        
                        cout << "Book returned!" << endl;
                        return;
                    }
                }
            }
            cout << "Book not found!"<< endl;
            return;
       }
};

class user_database{     
    public:
        void add_user(){
            cout<<"Add User Menu"<<endl;
            users new_user;
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, new_user.name);
            cout << "Enter password: ";
            getline(cin, new_user.password);
            cout << "Enter id: ";
            getline(cin, new_user.id);
            cout << "Enter role (type: 0 for professor, 1 for student, 2 for librarian): ";
            cin >> new_user.type;
            list_of_users.push_back(new_user);
            //system("CLS");
            cout<<"User added!"<<endl;
            
        };
        void search_user(){
            //system("CLS");
            cout<<"Search User Menu"<<endl;
            cout<<"Enter name: ";
            cin.ignore();
            string name;
            getline(cin, name);
            int j=0;
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].name == name){
                    j++;
                    cout<<j<<" User"<<endl;
                    cout<<"Name: "<<list_of_users[i].name<<endl;
                    cout<<"Id: "<<list_of_users[i].id<<endl;
                    cout<<"Role (0 for professor, 1 for user, 2 for librarian): "<<list_of_users[i].type<<endl;
                    cout<<"----------------------------------------"<<endl;
                }
            }
            if(j==0) cout<<"User not found"<<endl;
            //return;
        };
        void delete_user(){
            //system("CLS");
            cout<<"Delete User Menu"<<endl;
            cout<<"Enter name: ";
            cin.ignore();
            string name;
            getline(cin, name);
            cout<<"Enter user id: ";
            string id;
            getline(cin,id);
            cout<<"Enter type: ";
            int type;
            cin>>type;
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                    list_of_users.erase(list_of_users.begin()+i);
                    cout<<"User deleted!"<<endl;
                    return;
                }
            }
            cout<<"User not found!"<<endl;
        };
        void update_user(){
            //system("CLS");
            cout<<"Update User Menu"<<endl;
            cout<<"Which Field you want to update"<<endl;
            cout<<"1. Name"<<endl;
            cout<<"2. Password"<<endl;
            cout<<"3. Id"<<endl;
            cout<<"4. Type"<<endl;
            cout<<"Enter your choice: ";
            int choice;
            cin>>choice;
            cout<<endl;
            string name, password, id;
            int type;
            int flag=0;
            switch(choice){
            case 1:
                    cin.ignore();
                    cout<<"Enter name: ";
                    getline(cin, name);
                    cout<<"Enter id: ";
                    
                    getline(cin, id);
                    cout<<"Enter role (0 for professor, 1 for student, 2 for librarian): ";
                    
                    cin>>type;
                    for(int i=0; i<list_of_users.size(); i++){
                        if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                            cout<<"Enter new name: ";
                            cin>>list_of_users[i].name;
                            cout<<"User updated!"<<endl;
                            flag=1;
                            return;
                        }
                    }
                    if(flag==0) cout<<"User not found!"<<endl;
                    break;
            
            case 2:
                   // string name;
                    cin.ignore();
                    cout<<"Enter name: ";
                    getline(cin, name);
                    cout<<"Enter id: ";
                    //string id;
                    getline(cin, id);
                    cout<<"Enter type: ";
                    //int type;
                    cin>>type;
                    for(int i=0; i<list_of_users.size(); i++){
                        if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                            cout<<"Enter new password: ";
                            cin>>list_of_users[i].password;
                            cout<<"User updated!"<<endl;
                            flag=1;
                            return;
                        }
                    }
                    if(flag==0) cout<<"User not found!"<<endl;
                    break;
            case 3:
                    //string name;
                    cin.ignore();
                    cout<<"Enter name: ";
                    
                    getline(cin, name);
                    cout<<"Enter id: ";
                    //string id;
                    getline(cin, id);
                    cout<<"Enter role (0 for professor, 1 for student, 2 for librarian): ";
                    //int type;
                    cin>>type;
                    for(int i=0; i<list_of_users.size(); i++){
                        if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                            cout<<"Enter new id: ";
                            cin>>list_of_users[i].id;
                            cout<<"User updated!"<<endl;
                            flag=1;
                            return;
                        }
                    }
                    if(flag==0) cout<<"User not found!"<<endl;
                    break;
            case 4:
                    //string name;
                    cin.ignore();
                    cout<<"Enter name: ";
                    getline(cin, name);
                    cout<<"Enter id: ";
                    //string id;
                    getline(cin, id);
                    cout<<"Enter type: ";
                    //int type;
                    cin>>type;
                    for(int i=0; i<list_of_users.size(); i++){
                        if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                            cout<<"Enter type: ";
                            cin>>list_of_users[i].type;
                            cout<<"User updated!"<<endl;
                            flag=1;
                            return;
                        }
                    }
                    if(flag==0) cout<<"User not found!"<<endl;
                    break;
            default: 
                cout<<"Invalid input!"<<endl;
                break;
            }
            return;   
        };
        void display_all_users(){
            cout<<"Display All Users Menu"<<endl;
            for(int i=0; i<list_of_users.size(); i++){
                cout<<"Name: "<<list_of_users[i].name<<endl;
                cout<<"Password: "<<list_of_users[i].password<<endl;
                cout<<"Id: "<<list_of_users[i].id<<endl;
                cout<<"Role (0 for professor, 1 for user, 2 for librarian): "<<list_of_users[i].type<<endl;
            }
        };
        void display_issued_book(){
            cout<<"Display Issued Book Menu"<<endl;
            for(int i=0; i<mp[CurrentUser].size(); i++){
                cout<<"Book name: "<<mp[CurrentUser][i]<<endl;
            }
        }
}; 

user_database user_db;
book_database book_db;

class librarian: public users{
    private:
        string id;
        string name;
        int type;
        
    public:
        librarian(users l){
            id = l.id;
            name = l.name;
            type=2;
        }
        void add_user(){
            user_db.add_user();
        };
        void search_user(){
            user_db.search_user();
        };
        void delete_user(){
            user_db.delete_user();
        };
        void update_user(){
            user_db.update_user();
        };
        void add_book(){
            book_db.add_book();
        };
        void search_book(){
            book_db.search_book();
        };
        void delete_book(){
            book_db.delete_book();
        };
        void update_book(){
            book_db.update_book();
        };
        void show_all_books(){
            book_db.show_books();
        };
        void show_all_users(){
            user_db.display_all_users();
            cout<<"----------------------------------------"<<endl;
        };
};

class professor: public users{
    protected:
        string name;
        string id;
        int type;
        int fine;
        
    public:
        professor(users p){ 
            name = p.name;
            id = p.id;
            fine = fine_db[CurrentUser];
            type=0;
        }
        void search_book(){
            book_db.search_book();
        };
        void show_book(){
            book_db.show_books();
        };
         int check_fine(){
            return fine_db[id];
        }
        void clear_fine(){
            cout<<"Have you paid all dues (y/n)"<<endl;
            char c;
            cin>>c;

            if(c=='y' || c=='Y') fine_db[id]=0;
            else{
                cout<<"Yours dues are not cleared!"<<endl;
            }
        }

        void show_issued_book(){
            cout<<"Display Issued Book Menu"<<endl;
            for(int i=0; i<mp[id].size(); i++){
                cout<<"Book name: "<<mp[id][i]<<endl;
            }
        }
};

class Student: public users{
    protected:
        string name;
        string id;
        int fine;
        int type;

    public:
        Student(users s){
            name=s.name;
            id=s.id;
            fine=fine_db[CurrentUser];
            int type=1;
        }
        void search_book(){
            book_db.search_book();
        };
        void show_book(){
            book_db.show_books();
        };
        int check_fine(){
            return fine_db[id];
        }
        void clear_fine(){
            fine_db[id]=0;
        }

        void show_issued_book(){
            cout<<"Display Issued Book Menu"<<endl;
            cout<<name<<endl;
            for(int i=0; i<mp[id].size(); i++){
                cout<<"Book name: "<<mp[id][i]<<endl;
            }
        };

};
void Librarianmenu(librarian &lib){
    cout<<"1. Add User"<<endl;
    cout<<"2. Search User"<<endl;
    cout<<"3. Delete User"<<endl;
    cout<<"4. Update User"<<endl;
    cout<<"5. Show all users"<<endl;
    cout<<"6. Add Book"<<endl;
    cout<<"7. Search Book"<<endl;
    cout<<"8. Delete Book"<<endl;
    cout<<"9. Update Book"<<endl;
    cout<<"10. Show all Books"<<endl;
    cout<<"11. Logout"<<endl;
    
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 1:
            //system("CLS");
            lib.add_user();
            break;
        case 2:
            //system("CLS");
            lib.search_user();
            break;
        case 3:
            //system("CLS");
            lib.delete_user();
            break;
        case 4:
            //system("CLS");
            lib.update_user();
            break;
        case 5:
            //system("CLS");
            lib.show_all_users();
            break;
        case 6:
            //system("CLS");
            lib.add_book();
            break;
        case 7:
            //system("CLS");
            lib.search_book();
            break;
        case 8:
            //system("CLS");
            lib.delete_book();
            break;
        case 9:
            //system("CLS");
            lib.update_book();
            break;
        case 10:
            //system("CLS");
            lib.show_all_books();
            break;
        case 11:
            system("CLS");
            cout<<"Logged out!"<<endl;
            return;
            break;
        default:
            cout<<"Invalid input!"<<endl;
            break;
    }
    Librarianmenu(lib);
}
void Studentmenu(Student &student){
    //system("CLS");
    cout<<"1. Search Book"<<endl;
    cout<<"2. Show Books"<<endl;
    cout<<"3. Issue Book"<<endl;
    cout<<"4. Show Issued Books"<<endl;
    cout<<"5. Return Book"<<endl;
    cout<<"6. Check Fine"<<endl;
    cout<<"7. Clear fine"<<endl;
    cout<<"8. Logout"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 1:
            student.search_book();
            break;
        case 2:
            student.show_book();
            break;
        case 3:
            book_db.issue_book(1);
            break;
        case 4:
            student.show_issued_book();
            break;
        case 5:
            book_db.return_book(1);
            break;
        case 6:
           cout<<"Fine = "<<student.check_fine()<<endl;
           break;
        case 7:
            student.clear_fine();
            break;
        case 8:
            system("CLS");
            cout<<"Logged out!"<<endl;
            return;
            break;
        default:
            cout<<"Invalid input!"<<endl;
    }
    Studentmenu(student);
}
void Profmenu(professor &prof){ 
    //system("CLS");
    cout<<"1. Search Book"<<endl;
    cout<<"2. Show Books"<<endl;
    cout<<"3. Issue Book"<<endl;
    cout<<"4. Show issued books"<<endl;
    cout<<"5. Return Book"<<endl;
    cout<<"6. Check Fine"<<endl;
    cout<<"7. Clear Fine"<<endl;
    cout<<"8. Logout"<<endl;
    int choice;
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 1:
            prof.search_book();
            break;
        case 2:
            prof.show_book();
            break;
        case 3:
            book_db.issue_book(0);
            break;
        case 4:
            prof.show_issued_book();
            break;
       case 5:
            book_db.return_book(0);
            break;
        case 6:
           prof.check_fine();
           break;
        case 7:
            prof.clear_fine();
        case 8:
            system("CLS");
            cout<<"Logged out!"<<endl;
            return;
            break;
        default:
            cout<<"Invalid input!"<<endl;
    }
    Profmenu(prof);
}

void menu(){
    cout<<"Login as:"<<endl;
    cout<<"1. Student"<<endl;
    cout<<"2. Professor"<<endl;
    cout<<"3. Librarian"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";

    int choice;
    cin>>choice;
    cout<<endl;
    system("CLS");
    string user_id;
    string password;
    int flag=0;
    
    switch(choice){
        case 1:
            cout<<"Student"<<endl;
            cout<<"Please enter your user id: ";
            cin.ignore (); 
            getline(cin, user_id);

            cout<<"Password: ";
            getline(cin, password);
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].id==user_id && list_of_users[i].password==password && list_of_users[i].type==1){
                    cout<<"Welcome "<<list_of_users[i].name<<endl;
                    cout<<"You have sucefully logged in!"<<endl;
                    CurrentUser=user_id;
                    flag=1;
                    Student Std(list_of_users[i]);
                    Studentmenu(Std);
                }
            }
            if(flag==0) cout<<"Invalid user id or password!"<<endl;
            break;
        
        case 2:
            cout<<"Professor"<<endl;
            cout<<"Please enter your id: ";
            cin.ignore (); 
            getline(cin, user_id);
            cout<<"Password: ";
            getline(cin, password);
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].id==user_id && list_of_users[i].password==password && list_of_users[i].type==2){
                    cout<<"Logged in!"<<endl;
                    flag=1;
                    professor p(list_of_users[i]);
                    Profmenu(p);
                }
            }
            if(flag==0) cout<<"Invalid user id or password!"<<endl;
            break;
        
            
        case 3:
            cout<<"Librarian"<<endl;
            cout<<"Please enter your id: ";
            cin.ignore (); 
            getline(cin, user_id);
            cout<<"password: ";
            getline(cin, password);
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].id == user_id && list_of_users[i].password == password && list_of_users[i].type == 2){
                    cout<<"Welcome "<<list_of_users[i].name<<endl;
                    cout<<"You have sucefully logged in!"<<endl;
                    flag=1;
                    librarian l(list_of_users[i]);
                    Librarianmenu(l);
                }
            }
            if(flag==0) cout<<"Invalid user id or password!"<<endl;
            break;

        case 4:
            cout<<"Exit"<<endl;
            return;
            break;
        
        default:
            cout<<"Invalid input!"<<endl;
            break;
        } 
    menu();
}

void add_librarian(){
    users lib;
    lib.name = "Librarian";
    lib.id = "iitklib";
    lib.password = "admin";
    lib.type = 2;
    list_of_users.push_back(lib);
}
void add_test_student(){
    users s;
    s.name = "Test Student";
    s.id = "test";
    s.password = "test";
    s.type = 1;
    list_of_users.push_back(s);
}
void add_test_professor(){
    users p;
    p.name = "Test Professor";
    p.id = "testprof";
    p.password = "test";
    p.type = 0;
    list_of_users.push_back(p);
}

void add_test_books(){
    for(int i=1; i<=6; i++){
        book b;
        b.name = "Book"+to_string(i);
        b.author = "Author"+to_string(i);
        b.issued = 0;
        list_of_books.push_back(b);
    }
}

int main(){
    system("CLS");
    add_librarian();
    add_test_student();
    add_test_professor();
    add_test_books();
	cout<<"LIBRARY MANAGEMENT SYSTEM"<<endl;
    menu();
    return 0;
}



