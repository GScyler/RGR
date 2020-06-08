#pragma once
#include "Account.h"

class TelephoneDirectory
{
private:
	string Name;
	int Size;
	Account* TD;
public:
	TelephoneDirectory();
	TelephoneDirectory(string Name, int Size);
	~TelephoneDirectory();

	const string getName() const;
	void setName(const string Name);
	const int getSize() const;
	void setSize(const int Size);

	TelephoneDirectory& operator=(const TelephoneDirectory& t);

	void print();
	void insert();
	void edit();
	void del();
	void clearing();
	void search();
	void fout();
	void fin();
};

