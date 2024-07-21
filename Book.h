#ifndef BOOK_H_
#define BOOK_H_

#include<iostream>
#include "Date.h"
using namespace std;

class Book
{
protected:
	string id;
	string name;
	string author;
	int edition;
	string purchaseDate;
	bool isAvailable;
    Date *issueDate;
    Date returnDate;
public:
	 Book(string id="", string name="", string author="", int edition=0, string purchaseDate="", bool isAvailable=1);
	 string getAuthor() const;

	void setAuthor(const string &author);

	int getEdition() const;

	void setEdition(int edition);

	string getId() const;

	void setId(const string &id);

	bool isIsAvailable() const;

	void setIsAvailable(bool isAvailable);

	string getName() const;

	void setName(const string &name);

	string getPurchaseDate() const;

	void setPurchaseDate(const string &purchaseDate);

	void setIssueDate(const Date &date);
	Date* getIssueDate()const;
    void setReturnDate(const Date &date);
    void getReturnDate(int limit, int i);

	friend ostream& operator<<(ostream&out, Book &book);
};



class StudyBook : public Book {
public:
    StudyBook(string id, string name, string author, int edition, string purchaseDate, bool isAvailable=1);
};

class Journal : public Book {
public:
    Journal(string id, string name, string author, int edition, string purchaseDate, bool isAvailable=1);
};

class Magazine : public Book {
public:
    Magazine(string id, string name, string author, int edition, string purchaseDate, bool isAvailable=1);
};

#endif
