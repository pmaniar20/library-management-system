# CS253 Assignment 1
# library-management-system
# done by : Parth Maniar (200671)


This zip file contains this readme.md file and C++ code for library management system. 

To run the code, you need to compile it.

``` 
g++  lbm.cpp -o lbm
```


It will create a file named lbm.out. Then you can run the code by typing:

```
./lbm.out
```

During the execution, my code will add a test student, test professor, test librarian and 5 test book. 
```
Test Librarian
name : librarian 
id : iitklib
password : admin
type : 2

Test Student
name : Test Student
id : test
password : test
type : 1

Test Professor
name : Test Professor
id : testprof
password : test
type : 0
```

I have defined a User class 
```
class users{
    public:
        string name;
        string password;
        string id;
        int type; // 0 for professor, 1 for student, 2 for librarian
        users()
};

```
and its children class:

```
class librarian: public users{
    private:
        string id;
        string name;
        int type;
        
    public:
        librarian();

        void add_user();

        void search_user();

        void delete_user();

        void update_user();

        void add_book();

        void search_book();

        void delete_book();

        void update_book();

        void show_all_books();

        void show_all_users();
};

class professor: public users{
    protected:
        string name;
        string id;
        int type;
        int fine;
        
    public:
        professor();

        void search_book();

        void show_book();

        int check_fine();
        void clear_fine();

        void show_issued_book();
};

class Student: public users{
    protected:
        string name;
        string id;
        int fine;
        int type;

    public:
        Student();

        void search_book();

        void show_book();

        int check_fine();

        void clear_fine();

        void show_issued_book();

};
```

I made these dummy data to test my code. 
For database management:

I created two vectors to store the data:
```
1. list_of_users under user_database class : store all the users' data
2. list_of_books under book_database_class : store all the books' data
```

and two maps to store the data:
```
1. get_issued_books under book_database class : map user_id to a vector of books issued by that user
2. fine_map under fine_db class : map user_id to fine amount
```

I have also make sure that each user should have their **unique user_id**. **User class** has attribute *type* which distinguish what **type of user** it is.

```
type 0 is professor
type 1 is student
type 2 is librarian
```

For calculating difference between two dates I defined a seperate function under Date Class which give us the difference between two dates.
```
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

       int difference(Date d){
           int monthDays[13]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
           if(years==d.years){
                if(months==d.months){
                    return days-d.days;
                } 
                else if(months>d.months){
                     int diff=0;
                     for(int i=d.months;i<months;i++){
                          diff+=monthDays[i];
                     }
                    
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
```

Using this, I can calculate fine for each user accordingly and store in the* map fine_db* under *fine_db class*. I have also ensure that student user can only issue upto 5 books at a time.

I tried to maintain data of who has issued the book and who has returned the book everything is stored in *vector list_of_books* inside *book_database class*. I have also made sure that the book can be issued only once.









