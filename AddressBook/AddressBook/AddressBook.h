#include <iostream>
#include <map>
#include <string>

class AddressBook
{
public:
	AddressBook();
	~AddressBook();
	void ReadFile();
	void WriteFile();
	void Print();
	std::string SearchByName(std::string name);
	std::string SearchByNum(std::string num);

private:
	std::map<std::string, std::string> people;
};

