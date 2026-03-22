#include "SList.h"


SList::SList(const SList &)
{

}

void SList::push_back(int x)
{
    // In case we're dealing with an empty list.
    if(isEmpty())
    {
        Node* new_node = new Node{x, nullptr};
        m_head = new_node;
        m_tail = new_node;
        return;
    }
    // List is not empty.
    Node* new_node = new Node{x, m_head};
    m_head = new_node;
}

void SList::push_front(int x)
{
    // In case we're dealing with an empty list.
    if(isEmpty())
    {
        Node* new_node = new Node{x, nullptr};
        m_head = new_node;
        m_tail = new_node;
        return;
    }
    // List is not empty.
    Node* new_node = new Node{x, nullptr};
    m_tail->next = new_node;
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

SListIterator begin()
{
    return;
}

SListIterator end()
{

}

SList::~SList()
{

}
