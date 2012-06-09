#include "Stack.h"

void Stack::insert(Node* toInsert)
{
    m_nodes.push(toInsert);
}

Node* Stack::peekFront()
{
    return m_nodes.top();
}

Node* Stack::removeFront()
{
    Node* node = m_nodes.top();
    m_nodes.pop();
    return node;
}

int Stack::size()
{
    return m_nodes.size();
}

bool Stack::contains(Node* node)
{
    assert(false);
    return false;
}

