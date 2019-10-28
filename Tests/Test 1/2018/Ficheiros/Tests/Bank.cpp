/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}

// ----------------------------------------------------------------------------------------------

double Bank::getWithdraw(string cod1) const{
    double res = 0;
    for(auto acc : accounts)
        if(acc->getCodH() == cod1)
            res += acc->getWithdraw();
	return res;
}

vector<Account *> Bank::removeBankOfficer(string name){
	vector<Account *> res;
	auto it = bankOfficers.begin();
	while(it != bankOfficers.end()){
	    if(it->getName() == name){
            res = it->getAccounts();
            bankOfficers.erase(it);
	    }
	    it++;
	}
	return res;
}

// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    BankOfficer *bo= new BankOfficer();
    return *bo;
}


// a alterar
void Bank::sortAccounts() {
}

