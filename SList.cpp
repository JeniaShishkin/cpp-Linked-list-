#include "SList.h"

void SList::push_back(const int &x)
{
    // In case we're dealing with an empty list.
    if (isEmpty())
    {
        Node* new_node = new Node{x, nullptr};
        m_head = new_node;
        m_tail = new_node;
        return;
    }

    // List is not empty.
    Node* new_node = new Node{x, nullptr};
    m_tail->next = new_node;
    m_tail = new_node;
}


void SList::push_front(const int &x)
{
    // In case we're dealing with an empty list.
    if (isEmpty())
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

void SList::pop_front()
{
    // In case we're dealing with an empty list.
    if (isEmpty())
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
    while (!isEmpty())
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
 }

void SList::PrintList()
{
    for (SList::SListIterator itr = begin() ; itr != end() ; ++itr) 
    {    
        std::cout << *itr << " "; 
    }
}


 
