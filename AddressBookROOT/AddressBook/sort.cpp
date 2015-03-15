#include "sort.h"

bool sort_address::compare(const Address &a, const Address &b)
{
	std::string a_name = a.name();
	std::string b_name = b.name();

	int minsize = a_name.size() < b_name.size() ?
		a_name.size() : b_name.size();

	for (int i = 0; i < minsize; i++) {
		if (a_name[i] != b_name[i])
			return a_name[i] < b_name[i];
	}

	return a_name.size() < b_name.size();
}

void sort_address::sort(Address *addresses, int size)
{
	std::sort(addresses, addresses + size - 1, sort_address::compare);
}