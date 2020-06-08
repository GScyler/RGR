#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class Account
{
private:
	string Name;
	string Surname;
	string Number;
public:
	Account();
	const string getName() const;
	void setName(const string Name);
	const string getSurname() const;
	void setSurname(const string Surname);
	const string getNumber() const;
	void setNumber(const string Number);
	void print();
};

