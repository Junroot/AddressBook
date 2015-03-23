#include "call.h"
#include <fstream>

using namespace std;

Call::Call()
{
	Readfile();
}

void Call::Readfile()
{
	ifstream inFile("Call.txt", ios::in);
	string date;
	Caller caller;
	while (inFile >> date >> caller.number >> caller.status)
	{
		callers.insert(pair<string,Caller>(date,caller));
	}
	inFile.close();
}

void Call::Print(AddressBook* book)
{
	for (map<string, Caller>::iterator it = callers.begin(); it != callers.end(); ++it)
	{
		if (it->second.status=="S")		printf("\t%-10s","Sent");
		else printf("\t%-10s","Received");
		if (book->SearchName(it->second.number) != "")
		{
			printf("%-20s", book->SearchName(it->second.number).c_str());
		}
		else printf("%-20s", it->second.number.c_str());
		cout << "20" << it->first[0] << it->first[1] << "-";
		cout << it->first[2] << it->first[3] << "-";
		cout << it->first[4] << it->first[5] << "  ";
		cout << it->first[6] << it->first[7] << ":";
		cout << it->first[8] << it->first[9] << endl;
	}
}