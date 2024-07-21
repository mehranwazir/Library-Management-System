#include "Librarian.h"
#include <iostream>

Librarian::Librarian(string username, string password): username(username),password(password),book_count(0),book(nullptr){}

bool Librarian::login(string username, string password)
{
 if (this->username == username && this->password == password)
 {
	 cout<<"Successfully logged in."<<endl;
	 return true;
 }

 cout<<"Login details do not match. Enter again."<<endl;
 return false;
}

void Librarian::addBook(const Book &book)
{
	if(this->book!=nullptr)
	{
     Book *temp = new Book[book_count];

     for(int i=0; i<book_count; i++)
     temp[i] = this->book[i];

     delete [] this->book;
     this->book = nullptr;

     book_count++;
     this->book = new Book[book_count];

     for(int i=0; i<book_count-1; i++)
    	 this->book[i] = temp[i];

	this->book[book_count-1] = book;

	delete [] temp;
	temp = nullptr;

	}

	else
	{
	book_count++;
	this->book = new Book[book_count];
	this->book[0] = book;
	}
}

bool Librarian::SearchBook(string id)
{
  for(int i=0; i<book_count; i++)
	  if(this->book[i].getId() == id)
		  return true;

  return false;

}

int Librarian::returnBookIndex(string id)const
{
	  for(int i=0; i<book_count; i++)
		  if(this->book[i].getId() == id)
			  return i;

		  return 1;
}


void Librarian::issueBook(LibraryCard &membership, int index)
{

   membership.issueBook(book[index]);
   book[index].setIsAvailable(0);
}

void Librarian::returnBook(LibraryCard &membership, int index)
{
	membership.returnBook(book[index]);
	book[index].setIsAvailable(1);

}

int Librarian::daysBetween(Date *d1, const Date& d2) {
	     const int DAYS_PER_MONTH[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	     int days = 0;
	     if (d1->year == d2.year) {
	         if (d1->month == d2.month) {
	             days = d2.day - d1->day;
	         } else {
	             days = DAYS_PER_MONTH[d1->month-1] - d1->day;
	             for (int i = d1->month; i < d2.month - 1; i++) {
	                 days += DAYS_PER_MONTH[i];
	             }
	             days += d2.day;
	         }
	     } else {
	         days += DAYS_PER_MONTH[d1->month-1] - d1->day;
	         for (int i = d1->month; i < 12; i++) {
	             days += DAYS_PER_MONTH[i];
	         }
	         for (int i = d1->year + 1; i < d2.year; i++) {
	             if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
	                 days += 366;
	             } else {
	                 days += 365;
	             }
	         }
	         for (int i = 0; i < d2.month - 1; i++) {
	             days += DAYS_PER_MONTH[i];
	         }
	         days += d2.day;
	     }
	     return days;
	 }


void Librarian::fine(LibraryCard &membership, Date &d)
{
    for(int i=0; i<membership.getNumIssued(); i++)
	{
    	int days = daysBetween(membership.book[i].getIssueDate(),d);

    	 if(membership.getMember()->getIsStudent() && days>= 15)
    		 membership.setFine(1);

    	 else if(!membership.getMember()->getIsStudent()  && days>=60)
    		 membership.setFine(1);

	}

}


