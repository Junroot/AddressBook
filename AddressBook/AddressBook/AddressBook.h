#include <iostream>
#include <map>
#include <string>

#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__

typedef std::pair<std::string, std::string> person;

class AddressBook
{
public:
	AddressBook();
	~AddressBook();
	void ReadFile();
	void WriteFile();
	void Print(int sel);
	void SearchByName(std::string name);
	void SearchByNum(std::string num);

	std::string SearchName(std::string num);

	void AddPerson(person p);
	void DeletePerson(int sel);
	int Size()	{ return people.size(); }

private:
	std::map<std::string, person> people;
};

#endif
