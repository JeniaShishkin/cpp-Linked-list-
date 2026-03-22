#include "SList.h"

void SList::push_back(int x)
{
    // In case we're dealing with an empty list.
    if(isEmpty())
    {
        Node* new_node = new Node{x, nullptr};
        m_head = new_node;
        return;
    }
    // List is not empty.
    Node* new_node = new Node{x, nullptr};
    Node* current = m_head;
    while(current->next)
    {
        current = current->next;
    }
    current->next = new_node;
}


void SList::push_front(int x)
{
    // In case we're dealing with an empty list.
    if(isEmpty())
    {
        Node* new_node = new Node{x, nullptr};
        m_head = new_node;
        return;
    }
    // List is not empty.
    Node* new_node = new Node{x, m_head};
    m_head = new_node;
}

void SList::pop_front()
{
    // In case we're dealing with an empty list.
    if(isEmpty())
    {
        return;
    }
    // List is not empty.
    Node* temp = m_head;
    m_head = m_head->next;
    delete temp;
}

 SList::~SList()
 {
    while(!isEmpty())
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
 }

void SList::PrintList()
{
    Node* current = m_head;
    while(current)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

 SListIterator SList::begin()
 {
     return SListIterator{m_head};
 }
 
 SListIterator SList::end()
 {
    Node* current = m_head;
    while(current) { current = current->next; }
    return SListIterator{current};
 }

 bool SListIterator::operator==(const SListIterator& other)
 {
    return m_node_ptr == other.m_node_ptr;
 }

 bool SListIterator::operator!=(const SListIterator& other)
{
    return !(m_node_ptr == other.m_node_ptr);
}
 SListIterator& SListIterator::operator++()
 {
    m_node_ptr = m_node_ptr->next;
    return *this;
 }

 void SListIterator::operator=(const SListIterator& other)
 {
    m_node_ptr = other.m_node_ptr;
 }

 Node* SListIterator::operator*()
 {
    return m_node_ptr;
 }
 

