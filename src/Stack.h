#ifndef STACK_H
#define STACK_H

#include <stack>
#include "Queue.h"

class Stack : public Queue
{
    public:
        //Constructor, destructor
        Stack() {}
        virtual ~Stack() {}

        virtual void insert(Node* toInsert);

        virtual Node* peekFront();

        virtual Node* removeFront();

        virtual int size();

        virtual bool contains(Node* node);
    private:
        std::stack<Node*> m_nodes;
};

#endif
