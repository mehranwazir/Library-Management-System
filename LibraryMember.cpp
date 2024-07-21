#include "LibraryMember.h"


LibraryMember::LibraryMember(string id, string name, string address, string phoneNumber, int IssuanceLimit, bool isStudent):ID(id),Name(name),Address(address),phoneNumber(phoneNumber),IssuanceLimit(IssuanceLimit),isStudent(isStudent){}


string LibraryMember::getAddress() const {
	return Address;
}

void LibraryMember::setAddress(const string &address) {
	Address = address;
}

string LibraryMember::getId() const {
	return ID;
}

void LibraryMember::setId(const string &id) {
	ID = id;
}

bool LibraryMember::getIsStudent() const {
	return isStudent;
}

void LibraryMember::setIsStudent(bool isStudent) {
	this->isStudent = isStudent;
}

int LibraryMember::getIssuanceLimit() const {
	return IssuanceLimit;
}

void LibraryMember::setIssuanceLimit(int issuanceLimit) {
	IssuanceLimit = issuanceLimit;
}

string LibraryMember::getName() const {
	return Name;
}

void LibraryMember::setName(const string &name) {
	Name = name;
}

string LibraryMember::getPhoneNumber() const {
	return phoneNumber;
}

void LibraryMember::setPhoneNumber(const string &phoneNumber) {
	this->phoneNumber = phoneNumber;
}


Student::Student(string id, string name, string address, string phoneNumber, int maxIssuance, bool isStudent): LibraryMember(id, name, address, phoneNumber, maxIssuance, isStudent ){}

Faculty::Faculty(string id, string name, string address, string phoneNumber, int maxIssuance, bool isStudent): LibraryMember(id, name, address, phoneNumber, maxIssuance, isStudent ){}
