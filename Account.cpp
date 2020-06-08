#include "Account.h"
Account::Account()
{
	Name = "None";
	Surname = "None";
	Number = "None";
}
const string Account::getName() const { return Name; }
void Account::setName(const string Name) { this->Name = Name; }
const string Account::getSurname() const { return Surname; }
void Account::setSurname(const string Surname) { this->Surname = Surname; }
const string Account::getNumber() const { return Number; }
void Account::setNumber(const string Number) { this->Number = Number; }

void Account::print()
{
	cout << Name << " " << Surname << " " << Number << endl;
}