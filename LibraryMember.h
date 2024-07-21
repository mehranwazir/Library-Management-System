#ifndef LIBRARYMEMBER_H_
#define LIBRARYMEMBER_H_

#include <iostream>
using namespace std;

class LibraryMember //User
{
private:
	string ID;
	string Name;
	string Address;
	string phoneNumber;
	int IssuanceLimit;
	bool isStudent;
public:
	LibraryMember(string id, string name, string address, string phoneNumber, int maxIssuance, bool isStudent);
    string getAddress() const;
	void setAddress(const string &address);
	string getId() const;
	void setId(const string &id);
	bool getIsStudent() const;
	void setIsStudent(bool isStudent);
	int getIssuanceLimit() const;
	void setIssuanceLimit(int issuanceLimit);
	string getName() const;
	void setName(const string &name);
	string getPhoneNumber() const;
	void setPhoneNumber(const string &phoneNumber);
};

class Student:public LibraryMember
{
public:
	Student(string id, string name, string address, string phoneNumber, int maxIssuance, bool isStudent);
};

class Faculty: public LibraryMember
{
public:
	Faculty(string id, string name, string address, string phoneNumber, int maxIssuance, bool isStudent);
};

#endif
