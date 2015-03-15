#include <iostream>
#include <string>
<<<<<<< HEAD
#include <vector>
=======
>>>>>>> origin/master

class Address
{
public:
	Address();
	Address(string name, vector<string> phonenum, int CallerID);
	~Address();
	const std::string name() const
	{
		return _name;
	}

private:
<<<<<<< HEAD
<<<<<<< HEAD
	string name;
	vector<string> phonenums;
	int CallerID;
=======
	std::string _name;
	std::string _phonenum;
	int _callerID;
>>>>>>> origin/master
=======
	std::string _name;
	std::string _phonenum;
	int _callerID;
>>>>>>> origin/master
};