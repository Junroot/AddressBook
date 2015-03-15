#include "AddressBook.h"
#include <string>
#include <vector>

using namespace std;

Address::Address() {}

Address::Address(string name, vector<string> phonenums, int CallerID)
{
	name = name;
	phonenums = phonenums;
	CallerID = CallerID;
}

Address::~Address() {}