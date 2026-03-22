#ifndef __SLIST_H__
#define __SLIST_H__
#include <vector>




struct Node
{
    int value;
    Node* next;
};

class SList
{
    public:

        bool isEmpty() { return m_head == nullptr; }
        explicit SList(Node* head = nullptr, Node *tail = nullptr) : m_head(head), m_tail(tail) {}
        SList(const SList &);
        void push_back(int x);
        void push_front(int x);
        void pop_front();
        SListIterator begin();
        SListIterator end();
        ~SList();

    private:
        Node* m_head;

        // For implementation of push_front in O(1).

        Node* m_tail;

};


class SListIterator
{
    public:

        explicit SListIterator();


        ~SListIterator() = default;

        SListIterator operator++();
        bool operator==(const SListIterator&);
        bool operator!=(const SListIterator&);
        SListIterator operator=(const SListIterator&);


    private:
        Node* list_ptr;

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

