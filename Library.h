
#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "Book.h"
#include "Librarian.h"
#include "LibraryCard.h"
class Library
{
public:

	Library()
	{
      librarycard = nullptr;
      book = nullptr;
      librarian = nullptr;
      number_of_members = 0;
	}
	 Book* getBook() const {
		return book;
	}

	void setBook( Book *book) {
		this->book = book;
	}

	void setLibrarian(Librarian *librarian)
	{
		this->librarian = librarian;
	}

	void operator=(const LibraryCard &rhs)
	{
		this->librarycard->setMember(rhs.getMember());
		this->librarycard->setIssuaceLimit(rhs.getIssuanceLimit());
		this->librarycard->setNumIssued(rhs.getNumIssued());
		this->librarycard->setBook(rhs.getBook());
	}

	void AddMember(const LibraryCard &member)
	{
		if(this->librarycard!=nullptr)
			{
		     LibraryCard *temp = new LibraryCard[number_of_members];

		     for(int i=0; i<number_of_members; i++)
		     temp[i] = this->librarycard[i];

		     delete [] this->librarycard;
		     this->librarycard = nullptr;

		     number_of_members++;
		     this->librarycard = new LibraryCard[number_of_members];

		     for(int i=0; i<number_of_members-1; i++)
		    	 this->librarycard[i] = temp[i];

			this->librarycard[number_of_members-1] = member;

			delete [] temp;
			temp = nullptr;

			}

		else
		{
			number_of_members++;
			this->librarycard = new LibraryCard[number_of_members];
			this->librarycard[0] = member;
		}
	}

	int getNumberofMembers()const
	{
		return number_of_members;
	}
    Librarian *librarian;
    LibraryCard *librarycard;
private:
	string name;
	Book *book;
    int number_of_members;
};



#endif /* LIBRARY_H_ */
