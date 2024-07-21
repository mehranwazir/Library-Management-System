#ifndef DATE_H_
#define DATE_H_

#include "iostream"
using namespace std;


class Date
{
public:

	int day;
	int month;
	int year;

	Date(int d=0,int m=0, int y=0): day(d),month(m),year(y)	{}

	 Date addDays(int numDays) const {
	        int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	        int newDay = day + numDays;
	        int newMonth = month;
	        int newYear = year;

	        while (newDay > daysInMonth[newMonth-1]) {
	            newDay -= daysInMonth[newMonth-1];
	            if (++newMonth > 12) {
	                newMonth = 1;
	                newYear++;
	            }
	        }

	        Date temp(newDay,newMonth,newYear);
	        return temp;
	    }




//	 Date operator=( Date* d)
//	 {
//		 this->day = d->day;
//		 this->month = d->month;
//		 this->year = d->year;
//		 return *this;
//	 }

};




#endif /* DATE_H_ */
