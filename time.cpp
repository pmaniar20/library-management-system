#include<iostream>

using namespace std;

class Date{
    private:
        int days;
        int months;
        int years;
    public:
       Date(int d, int m, int y){
           days = d;
           months = m;
           years = y;
       }
       //~Date();

       int difference(Date d){
           int monthDays[13]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
           if(years==d.years){
                if(months==d.months) return days-d.days;
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

int main(){
    Date d1(1,01,2021);
    Date d2(28,02,2022);
    cout<<d2.difference(d1)<<endl;
    return 0;
}