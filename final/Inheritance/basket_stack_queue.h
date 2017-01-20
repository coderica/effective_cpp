#pragma once

class Stack_Queue;

class Basket
{
	Basket * nextOne;
public:
	Basket() :nextOne(nullptr) {}
	virtual Basket * next() { return nextOne; }
	virtual void display() = 0;
	virtual ~Basket() {};
	friend class Stack_Queue;
	
};

class Stack_Queue {
protected:
	Basket *head;
	Basket *tail;
public:
	Stack_Queue() :head(nullptr), tail(nullptr) {}
	void setNext(Basket *b, Basket *next) { b->nextOne = next; }
	virtual void push(Basket *basket);
	virtual Basket* pop()=0;
	virtual void display();
	virtual bool empty() { return !head; }
};

class Stack : public Stack_Queue
{
public:
	Stack() :Stack_Queue() {}
	Basket* pop() override;
	
};

class Queue : public Stack_Queue
{
public:
	Queue() :Stack_Queue() {}
	Basket* pop() override;
};
