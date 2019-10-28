/*
 * Bank.h
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include <vector>

#include "BankOfficer.h"

template <class T>
unsigned int numberDifferent (const vector<T> & v1){
    vector<T> diff;
    for(auto elem : v1){
        bool found = false;
        for(auto x : diff)
            if(elem == x)
                found = true;
        if(!found)
            diff.push_back(elem);
    }
    return diff.size();
}

class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();
};


#endif /* SRC_BANK_H_ */
