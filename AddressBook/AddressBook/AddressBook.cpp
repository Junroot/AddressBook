#include "AddressBook.h"
#include <fstream>

using namespace std;

AddressBook::AddressBook()
{
	ReadFile();
	WriteFile();
}
AddressBook::~AddressBook(){}

void AddressBook::ReadFile()
{
	ifstream inFile("list.txt",ios::in);
	pair<string, string> per;
	while (inFile >> per.first >> per.second)
	{
		people.insert(per);
	}
	inFile.close();
}
void AddressBook::WriteFile()
{
	ofstream outFile("list.txt",std::ios::out);
	for (map<string, string>::iterator it = people.begin();
		it != people.end(); ++it)
	{
		outFile << it->first << "\t" << it->second << endl;
	}
	outFile.close();
}
void AddressBook::Print(int sel)
{
	int i = 1;
	for (map<string, string>::iterator it = people.begin();
		it != people.end(); ++it)
	{
		cout << "\t";
		if (i == sel) cout << "¢º";
		printf("name : %-20s number : %s\n", it->first.c_str(), it->second.c_str());
		i++;
	}
}

void AddressBook::SearchByName(string name)
{
	for(map<string, string>::iterator it = people.begin();
			it != people.end(); ++it)
	{
		if (it->first.find(name) != string::npos)
		{
			printf("\tname : %-20s number : %s\n", it->first.c_str(), it->second.c_str());
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
			printf("\tname : %-20s number : %s\n", it->first.c_str(), it->second.c_str());
		}
	}
}

void AddressBook::AddPerson(person p)
{
	people.insert(p);
	WriteFile();
}
void AddressBook::DeletePerson(int sel)
{
	if (people.size() == 0) return;
	map<string, string>::iterator it = people.begin();
	for (int i = 1; i < sel; i++) it++;
	people.erase(it);
	WriteFile();
}