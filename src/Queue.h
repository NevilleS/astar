#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
    public:
        //Constructor, destructor
        Queue() {}
        virtual ~Queue() {}

        virtual void insert(Node* toInsert) = 0;

        virtual Node* peekFront() = 0;

        virtual Node* removeFront() = 0;

        virtual int size() = 0;

        virtual bool contains(Node* node) = 0;
};

#endif
