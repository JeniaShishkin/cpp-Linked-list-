#ifndef __SLIST_H__
#define __SLIST_H__
#include <iostream>



/* List node struct */
struct Node
{
    int value;
    Node* next;
};

/* List class */
class SList
{
public:
    class SListIterator
    {
    public:

        explicit SListIterator(Node* node_ptr) : current(node_ptr) { }
        SListIterator(const SListIterator& other) = default;
        ~SListIterator() = default;
        SListIterator& operator++() { current = current->next; return *this; }
        bool operator==(const SListIterator& other) { return current == other.current; }
        bool operator!=(const SListIterator& other) { return !(current == other.current); }
        SListIterator& operator=(const SListIterator& other) { current = other.current; return *this; } 
        int& operator*() { return current->value; }

    private:
        Node* current;
    };

    explicit SList(Node* head = nullptr, Node* tail = nullptr) : m_head(head), m_tail(tail){}
    SList(const SList & other) = default;
    ~SList();
    void push_back(const int &x);
    void push_front(const int &x);
    void pop_front();
    bool isEmpty() { return m_head == nullptr; }
    
    // Iterator methods.
    SListIterator begin() const { return SListIterator{m_head}; }
    SListIterator end() const { return SListIterator{nullptr}; }

    void PrintList();
private:

    Node* m_head;
    Node* m_tail;

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

