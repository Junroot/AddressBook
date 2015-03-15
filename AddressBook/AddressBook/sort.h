#ifndef __SORT_H__
#define __SORT_H__

#include <algorithm>
#include "AddressBook.h"

namespace sort_address
{
//Address가 배열에 저장된다고 가정함
//Address를 vector에 저장할 경우 수정
void sort(Address *addresses, int size);

bool compare(const Address &a, const Address &b);

}
#endif