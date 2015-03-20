#include "AddressBook.h"

using namespace std;

AddressBook::AddressBook(){}
AddressBook::~AddressBook(){}

void AddressBook::ReadFile(){}
void AddressBook::WriteFile(){}
void AddressBook::Print()
{
	for (map<string, string>::iterator it = people.begin();
		it != people.end(); ++it)
	{
		cout << "name: " << it->first << "\t";
		cout << "number: " << it->second << endl;
	}
}

void AddressBook::SearchByName(string name)
{
	for(map<string, string>::iterator it = people.begin();
			it != people.end(); ++it)
	{
		if (it->first.find(name) != string::npos)
		{
			cout << "name: " << it->first << "\t";
			cout << "number: " << it->second << endl;
		}
	}
}
void AddressBook::SearchByNum(string num)
{ 
	for (map<string, string>::iterator it = people.begin();
		it != people.end(); ++it)
	{
		if (it->second.find(num) != string::npos)
		{
			cout << "name: " << it->first << "\t";
			cout << "number: " << it->second << endl;
		}
	}
}
