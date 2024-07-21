#include "Book.h"

Book::Book(string id, string name, string author, int edition, string purchaseDate, bool isAvailable): id(id), name(name),author(author),edition(edition), purchaseDate(purchaseDate),isAvailable(isAvailable),issueDate(nullptr),returnDate(){}

string Book::getAuthor() const {
		return author;
	}

void Book::setAuthor(const string &author) {
		this->author = author;
	}

int Book::getEdition() const {
		return edition;
	}

void Book::setEdition(int edition) {
		this->edition = edition;
	}

string Book::getId() const {
		return id;
	}

void Book::setId(const string &id) {
		this->id = id;
	}

bool Book::isIsAvailable() const {
		return isAvailable;
	}

void Book::setIsAvailable(bool isAvailable) {
		this->isAvailable = isAvailable;
	}

string Book::getName() const {
		return name;
	}

void Book::setName(const string &name) {
		this->name = name;
	}

string Book::getPurchaseDate() const {
		return purchaseDate;
	}


void Book::setIssueDate(const Date &date)
{

	issueDate = new Date(date.day,date.month,date.year);

}

Date* Book::getIssueDate()const
{
  return issueDate;
}

void Book::setReturnDate(const Date &date)
{
	returnDate = date;
}

void Book::getReturnDate(int limit, int i)
{
    if (limit == 3)
	returnDate = issueDate->addDays(15);

    else if(limit == 5)
    	returnDate = issueDate->addDays(60);

	cout<<"Return Date of Book "<<i+1<<" :  "<< returnDate.day<<"/"<<returnDate.month<<"/"<<returnDate.year<<endl;
}

void Book::setPurchaseDate(const string &purchaseDate) {
		this->purchaseDate = purchaseDate;
	}


StudyBook::StudyBook(string id, string name, string author, int edition, string purchaseDate, bool isAvailable): Book(id,name,author,edition,purchaseDate,isAvailable){}

Magazine::Magazine(string id, string name, string author, int edition, string purchaseDate, bool isAvailable): Book(id,name,author,edition,purchaseDate,isAvailable){}

Journal::Journal(string id, string name, string author, int edition, string purchaseDate, bool isAvailable): Book(id,name,author,edition,purchaseDate,isAvailable){}


ostream& operator<<(ostream&out, Book &book)
{
		out<<"Book ID: "<<book.id<<endl;
		out<<"Name of Book: "<<book.name<<endl;
		out<<"Name of author: "<<book.author<<endl;
		out<<"edition: "<<book.edition<<endl;
		out<<"Purchase date: "<<book.purchaseDate<<endl;
		out<<"Is available: "<<book.isAvailable<<endl;

		return out;

}
