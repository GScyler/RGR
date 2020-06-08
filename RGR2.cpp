#include "TelephoneDirectory.h"


int main()
{
	TelephoneDirectory A;
	while (true)
	{
		cout << "Press:\n1 - print the telephone directory\n2 - search an account\n3 - save the telephone directory to a file\n4 - load the telephone directory from the file\n5 - quit the programm\n" << endl;
		switch (_getch())
		{
		case '1':
		{
			bool tf = true;
			while (tf)
			{
				A.print();
				cout << "Press:\n1 - change the name of the telephone directory\n2 - add a new account\n3 - change one of accounts\n4 - delete one of accounts\n5 - clear to the telephone directory\n6 - back to the main screen" << endl;
				switch (_getch())
				{
				case '1':
				{
					string ps;
					system("cls");
					A.print();
					cout << "Set the new name: ";
					cin >> ps;
					A.setName(ps);
					break;
				}
				case '2':
					A.insert();
					break;
				case '3':
				{
					A.print();
					A.edit();
					break;
				}
				case '4':
					A.print();
					A.del();
					break;
				case '5':
					A.clearing();
					break;
				case '6':
					system("cls");
					tf = false;
					break;
				default:
					system("cls");
				}
			}
			break;
		}
		case '2':
			A.search();
			break;
		case '3':
			A.fout();
			break;
		case '4':
			A.fin();
			break;
		case '5':
			return 0;
		default:
			system("cls");
		}
	}
}
