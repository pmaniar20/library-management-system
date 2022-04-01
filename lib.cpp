// /*
// library managment system
// This is done by Parth Maniar 200671
// */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
//#include "lbm.hpp"
using namespace std;

class users{
    public:
        string name;
        string password;
        string id;
        int type; // type: 0 for professor, 1 for user, 2 for librarian;
        vector<string> issued_books;
        // int fine_calculator(int date_issued, int date_returned, int fine_per_day, int type){
        //     int fine = 0;
        //     if(type==0){
        //         if(date_returned - date_issued > 60){
        //             fine = (date_returned - date_issued - 60)*5;
        //        }

        //     }
        //     if(type==1){
        //         if(date_returned - date_issued > 30){
        //             fine = (date_returned-date_issued-30)*2;
        //        }
        //     return fine;
        // } 
};

class book{
    public:
        string name;
        string author;
        string ISBN;
        string publication;

        bool issued=false;
        users issued_by=users();
        int issued_date;
};


vector<users> list_of_users;
vector<book> list_of_books;

/*vector<Student> list_of_students;
vector<professor> list_of_professors;
vector<librarian> list_of_librarians;*/

class book_database{
    public:
        void add_book(){
            book new_book;
            cout<<"Enter the name of the book: ";
            cin>>new_book.name;
            cout<<"Enter the author of the book: ";
            cin>>new_book.author;
            cout<<"Enter the ISBN of the book: ";
            cin>>new_book.ISBN;
            cout<<"Enter the publication of the book: ";
            cin>>new_book.publication;
            new_book.issued=false;
            //new_book.issued_by=;
            new_book.issued_date=0;
            list_of_books.push_back(new_book);
        }
        void search_book(){
            string search_book;
            cout<<"Enter the name of the book you want to search: ";
            cin>>search_book;
            for(int i=0; i<list_of_books.size(); i++){
                if(list_of_books[i].name == search_book){
                    cout << "Book found!" << endl;
                    cout << "Name: " << list_of_books[i].name << endl;
                    cout << "Author: " << list_of_books[i].author << endl;
                    cout << "ISBN: " << list_of_books[i].ISBN << endl;
                    cout << "Publication: " << list_of_books[i].publication << endl;
                    cout << "Issued: " << list_of_books[i].issued << endl;
                    if(list_of_books[i].issued == true){
                        cout << "Issued by: " << list_of_books[i].issued_by.name << endl;
                    }
                    return;
                }
            }
            cout << "Book not found!" << endl;
        }
        void delete_book(){
            string delete_book_name;
            cout<<"Enter the name of the book you want to delete: ";
            cin>>delete_book_name;
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
           cout<<"Which Feild you want to update"<<endl;
            cout<<"1. Name"<<endl;
            cout<<"2. Author"<<endl;
            cout<<"3. ISBN"<<endl;
            cout<<"4. Publication"<<endl;
            cout<<"5. Issued"<<endl;
            
            cout<<"Enter your choice: ";
            int choice;
            cin>>choice;

            if(choice==1){
                    string delete_book_name;
                    cout<<"Enter the name of the book you want to search: ";
                    cin>>delete_book_name;
                    string new_name;
                    cout<<"Enter the new name: ";
                    cin>>new_name;
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].name = new_name;
                            cout << "Book updated!" << endl;
                        }
                    }
                    cout << "Book not found!" << endl;
            }
            if(choice==2){
                    string delete_book_name;
                    cout<<"Enter the name of the book you want to search: ";
                    cin>>delete_book_name;
                    
                    string new_author;
                    cout<<"Enter the new author: ";
                    cin>>new_author;
                    
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
                    cout<<"Enter the name of the book you want to search: ";
                    cin>>delete_book_name;
                    
                    string new_ISBN;
                    cout<<"Enter the new ISBN: ";
                    cin>>new_ISBN;
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].ISBN = new_ISBN;
                            cout << "Book updated!" << endl;
                            return;
                        }
                    }
                    cout << "Book not found!" << endl;
            }
            if(choice==4){
                    string delete_book_name;
                    cout<<"Enter the name of the book you want to search: ";
                    cin>>delete_book_name;
                    
                    string new_publication;
                    cout<<"Enter the new publication: ";
                    cin>>new_publication;
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].publication = new_publication;
                            cout << "Book updated!" << endl;
                            return;
                        }
                    }
                    cout << "Book not found!" << endl;
            }
            if(choice==5){
                    string delete_book_name;
                    cout<<"Enter the name of the book you want to search: ";
                    cin>>delete_book_name;
                    
                    bool new_issued;
                    cout<<"Enter the new issued: ";
                    cin>>new_issued;
                    
                    for(int i=0; i<list_of_books.size(); i++){
                        if(list_of_books[i].name == delete_book_name){
                            list_of_books[i].issued = new_issued;
                            cout << "Book updated!" << endl;
                            return;
                        }
                    }
                    cout << "Book not found!" << endl;
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
                    cout << "Issued by: " << list_of_books[i].issued_by.name << endl;
                }
                cout<<"----------------------------------------"<<endl;
            }
       }
       void issue_book(users user_obj){
            string issue_book_name;
            int date;
            cout<<"Today's Date: ";
            cin>>date;
            cout<<"Enter the name of the book user wants to issue: ";
            cin>>issue_book_name;

            for(int i=0; i<list_of_books.size(); i++){
                if(list_of_books[i].name == issue_book_name){
                    if(list_of_books[i].issued == true){
                        cout << "Book already issued!" << endl;
                        cout<<"Whether to issue another boook?(y/n): ";
                        char c;
                        cin>>c;
                        while(c=='y' || c=='Y' || c=='N' || c=='n'){
                            if(c=='y' || c=='Y'){
                                issue_book(user_obj);
                            }
                            else if(c=='n' || c=='N'){
                                return;
                            }
                        return;
                        }
                    }
                    else{
                        if(user_obj.type==1 && user_obj.issued_books.size()>5){
                            cout << "Student can't issue more than 5 books!" << endl;
                            return;
                        }
                        list_of_books[i].issued = true;
                        list_of_books[i].issued_by = user_obj;
                        list_of_books[i].issued_date = date;
                        user_obj.issued_books.push_back(list_of_books[i].name);
                        cout << "Book issued!" << endl;
                        return;
                    }
                }
            }
            cout << "Book not found!" << endl;
       }
       void return_book(users user_obj, int date){
            string return_book_name;
            cout<<"Enter the name of the book user wants to return: ";
            cin>>return_book_name;
            for(int i=0; i<list_of_books.size(); i++){
                if(list_of_books[i].name == return_book_name){
                    if(list_of_books[i].issued == false){
                        cout << "Book not issued!" << endl;
                        cout<<"Whether to return another book?(y/n): ";
                        char c;
                        cin>>c;
                        while(c=='y' || c=='Y' || c=='N' || c=='n'){
                            if(c=='y' || c=='Y'){
                                return_book(user_obj, date);
                            }
                            else if(c=='n' || c=='N'){
                                return;
                            }
                        return;
                        }
                    }
                    else{
                        list_of_books[i].issued = false;
                        //list_of_books[i].issued_by = use;
                        list_of_books[i].issued_date = 0;
                       // int element= find(user_obj.issued_books.begin(), user_obj.issued_books.end(), list_of_books[i].name)-user_obj.issued_books.begin();
                        //3user_obj.issued_books.erase(user_obj.issued_books.begin()+element);
                        cout << "Book returned!" << endl;
                        return;
                    }
                }
            }
            cout << "Book not found!" << endl;
       }
};

