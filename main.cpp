#include <iostream>
#include "SList.h"


/* class SList:
push_back(int) - adds at end of list
push_front(int) - adds at begining of list
begin() - return iterator to start of list
end() - return iterator marking AFTER END of list
pop_front() - removes first element (at beginning of list)

class SListIterator:
operator++
operator==
operator!=
operator=
operator*    - returns the value pointed to by the iterator


code using the SList will look something like this
 */

int main()
{
    SList slist;
    slist.push_front(5);
    slist.push_back(8);
    for (SList::iterator itr = slist.begin() ; itr != slize.end() ; ++itr)
    {
        std::cout << *itr << std::cout;
    }
    return 0;
}