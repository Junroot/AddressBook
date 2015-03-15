#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "AddressBook.h"

using namespace std;

void Sort()
{

}

int main(void)
{
	vector<Address> Addresses;
	FILE * fp;
	
	if (fp = fopen("list.txt", "r"))
	{
		string name;
		while (fscanf(fp, "%s", name) != EOF)
		{
			vector<string> phonenums;
			int count;
			if (fscanf(fp, "%d", &count) != EOF)
			{
				for (int i = 0; i < count; i++)
				{
					string number;
					fscanf(fp, "%s", number);
					
				}
			}
			Address address(name, phonenums, Addresses.size());
			Addresses.push_back(address);
		}
	}
	fclose(fp);
	return 0;
}