class user_database{     
    public:
        void add_user(){
            users new_user;
            cout << "Enter name: ";
            cin >> new_user.name;
            cout << "Enter password: ";
            cin >> new_user.password;
            cout << "Enter id: ";
            cin >> new_user.id;
            cout << "Enter type: ";
            cin >> new_user.type;
            list_of_users.push_back(new_user);
            cout<<"User added!"<<endl;
            cout<<"Whether to add another user?(y/n): ";
            char c;
            cin>>c;
            while(c=='y' || c=='Y' || c=='N' || c=='n'){
                if(c=='y' || c=='Y'){
                    add_user();
                }
                else if(c=='n' || c=='N'){
                    return;
                }
                else{
                    cout<<"Invalid input!"<<endl;
                    cout<<"Whether to add another user?(y/n): ";
                    cin>>c;
                }
            }
        };
        void search_user(){
            cout<<"Enter name: ";
            string name;
            cin>>name;
            int j=0;
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].name == name){
                    j++;
                    cout<<j<<" User"<<endl;
                    cout<<"Name: "<<list_of_users[i].name<<endl;
                    cout<<"Id: "<<list_of_users[i].id<<endl;
                    cout<<"Type: "<<list_of_users[i].type<<endl;
                    cout<<"----------------------------------------"<<endl;
                }
            }
            if(j==0) cout<<"User not found"<<endl;
            return;
        };
        void delete_user(){
            cout<<"Enter name: ";
            string name;
            cin>>name;
            cout<<"Enter id: ";
            string id;
            cin>>id;
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
            cout<<"Which Feild you want to update"<<endl;
            cout<<"1. Name"<<endl;
            cout<<"2. Password"<<endl;
            cout<<"3. Id"<<endl;
            cout<<"4. Type"<<endl;
            cout<<"Enter your choice: ";
            int choice;
            cin>>choice;
            
            if(choice==1){
                    cout<<"Enter name: ";
                    string name;
                    cin>>name;
                    cout<<"Enter id: ";
                    string id;
                    cin>>id;
                    cout<<"Enter type: ";
                    int type;
                    cin>>type;
                    for(int i=0; i<list_of_users.size(); i++){
                        if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                            cout<<"Enter new name: ";
                            cin>>list_of_users[i].name;
                            cout<<"User updated!"<<endl;
                            return;
                        }
                    }
                    cout<<"User not found!"<<endl;
            }
            if(choice==2){
                    cout<<"Enter name: ";
                    string name;
                    cin>>name;
                    cout<<"Enter id: ";
                    string id;
                    cin>>id;
                    cout<<"Enter type: ";
                    int type;
                    cin>>type;
                    for(int i=0; i<list_of_users.size(); i++){
                        if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                            cout<<"Enter new password: ";
                            cin>>list_of_users[i].password;
                            cout<<"User updated!"<<endl;
                            return;
                        }
                    }
                    cout<<"User not found!"<<endl;
            }
            if(choice==3){
                    cout<<"Enter name: ";
                    string name;
                    cin>>name;
                    cout<<"Enter id: ";
                    string id;
                    cin>>id;
                    cout<<"Enter type: ";
                    int type;
                    cin>>type;
                    for(int i=0; i<list_of_users.size(); i++){
                        if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                            cout<<"Enter new id: ";
                            cin>>list_of_users[i].id;
                            cout<<"User updated!"<<endl;
                            return;
                        }
                    }
                    cout<<"User not found!"<<endl;
            }
            if(choice==4){
                    cout<<"Enter name: ";
                    string name;
                    cin>>name;
                    cout<<"Enter id: ";
                    string id;
                    cin>>id;
                    cout<<"Enter type: ";
                    int type;
                    cin>>type;
                    for(int i=0; i<list_of_users.size(); i++){
                        if(list_of_users[i].name == name && list_of_users[i].id == id && list_of_users[i].type == type){
                            cout<<"Enter type: ";
                            cin>>list_of_users[i].type;
                            cout<<"User updated!"<<endl;
                            return;
                        }
                    }
                    cout<<"User not found!"<<endl;
            }
            else cout<<"Invalid input!"<<endl;
                
        };
        void display_all_users(){
            for(int i=0; i<list_of_users.size(); i++){
                cout<<"Name: "<<list_of_users[i].name<<endl;
                cout<<"Password: "<<list_of_users[i].password<<endl;
                cout<<"Id: "<<list_of_users[i].id<<endl;
                cout<<"Type: "<<list_of_users[i].type<<endl;
            }
        };

}; 
user_database user_db;
book_database book_db;

