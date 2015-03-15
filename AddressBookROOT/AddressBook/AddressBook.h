#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Address
{
public:
	Address();
	Address(string name, vector<string> phonenum, int CallerID);
	~Address();

private:
	string name;
	vector<string> phonenums;
	int CallerID;
};