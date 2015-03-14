#include <iostream>
#include <string>

using namespace std;

class Address
{
public:
	Address();
	~Address();
private:
	string name;
	int *phonenum;
};