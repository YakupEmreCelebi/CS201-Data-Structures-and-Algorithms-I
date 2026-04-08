// Name: Yakup Emre Çelebi, Section : 2, ID: 22302267, Department: Computer Science

#include "StringStack.h"

StringStack::StringStack(int initialCapacity)
{
    capacity = initialCapacity;
    if (capacity < 0)
    {
        capacity = 0;
    }
    if (capacity > 0)
    {
        data = new string[capacity];
    }

    else
    {
        data = nullptr;
    }

    topIndex = -1;
}

StringStack::~StringStack()
{
    delete[] data;
    data = nullptr;
}

bool StringStack::push(string value)
{
    if (isFull())
    {
        return false;
    }

    topIndex++;

    data[topIndex] = value;
    return true;
}

string StringStack::pop()
{
    if (isEmpty())
    {

        return "";
    }
    string val = data[topIndex];

    topIndex--;
    return val;
}

string StringStack::peek() const
{
    if (isEmpty())
        return "";

    else
    {
        return data[topIndex];
    }
}

bool StringStack::isEmpty() const
{
    return topIndex == -1;
}

bool StringStack::isFull() const
{
    if (capacity > 0 && topIndex == capacity - 1)
    {
        return true;
    }
    return false;
}

int StringStack::size() const
{
    return topIndex + 1;
}

int StringStack::getCapacity() const
{
    return capacity;
}

void StringStack::expand()
{
    int newCapacity = (capacity == 0) ? 2 : capacity * 2;
    string *newData = new string[newCapacity];

    for (int i = 0; i <= topIndex; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;

    data = newData;
    capacity = newCapacity;
}

void StringStack::clear()
{

    topIndex = -1;
}

string StringStack::getElementAt(int index) const
{

    if (index < 0 || index > topIndex)
    {
        return "";
    }
    else
    {
        return data[index];
    }
}
