#include "LibraryCard.h"

LibraryCard::LibraryCard(LibraryMember *member,int maxIssuance): member(member),IssuanceLimit(maxIssuance),numIssued(0),book(nullptr){}


void LibraryCard::issueBook(const Book &book)
{
	if(this->book!=nullptr && numIssued <= IssuanceLimit)
		{
	     Book *temp = new Book[numIssued];

	     for(int i=0; i<numIssued; i++)
	     temp[i] = this->book[i];

	     delete [] this->book;
	     this->book = nullptr;

	     numIssued++;
	     this->book = new Book[numIssued];

	     for(int i=0; i<numIssued-1; i++)
	    	 this->book[i] = temp[i];

		this->book[numIssued-1] = book;

		delete [] temp;
		temp = nullptr;

		}
	else if(this->book == nullptr)
	{
		numIssued++;
		this->book = new Book[numIssued];
		this->book[0] = book;
	}

	else
	{
		cout<<"Your issuance limit is reached. You can't issue any more books."<<endl;
	}

}

void LibraryCard::returnBook(const Book& book)
{
	for(int i=0; i<numIssued; i++)
		if(this->book[i].getId() == book.getId() && i<=numIssued-1)
			{
			for(int j=i; j<numIssued-1; j++)
			this->book[i] = this->book[i+1];
			}

	numIssued--;

}

LibraryMember* LibraryCard::getMember()const
{
	return member;
}

void LibraryCard::setMember(LibraryMember* member)
{
	this->member = member;
}
int LibraryCard::getNumIssued()const
{
	return numIssued;
}

int LibraryCard::getIssuanceLimit()const
{
	return IssuanceLimit;
}
void LibraryCard::setIssuaceLimit(int limit)
{
	IssuanceLimit = limit;
}
void LibraryCard::setNumIssued(int num)
{
	numIssued = num;
}

Book* LibraryCard::getBook()const
{
	return book;
}

void LibraryCard::setBook(Book *book)
{
this->book = book;
}

void LibraryCard::returnDate()
{
	for(int i=0; i<numIssued; i++)
	{
		book[i].getReturnDate(IssuanceLimit, i);
	}

}

bool LibraryCard::getFine()const{

	return fine;
}

void LibraryCard::setFine(bool fine)
{
	this->fine = fine;
}
