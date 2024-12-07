#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <iostream>

class QueueADT {
public:
    virtual bool Enqueue(int item) = 0;
    virtual int Dequeue() = 0;

    virtual int GetLength() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual int Peek() const = 0;
    virtual void Print(std::ostream& printStream = std::cout,
        const std::string& separator = ", ") const = 0;
};

#endif