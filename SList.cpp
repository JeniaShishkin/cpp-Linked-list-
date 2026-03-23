#include "SList.h"


SList::SList(const SList & other) : m_head(nullptr) , m_tail(nullptr)
{
    for (SList::SListIterator itr = other.begin() ; itr != other.end() ; ++itr) 
    {    
        push_back(*itr); 
    }

}

SList::~SList()
{
    while (!isEmpty())
    {
        pop_front();
    }
    m_head = m_tail = nullptr; 
}


void SList::push_back(const int &x)
{
    // In case we're dealing with an empty list.
    if (isEmpty())
    {
        m_head = m_tail = new Node{x, nullptr};
    }
    // List is not empty.
    else
    {
    Node* new_node = new Node{x, nullptr};
    m_tail->next = new_node;
    m_tail = new_node;
    }
}


void SList::push_front(const int &x)
{
    // In case we're dealing with an empty list.
    if (isEmpty())
    {
        m_head = m_tail = new Node{x, nullptr};
    }
    else
    {
       // List is not empty.
        Node* new_node = new Node{x, m_head};
        m_head = new_node;
    }
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
    m_tail = m_head == nullptr ? nullptr : m_tail;
    delete temp;
}

void SList::swap(SList& other)
{
    using std::swap;
    swap(m_head, other.m_head);
    swap(m_tail, other.m_tail);
}
void SList::PrintList() const
{
    for (SList::SListIterator itr = begin() ; itr != end() ; ++itr) 
    {    
        std::cout << *itr << " "; 
    }
    std::cout << std::endl;
}

SList& SList::operator=(const SList& other) noexcept
{  
    SList copy(other);
    swap(copy);
    return *this;
}
