/*
 * Queue class from ZyBooks, sort of
 *
 */
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "QueueADT.h"

 // linked list queue
class QueueNode {
public:
	int data;
	QueueNode* next;

	QueueNode(int dataValue, QueueNode* nextNode = nullptr)
	{
		data = dataValue;
		next = nextNode;
	}
};

class Queue : public QueueADT {
private:
	QueueNode* front;
	QueueNode* end;

public:
	Queue()
	{
		front = nullptr;
		end = nullptr;
	}

	virtual ~Queue()
	{
		while (front)
		{
			QueueNode* nodeToDelete = front;
			front = front->next;
			delete nodeToDelete;
		}
	}

	virtual bool Enqueue(int newData) override
	{
		// Create a new node
		QueueNode* newNode = new QueueNode(newData);

		// Append newNode to the end of the linked list
		if (nullptr == front)
		{
			front = newNode;
		}
		else
		{
			end->next = newNode;
		}
		end = newNode;

		return true;
	}

	virtual int Dequeue() override
	{
		// Copy front node's data
		QueueNode* dequeuedNode = front;
		int dequeuedItem = front->data;

		// Remove front node
		front = front->next;
		delete dequeuedNode;

		// If empty, assign end with nullptr
		if (nullptr == front)
		{
			end = nullptr;
		}

		// Return dequeued item
		return dequeuedItem;
	}

	virtual int GetLength() const override
	{
		int length = 0;
		QueueNode* node = front;
		while (node)
		{
			length++;
			node = node->next;
		}
		return length;
	}

	virtual bool IsEmpty() const override
	{
		return nullptr == front;
	}

	virtual int Peek() const override
	{
		return front->data;
	}

	virtual void Print(std::ostream& printStream = std::cout,
		const std::string& separator = ", ") const override
	{
		QueueNode* node = front;
		if (node)
		{
			printStream << node->data;
			node = node->next;
		}
		while (node)
		{
			printStream << separator << node->data;
			node = node->next;
		}
		printStream << '\n';
	}
};

#endif