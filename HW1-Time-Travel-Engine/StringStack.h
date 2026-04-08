// Name: Yakup Emre Çelebi, Department: Computer Science
#ifndef STRINGSTACK_H
#define STRINGSTACK_H

#include <string>

#include <iostream>

using namespace std;

class StringStack
{
private:
    string *data;

    int topIndex;
    int capacity;

public:
    StringStack(int initialCapacity = 10);

    ~StringStack();

    bool push(string value);

    string pop();
    string peek() const;

    bool isEmpty() const;

    bool isFull() const;
    int size() const;
    int getCapacity() const;

    void expand();

    void clear();
    string getElementAt(int index) const;
};

#endif
