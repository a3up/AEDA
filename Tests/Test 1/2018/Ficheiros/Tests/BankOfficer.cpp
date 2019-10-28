/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"

unsigned int BankOfficer::last_id = 0;

BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}

// ----------------------------------------------------------------------------------------------

BankOfficer::BankOfficer(string name) {
    this->name = name;
    id = ++last_id;
}



