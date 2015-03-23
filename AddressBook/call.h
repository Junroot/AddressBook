#ifndef __CALL_H__
#define __CALL_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "AddressBook.h"

struct Caller
{
	std::string number;
	std::string status;
};

class Call
{ 
public:
	Call();
	~Call();
	void Readfile();
	void Print(AddressBook* book);
private:
	std::map<std::string, Caller> callers;
};

#endif