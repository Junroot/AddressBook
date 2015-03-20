#include <iostream>
#include <map>
#include <string>

#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__

class AddressBook
{
public:
	AddressBook();
	~AddressBook();
	void ReadFile();
	void WriteFile();
	void Print();
	void SearchByName(std::string name);
	void SearchByNum(std::string num);

private:
	std::map<std::string, std::string> people;
};

#endif
