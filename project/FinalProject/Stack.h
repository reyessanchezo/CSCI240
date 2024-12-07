// Stack class from zybooks
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackADT.h"

// Node to store an item in a linked-list-based stack
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

// Linked-list-based stack
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
        int popped[2];
    	popped[0] = top->dataX;
        popped[1] = top->dataY;

        // Remove top node
        top = top->next;

        // Delete former top node
        delete poppedNode;

        // Return the popped item
        return popped;
    }

    // Prints stack items from top to bottom, with the separator string between
    // each pair of items
    virtual void Print(std::ostream& printStream = std::cout,
        const std::string& separator = " | ") const override {
        StackNode* node = top;

        if (node) {
            // Print first item with no separator
            printStream << node->dataX << "," << node->dataY;
            node = node->next;
        }

        // Print remaining items, each preceded by the separator
        while (node) {
            printStream << separator << node->dataX << "," << node->dataY;
            node = node->next;
        }
    }
};

#endif