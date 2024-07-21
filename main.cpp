
#include "Library.h"
#include "Librarian.h"
#include "Book.h"
#include "LibraryCard.h"
#include "LibraryMember.h"
#include "Date.h"




#include <iostream>
using namespace std;

class Library;

int main()
{

	Library library;

	while(true)
	{
	  cout<<"1. Create a Librarian."<<endl;
      cout<<"2. Login"<<endl;
	  cout<<"3. Exit."<<endl;

	  int choice;
	  cout<<"Enter your choice: ";
	  cin>>choice;

	 if(choice == 1)
	 {
		  string name;
		  string password;
          cout<<"Enter the Username of the librarian: ";
          cin>>name;

          cout<<"Enter Password for the librarian: ";
          cin>>password;
          Librarian *librarian = new Librarian(name,password);
          library.setLibrarian(librarian);
	 }

	 else if(choice ==2)
	 {
         string name;
         string password;
         cout<<"Enter the User name of the librarian: ";
         cin>>name;
         cout<<"Enter Password for the librarian: ";
         cin>>password;

         if(library.librarian->login(name,password))
         {
        	 while(true)
        	 {

        		 cout<<"1. Add Book"<<endl;
        		 cout<<"2. Search Book"<<endl;
        		 cout<<"3. Issue Book"<<endl;
        		 cout<<"4. Receive Book"<<endl;
                 cout<<"5. Become a Member"<<endl;
                 cout<<"6. Display the book issued "<<endl;
                 cout<<"7. Display Return Date "<<endl;
                 cout<<"8. Display Fine "<<endl;
                 cout<<"9. Exit "<<endl;

        	     int choice;
        		 cout<<"Enter your choice: ";
        	     cin>>choice;

        	     if(choice == 1)
        	     {
        	    	 string id;
                    cout<<"Enter ID: ";
                    cin>>id;

                    string name;
                    cout<<"Enter name of the Book: ";
                    cin>>name;

                    string author;
                    cout<<"Enter the author: ";
                    cin>>author;

                    int edition;
                    cout<<"Enter edition: ";
                    cin>>edition;

                    string date;
                    cout<<"Enter purchase date: ";
                    cin>>date;

                    cout<<"Is it a: \n a. Study Book\n b. Journal\n c. Magazine\n";

                    char select;
                    cout<<"Enter your choice: ";
                    cin>>select;


                    if(select == 'a')
                    {
                    StudyBook book(id,name,author,edition,date);
                    library.librarian->addBook(book);
                    }

                    else if(select == 'b')
                    {
                    Journal journal(id,name,author,edition,date);
                    library.librarian->addBook(journal);
                    }

                    else if(select == 'c')
                    {
                    Magazine magazine(id,name,author,edition,date);
                    library.librarian->addBook(magazine);
                    }





        	     }

        	     else if(choice== 2)
        	     {
        	    	 string id;
                     cout<<"Enter the id of the book you want to search for: ";
                     cin>>id;

                    if(library.librarian->SearchBook(id))
                    	{
                    	cout<<"Book found."<<endl;
                    	int bookindex = library.librarian->returnBookIndex(id);
                    	cout<<library.librarian->book[bookindex];

                    	}

                    else
                    	cout<<"Book not found."<<endl;

        	     }


        	     else if(choice == 3)
        	     {


        	    	if(library.librarycard == nullptr)
        	    	{
        	    		cout<<"You are not a member. In order to issue a book you need to become a member."<<endl;
        	    		continue;
        	    	}

        	    	else
        	    	{   string id;
        	    		cout<<"Enter your own ID: ";
        	    		cin>>id;
        	    		bool mem = false;
        	    		for(int i=0; i<library.getNumberofMembers(); i++)
        	    			if(library.librarycard[i].getMember()->getId() == id)
        	    				{cout<<"You are a member."<<endl;
        	    	             mem = true;
        	    	             break;
        	    				}

        	    		if(!mem)
        	    			{
        	    			cout<<"You are not a member. In order to issue a book you need to become a member."<<endl;
        	    			continue;
        	    			}
        	    	}

                   cout<<"You want us to issue: "<<endl;
                   cout<<"a. Study Book\n b. Journal\n c. Magazine\n";

        	    	char select;
        	    	cout<<"Enter your choice: ";
        	    	cin>>select;

        	    	if(select == 'a')
        	    	{
        	    		string name;
        	    		cout<<"Enter your Name: ";
        	    		cin>>name;

        	    		string id;
        	    		cout<<"Enter the ID of Book: ";
        	    		cin>>id;



        	    		if(!library.librarian->book->isIsAvailable() || !library.librarian->SearchBook(id))
        	    		{
        	    			cout<<"Sorry. The book is not available."<<endl;
        	    			continue;
        	    			}

        	    		int d,m,y;
        	    		cout<<"Enter the Issue date: "<<endl;
        	    		cout<<"Enter the day: ";
        	    		cin>>d;
        	    		cout<<"Enter the month: ";
        	    		cin>>m;
        	    		cout<<"Enter the year: ";
        	    		cin>>y;


                        Date date(d,m,y);



                          for(int i=0; i<library.getNumberofMembers(); i++)
                          {
                        	  if(library.librarycard[i].getMember()->getName() == name)
                        	  {
                        		  int bookindex = library.librarian->returnBookIndex(id);

                        		  library.librarian->issueBook(library.librarycard[i], bookindex);
                                  library.librarian->book[library.librarycard->getNumIssued()-1].setIssueDate(date);
                                  library.librarycard[i].book[library.librarycard->getNumIssued()-1].setIssueDate(date);

                        	  }
                          }

        	    	}


        	    	else if(select ==  'b')
        	    	{
        	    		string name;
        	    		cout<<"Enter your Name: ";
           	    		cin>>name;

         	    		string id;
        	    		cout<<"Enter the ID of Journal: ";
          	    		cin>>id;

        	    		if(!library.librarian->book->isIsAvailable() || !library.librarian->SearchBook(id))
          	    		      {
          	    		        	cout<<"Sorry. The book is not available."<<endl;
          	    		        	continue;
          	         			}

          	    		int d,m,y;
        	    		cout<<"Enter the Issue date: "<<endl;
        	    		cout<<"Enter the day: ";
        	    		cin>>d;
        	    		cout<<"Enter the month: ";
        	    		cin>>m;
        	    		cout<<"Enter the year: ";
        	    		cin>>y;


                        Date date(d,m,y);



                              for(int i=0; i<library.getNumberofMembers(); i++)
        	                    {
        	    		         	  if(library.librarycard[i].getMember()->getName() == name)
        	    		             	  {
        	    		             		  int bookindex = library.librarian->returnBookIndex(id);

        	    		             		  library.librarian->issueBook(library.librarycard[i], bookindex);
        	    		             		  library.librarian->book[library.librarycard->getNumIssued()-1].setIssueDate(date);
        	                                  library.librarycard[i].book[library.librarycard->getNumIssued()-1].setIssueDate(date);

        	    		                        	  }
        	    		                          }


        	    	}
        	    	else if(select ==  'c')
        	    	        	    	{
        	    	        	    		string name;
        	    	        	    		cout<<"Enter your Name: ";
        	    	           	    		cin>>name;

        	    	         	    		string id;
        	    	        	    		cout<<"Enter the ID of Magazine: ";
        	    	          	    		cin>>id;

        	    	        	    		if(!library.librarian->book->isIsAvailable() || !library.librarian->SearchBook(id))
        	    	          	    		 {
        	    	          	    		 cout<<"Sorry. The book is not available."<<endl;
        	    	          	    		 continue;
        	    	          	    		 }

        	    	        	    		int d,m,y;
        	    	        	    		cout<<"Enter the Issue date: "<<endl;
        	    	        	    		cout<<"Enter the day: ";
        	    	        	    		cin>>d;
        	    	        	    		cout<<"Enter the month: ";
        	    	        	    		cin>>m;
        	    	        	    		cout<<"Enter the year: ";
        	    	        	    		cin>>y;


        	    	                        Date date(d,m,y);



        	    	                              for(int i=0; i<library.getNumberofMembers(); i++)
        	    	        	                    {
        	    	        	    		         	  if(library.librarycard[i].getMember()->getName() == name)
        	    	        	    		             	  {
        	    	        	    		             		  int bookindex = library.librarian->returnBookIndex(id);

        	    	        	    		             		  library.librarian->issueBook(library.librarycard[i], bookindex);
        	    	        	    		             		  library.librarian->book[library.librarycard->getNumIssued()-1].setIssueDate(date);
        	    	        	                                  library.librarycard[i].book[library.librarycard->getNumIssued()-1].setIssueDate(date);

        	    	        	    		                        	  }
        	    	        	    		                          }


        	    	        	    	}


            cout<<"Book Issued.."<<endl;

        	     }

        	     else if(choice == 4)
        	     {
        	       string name;
        	       cout<<"Enter Your Name: ";
        	       cin>>name;

        	       string id;
                   cout<<"Enter the ID of the Book you are returning: ";
                   cin>>id;

                   int d,m,y;
                   cout<<"Enter the return Date:\n ";
                   cout<<"Enter the day: ";
                   cin>>d;
                   cout<<"Enter the month: ";
                   cin>>m;
                   cout<<"Enter the year: ";
                   cin>>y;

                   Date date(d,m,y);

                   for(int i=0; i<library.getNumberofMembers(); i++)
	                    {
	    		         	  if(library.librarycard[i].getMember()->getName() == name)
	    		             	  {
	    		             		  int bookindex = library.librarian->returnBookIndex(id);
                                      library.librarian->fine(library.librarycard[i],date);
	    		             		  library.librarian->returnBook(library.librarycard[i], bookindex);

	    		                        	  }
	    		                          }


           cout<<"Book returned."<<endl;

        	     }


        	     else if(choice == 5)
        	     {
                    string id;
                    cout<<"Enter ID: ";
                    cin>>id;

                    string name;
                    cout<<"Enter name: ";
                    cin>>name;

                    string address;
                    cout<<"Enter address: ";
                    cin>>address;

                    string number;
                    cout<<"Enter Phone Number: ";
                    cin>>number;

                    bool isStudent;
                    cout<<"Enter 1 for student and 0 for faculty: ";
                    cin>>isStudent;

                    int issuanceLimit;
                    if(isStudent)
                    	issuanceLimit = 3;

                    else
                    	issuanceLimit = 5;

                  LibraryMember member(id, name, address, number,issuanceLimit, isStudent);
                  LibraryCard membership(&member, issuanceLimit);
                  library.AddMember(membership);

        	     }
        	     else if(choice == 6)
        	     {
        	    	 for(int i=0; i<library.librarian->bookcount();i++)
        	    	 {
        	    		 cout<< library.librarian->book[i];
        	    	 }


        	     }

        	     else if(choice == 7)
        	     {
        	    	 string name;
                     cout<<"Enter Your Name: ";
                     cin>>name;

                     for(int i=0; i<library.getNumberofMembers(); i++)
  	                    {
  	    		         	  if(library.librarycard[i].getMember()->getName() == name)
  	    		             	  {
  	    		         		    library.librarycard[i].returnDate();
  	    		                   break;
  	    		             	       }
  	    		                          }


        	     }
        	     else if(choice == 9)
        	    	 break;

        	     else if(choice == 8)
        	     {
        	    	 string name;
        	    	 cout<<"Enter the name: ";
        	    	 cin>>name;

        	    	 for(int i=0; i<library.getNumberofMembers(); i++)
        	    	 {

        	    	 if(library.librarycard[i].getMember()->getName() == name)
        	    	 {
        	    		 if(library.librarycard[i].getFine())
        	    		 {
        	    			 cout<<"There is fine on you for the book turned in late."<<endl;
        	    		     break;
        	    		 }
        	    		 else
        	    			 cout<<"There is no fine on you."<<endl;

        	    	 }

        	    	 }
        	     }


        	 }

         }

	 }

	 else if(choice == 3 )
		 break;

	}



}




