#ifndef __SORT_H__
#define __SORT_H__

#include <algorithm>
#include "AddressBook.h"

namespace sort_address
{
//Address�� �迭�� ����ȴٰ� ������
//Address�� vector�� ������ ��� ����
void sort(Address *addresses, int size);

bool compare(const Address &a, const Address &b);

}
#endif