// Stack class from zybooks
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackADT.h"

// Linked-list stack node
class StackNode {
public:
    int dataX, dataY;
    StackNode* next;

    StackNode(int dataValueX, int dataValueY, StackNode* nextNode) {
        dataX = dataValueX;
        dataY = dataValueY;
        next = nextNode;
    }
};

// Linked list stack
class Stack : public StackADT {
private:
    StackNode* top;

public:
    Stack() {
        top = nullptr;
    }

    virtual ~Stack() {
        while (top) {
            StackNode* nodeToDelete = top;
            top = top->next;
            delete nodeToDelete;
        }
    }

    virtual int GetLength() const override {
        StackNode* node = top;
        int count = 0;
        while (node) {
            count++;
            node = node->next;
        }
        return count;
    }

    virtual bool IsEmpty() const override {
        return top == nullptr;
    }

    virtual int PeekX() const override {
        return top->dataX;
    }

    virtual int PeekY() const override {
        return top->dataY;
    }

    virtual void Push(int newDataX, int newDataY) override {
        top = new StackNode(newDataX, newDataY, top);
    }

    virtual int* Pop() override {
        // Copy top node's data
        StackNode* poppedNode = top;
        int* popped = new int[2]; //copilot recommendation
        popped[0] = top->dataX;
        popped[1] = top->dataY;

        // Remove top node
        top = top->next;

        // Delete former top node
        delete poppedNode;

        // Return the popped item
        return popped;
    }

    // prints top to bottom
    virtual void Print(std::ostream& printStream = std::cout,
        const std::string& separator = " | ") const override {
        StackNode* node = top;

        if (node) { // first node without separator
            printStream << node->dataX << "," << node->dataY;
            node = node->next;
        }

        while (node) {
            printStream << separator << node->dataX << "," << node->dataY;
            node = node->next;
        }
    }
};

#endif