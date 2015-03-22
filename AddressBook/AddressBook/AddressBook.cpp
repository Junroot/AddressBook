#include "AddressBook.h"
#include <fstream>
#include <algorithm>

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
	person per;
	while (inFile >> per.first >> per.second)
	{
		AddPerson(per);
	}
	inFile.close();
}
void AddressBook::WriteFile()
{
	ofstream outFile("list.txt",std::ios::out);
	for (map<string, person>::iterator it = people.begin();
		it != people.end(); ++it)
	{
		outFile << it->second.first << "\t" << it->second.second << endl;
	}
	outFile.close();
}
void AddressBook::Print(int sel)
{
	int i = 1;
	for (map<string, person>::iterator it = people.begin();
		it != people.end(); ++it)
	{
		cout << "\t";
		if (i == sel) cout << "▶";
		printf("name : %-20s number : %s\n",
			it->second.first.c_str(), it->second.second.c_str());
		i++;
	}
}

void AddressBook::SearchByName(string name)
{
	string lower_name = name;
	transform(lower_name.begin(), lower_name.end(), lower_name.begin(), tolower);
	for(map<string, person>::iterator it = people.begin();
			it != people.end(); ++it)
	{
		if (it->first.find(lower_name) != string::npos)
		{
			printf("\tname : %-20s number : %s\n",
				it->second.first.c_str(), it->second.second.c_str());
		}
	}
}
void AddressBook::SearchByNum(string num)
{ 
	for (map<string, person>::iterator it = people.begin();
		it != people.end(); ++it)
	{
		if (it->second.second.find(num) != string::npos)
		{
			printf("\tname : %-20s number : %s\n",
				it->first.c_str(), it->second.second.c_str());
		}
	}
}

void AddressBook::AddPerson(person p)
{
	string name = p.first;
	bool check = false;

	transform(name.begin(), name.end(), name.begin(), tolower);

	if (people.find(name) != people.end())
	{
		check = true;
	}

	if (check == true)
	{
		cout  << p.first << "\'s address exists. Please try after delete it.\n";
		fflush(stdin);
		getchar();
		return;
	}
	people.insert(pair<string, person>(name, p));
	WriteFile();
}
void AddressBook::DeletePerson(int sel)
{
	char ch;
	if (people.size() == 0) return;
	cout << "Do you want to delete this address? (Y/N)";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		map<string, person>::iterator it = people.begin();
		for (int i = 1; i < sel; i++) it++;
		people.erase(it);
		WriteFile();
	}
}