class librarian: public users{
    private:
        string password;
        string id;
        string name;
        
    public:
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
};

class professor: public users{
    protected:
        users pr;
        int fine;
        vector<string> issued_books;
    public:
        // void search_book(){
        //     book_db.search_book();
        // };
        // void show_book(){
        //     book_db.show_books();
        // };
        int fine_calculator(int date_issued){
            int date_returned = date_issued+60;
            int fine = 0;
            if(date_returned - date_issued > 15){
                fine = (date_returned - date_issued - 15)*5;
            }
            return fine;
        };
};

class Student: public users{
    protected:
        users s;
        string name;
        string id;
        int fine;
        vector<string> issued_books;
    public:
        // void search_book(){
        //     book_db.search_book();
        // };
        // void show_book(){
        //     book_db.show_books();
        // };
        int fine_calculator(int date_issued){
            int date_returned = date_issued+30;
            int fine = 0;
            if(date_returned - date_issued > 15){
                fine = (date_returned - date_issued - 15)*2;
            }
            return fine;
        }
        void issue_book(){
            book_db.issue_book(s);
        };

};
void Librarianmenu(){
    librarian lib;
    cout<<"1. Add User"<<endl;
    cout<<"2. Search User"<<endl;
    cout<<"3. Delete User"<<endl;
    cout<<"4. Update User"<<endl;
    cout<<"5. Add Book"<<endl;
    cout<<"6. Search Book"<<endl;
    cout<<"7. Delete Book"<<endl;
    cout<<"8. Update Book"<<endl;
    cout<<"9. Logout"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            lib.add_user();
            break;
        case 2:
            lib.search_user();
            break;
        case 3:
            lib.delete_user();
            break;
        case 4:
            lib.update_user();
            break;
        case 5:
            lib.add_book();
            break;
        case 6:
            lib.search_book();
            break;
        case 7:
            lib.delete_book();
            break;
        case 8:
            lib.update_book();
            break;
        case 9:
            cout<<"Logged out!"<<endl;
            return;
            break;
        default:
            cout<<"Invalid input!"<<endl;
            break;
    }
    Librarianmenu();
}
void Studentmenu(users student){
    cout<<"1. Search Book"<<endl;
    cout<<"2. Show Books"<<endl;
    cout<<"3. Issue Book"<<endl;
    cout<<"4. Return Book"<<endl;
    cout<<"5. Check Fine"<<endl;
    cout<<"6. Logout"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            book_db.search_book();
            break;
        case 2:
            book_db.show_books();
            break;
        case 3:
            cout<<"Enter date issued: ";
            int date;
            book_db.issue_book(student);
            break;
        case 4:
            cout<<"Enter date returned: ";
            int date_returned;
            book_db.return_book(student, date_returned);
            break;
        case 5:
           //cout<<student.fine_calculator(date);
           break;
        case 6:
            cout<<"Logged out!"<<endl;
            return;
            break;
        default:
            cout<<"Invalid input!"<<endl;
    }
    Studentmenu(student);
}
void Profmenu(users prof){ 
    cout<<"1. Search Book"<<endl;
    cout<<"2. Show Books"<<endl;
    cout<<"3. Issue Book"<<endl;
    cout<<"4. Return Book"<<endl;
    cout<<"5. Check Fine"<<endl;
    cout<<"6. Logout"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            book_db.search_book();
            break;
        case 2:
            book_db.show_books();
            break;
        case 3:
            cout<<"Enter date in";
            int date;
            book_db.issue_book(prof);
            break;
        case 4:
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
    string user_id;
    string password;
    switch(choice){
        case 1:
            cout<<"Student"<<endl;
            cout<<"Please enter your user id: ";
            cin>>user_id;
            cout<<"password: ";
            cin>>password;
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].id == user_id && list_of_users[i].password == password && list_of_users[i].type == 1){
                    cout<<"Welcome "<<list_of_users[i].name<<endl;
                    cout<<"You have sucefully logged in!"<<endl;
                    Studentmenu(list_of_users[i]);
                }
            }
            break;
        case 2:
            cout<<"Professor"<<endl;
            cout<<"Please enter your id: ";
            cin>>user_id;
            cout<<"password: ";
            cin>>password;
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].id == user_id && list_of_users[i].password == password && list_of_users[i].type == 2){
                    cout<<"Logged in!"<<endl;
                    Profmenu(list_of_users[i]);
                }
            }
            break;
        case 3:
            
            cout<<"Librarian"<<endl;
            cout<<"Please enter your id: ";
            cin>>user_id;
            cout<<"password: ";
            cin>>password;
            for(int i=0; i<list_of_users.size(); i++){
                if(list_of_users[i].id == user_id && list_of_users[i].password == password && list_of_users[i].type == 3){
                    cout<<"Welcome "<<list_of_users[i].name<<endl;
                    cout<<"You have sucefully logged in!"<<endl;
                    Librarianmenu();
                }
            }
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
    lib.type = 3;
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
    p.type = 2;
    list_of_users.push_back(p);
}

int main(){
    add_librarian();
    add_test_student();
    add_test_professor();
	cout<<"LIBRARY MANAGEMENT SYSTEM"<<endl;
    menu();
    return 0;
}



