#include <iostream>
#include <string>

class Address
{
public:
	Address();
	~Address();
	const std::string name() const
	{
		return _name;
	}

private:
	std::string _name;
	std::string _phonenum;
	int _callerID;
};