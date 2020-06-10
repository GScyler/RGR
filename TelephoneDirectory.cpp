#include "TelephoneDirectory.h"

TelephoneDirectory::TelephoneDirectory()
{
	Name = "Unnamed";
	Size = 0;
	TD = new Account[0];
}
TelephoneDirectory::TelephoneDirectory(string Name, int Size)
{
	this->Name = Name;
	this->Size = Size;
	TD = new Account[Size];
}
TelephoneDirectory::~TelephoneDirectory()
{
	delete[] TD;
	cout << "Telephone directory \"" << Name << "\" was deleted" << endl;
}
const string TelephoneDirectory::getName() const { return Name; }
void TelephoneDirectory::setName(const string Name) { this->Name = Name; }
const int TelephoneDirectory::getSize() const { return Size; }
void TelephoneDirectory::setSize(const int Size) { this->Size = Size; }

TelephoneDirectory& TelephoneDirectory::operator=(const TelephoneDirectory& t)
{
	Size = t.Size;
	delete[] TD;
	TD = new Account[Size];
	for (int i = 0; i < Size; i++)
		TD[i] = t.TD[i];
	return *this;
}

void TelephoneDirectory::print()
{
	system("cls");
	cout << "Telephone directory \"" << Name << "\"";
	if (Size == 0)
	{
		cout << " is empty\n" << endl;
	}
	else
	{
		cout << ":" << endl;
		for (int i = 0; i < Size; i++)
		{
			cout << i + 1 << ")";
			TD[i].print();
		}
		cout << endl;
	}
}
void TelephoneDirectory::insert()
{
	system("cls");
	Account* pTD = new Account[Size];
	for (int i = 0; i < Size; i++)
		pTD[i] = TD[i];
	delete[] TD;
	Size++;
	TD = new Account[Size];
	for (int i = 0; i < Size - 1; i++)
		TD[i] = pTD[i];
	string pS;
	cout << "Set the name: ";
	cin >> pS;
	TD[Size - 1].setName(pS);
	cout << "Set the surname: ";
	cin >> pS;
	TD[Size - 1].setSurname(pS);
	cout << "Set the number: ";
	cin >> pS;
	TD[Size - 1].setNumber(pS);
	delete[] pTD;
	cout << "The new account was added\n" << endl;
}
void TelephoneDirectory::edit()
{
	int n;
	while (true)
	{
		this->print();
		cout << "Enter the number of the account that you want to change: ";
		cin >> n;
		if (n > Size || Size == 0 || n <= 0)
		{
			cout << "Incorrect input\n\nPress:\n1 - try again\n2 - back to print menu screen" << endl;
			switch (_getch())
			{
			case '1':
				continue;
			case '2':
				return;
			}
		}
		break;
	}
	string pS;
	cout << "Press:\n1 - change all field\n2 - change only name\n3 - change only surname\n4 - change only number\n5 - stop changing\n" << endl;
	switch (_getch())
	{
	case '1':
		cout << "Set the new name: ";
		cin >> pS;
		TD[n - 1].setName(pS);
		cout << "Set the new surname: ";
		cin >> pS;
		TD[n - 1].setSurname(pS);
		cout << "Set the new number: ";
		cin >> pS;
		TD[n - 1].setNumber(pS);
		system("cls");
		cout << "Change was completed\n" << endl;
		break;
	case '2':
		cout << "Set the new name: ";
		cin >> pS;
		TD[n - 1].setName(pS);
		system("cls");
		cout << "Change was completed\n" << endl;
		break;
	case '3':
		cout << "Set the new surname: ";
		cin >> pS;
		TD[n - 1].setSurname(pS);
		system("cls");
		cout << "Change was completed\n" << endl;
		break;
	case '4':
		cout << "Set the new number: ";
		cin >> pS;
		TD[n - 1].setNumber(pS);
		system("cls");
		cout << "Changing was completed\n" << endl;
		break;
	case '5':
		system("cls");
		cout << "Changing was stoped\n" << endl;
		break;
	}
}
void TelephoneDirectory::del()
{
	system("cls");
	int n;
	while (true)
	{
		this->print();
		cout << "Enter the number of the account that you want to delete: ";
		cin >> n;
		if (n > Size || Size == 0 || n <= 0)
		{
			cout << "Incorrect input\n\nPress:\n1 - try again\n2 - back to print menu screen" << endl;
			switch (_getch())
			{
			case '1':
				continue;
			case '2':
				return;
			}
		}
		break;
	}
	cout << "Do you want to delete " << TD[n - 1].getName() << " " << TD[n - 1].getSurname() << "?\n\nPress:\n1 - Yes\n2 - No\n" << endl;
	switch (_getch())
	{
	case '1':
	{
		Size--;
		Account* pTD = new Account[Size];
		for (int i = 0; i < n - 1; i++)
			pTD[i] = TD[i];
		for (int i = n; i < Size + 1; i++)
			pTD[i - 1] = TD[i];
		delete[] TD;
		TD = new Account[Size];
		for (int i = 0; i < Size; i++)
			TD[i] = pTD[i];
		delete[] pTD;
		system("cls");
		cout << "Account was deleted\n" << endl;
		break;
	}
	case '2':
		system("cls");
		cout << "Account wasn't deleted\n" << endl;
		break;
	}
}
void TelephoneDirectory::clearing()
{
	system("cls");
	cout << "Do you want to clear \"" << Name << "\"?\n\nPress:\n1 - Yes\n2 - No\n" << endl;
	switch (_getch())
	{
	case '1':
		delete[] TD;
		TD = new Account[0];
		Size = 0;
		system("cls");
		cout << "\"" << Name << "\" was cleared\n" << endl;
		break;
	case '2':
		system("cls");
		cout << "\"" << Name << "\" wasn't cleared\n" << endl;
		break;
	}
}
void TelephoneDirectory::search()
{
	system("cls");
	int n = 0;
	string pS;
	Account* pTD = new Account[Size];
	cout << "Press:\n1 - search by name\n2 - search by surname\n3 - search by number\n4 - stop searching\n" << endl;
	switch (_getch())
	{
	case '1':
		cout << "Input name: ";
		cin >> pS;
		for (int i = 0; i < Size; i++)
			if (TD[i].getName() == pS)
			{
				pTD[n] = TD[i];
				n++;
			}
		system("cls");
		if (n == 0)
		{
			cout << "\"" << Name << "\" does not contain account with name \"" << pS << "\"\n" << endl;
		}
		else
		{
			cout << n << " accounts found:" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ")";
				pTD[i].print();
			}
			cout << endl;
		}
		break;
	case '2':
		cout << "Input surname: ";
		cin >> pS;
		for (int i = 0; i < Size; i++)
			if (TD[i].getSurname() == pS)
			{
				pTD[n] = TD[i];
				n++;
			}
		system("cls");
		if (n == 0)
		{
			cout << "\"" << Name << "\" does not contain account with surname \"" << pS << "\"\n" << endl;
		}
		else
		{
			cout << n << " accounts found:" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ")";
				pTD[i].print();
			}
			cout << endl;
		}
		break;
	case '3':
		cout << "Input number: ";
		cin >> pS;
		for (int i = 0; i < Size; i++)
			if (TD[i].getNumber() == pS)
			{
				pTD[n] = TD[i];
				n++;
			}
		system("cls");
		if (n == 0)
		{
			cout << "\"" << Name << "\" does not contain account with number \"" << pS << "\"\n" << endl;
		}
		else
		{
			cout << n << " accounts found:" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ")";
				pTD[i].print();
			}
			cout << endl;
		}
		break;
	case '4':
		system("cls");
		cout << "Searching was stoped\n" << endl;
		break;
	}
}
void TelephoneDirectory::fout()
{
	system("cls");
	string path = Name;
	path += ".txt";
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "File opening error" << endl;
	}
	else
	{
		fout << "Telephone directory \"" << Name << "\"";
		if (Size == 0)
		{
			fout << " is empty";
		}
		else
		{
			fout << ":" << endl;
			for (int i = 0; i < Size; i++)
			{
				fout << i + 1 << ")" << TD[i].getName() << " " << TD[i].getSurname() << " " << TD[i].getNumber();
				if (i + 1 < Size)
					fout << endl;
			}
		}
		cout << "Saving to the file was completed\n" << endl;
	}
	fout.close();
}
void TelephoneDirectory::fin()
{
	system("cls");
	string path = Name;
	path += ".txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "File opening error" << endl;
	}
	else
	{
		int c = 0, cn = 0;
		string pfin;
		Size = 0;
		delete[] TD;
		TD = new Account[0];
		while (!fin.eof())
		{
			fin >> pfin;
			if (pfin.find(')') >= 0 && pfin.find(')') <= 9000000000)
			{
				c++;
				cn = 0;
				Account* pTD = new Account[Size];
				for (int i = 0; i < Size; i++)
					pTD[i] = TD[i];
				delete[] TD;
				Size = c;
				TD = new Account[Size];
				for (int i = 0; i < Size - 1; i++)
					TD[i] = pTD[i];
			}
			cn++;
			if (c > 0)
			{
				if (cn == 1)
				{
					TD[c - 1].setName(pfin.substr(pfin.find(')') + 1, pfin.size() - pfin.find(')') - 1));
				}
				if (cn == 2)
				{
					TD[c - 1].setSurname(pfin);
				}
				if (cn == 3)
				{
					TD[c - 1].setNumber(pfin);
					cn = 0;
				}
			}
		}
		cout << "Loading from the file was completed\n" << endl;
	}
	fin.close();
}