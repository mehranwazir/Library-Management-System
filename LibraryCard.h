#ifndef LIBRARYCARD_H_
#define LIBRARYCARD_H_

#include "LibraryMember.h"
#include "Book.h"

class LibraryCard
{
private:
	LibraryMember *member;
	int IssuanceLimit;
	int numIssued;
    bool fine;
public:
	Book *book;
	//LibraryCard(string id, string name, string address, string phoneNumber, int maxIssuance, bool isStudent)
    LibraryCard(LibraryMember *member=nullptr, int maxIssuance=0);
    void issueBook(const Book &book);
    void returnBook(const Book &book);
    void returnDate();
    LibraryMember* getMember()const;
    void setMember(LibraryMember *member);
    int getIssuanceLimit()const;
    void setIssuaceLimit(int limit);
    int getNumIssued()const;
    void setNumIssued(int numIssued);
    void setBook(Book *book);
    Book* getBook()const;
    void setFine(bool fine);
    bool getFine()const;

};



#endif /* LIBRARYCARD_H_ */
