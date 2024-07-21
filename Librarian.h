#ifndef LIBRARIAN_H_
#define LIBRARIAN_H_

#include "Book.h"
#include "LibraryCard.h"

class Librarian
{
private:
	string username;
	string password;
	int book_count;
public:
	Book *book;

	Librarian(string username = "",string password="");
	int bookcount() const
	{
		return book_count;
	}
	bool login(string username, string password);
	void addBook(const Book &book);
	bool SearchBook(string id);
	int returnBookIndex(string id)const;
	void issueBook(LibraryCard &membership, int i);
	void returnBook(LibraryCard &membership,int index);
	int daysBetween(Date *d1, const Date& d2);
	void fine(LibraryCard &membership, Date &d);


};





#endif /* LIBRARIAN_H_ */
