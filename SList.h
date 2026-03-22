#ifndef __SLIST_H__
#define __SLIST_H__
#include <iostream>



/* Data struct */
struct Node
{
    int value;
    Node* next;
};

/* Iterator class */

class SListIterator
{
    public:

        explicit SListIterator(Node* node_ptr) : m_node_ptr(node_ptr){}

        ~SListIterator() = default;

        SListIterator& operator++();
        bool operator==(const SListIterator&);
        bool operator!=(const SListIterator&);
        void operator=(const SListIterator&);
        Node* operator*();

    private:
        Node* m_node_ptr;

};


/* List class */
class SList
{
    public:

        bool isEmpty() { return m_head == nullptr; }
        explicit SList(Node* head = nullptr) : m_head(head){}
        SList(const SList &) = delete;
        void push_back(int x);
        void push_front(int x);
        void pop_front();
        SListIterator begin();
        SListIterator end();
        void PrintList();
        ~SList();

    private:
        Node* m_head;
                    

};



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
*/


#endif

