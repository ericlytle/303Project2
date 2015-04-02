#pragma once

#include <list>

// Name: PriorityQueue
// Description: Uses a list to implement a priority queue class.
// Assumption 1: Pop() method assumes that items can be compared using the < operator.
// Assumption 2: Pop() method assumes that the list is non-empty.

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue<T>() {};
	bool IsEmpty() { return _list.empty(); };
	T Pop();
	void Push(T item) { _list.push_back(item); };
private:
	list<T> _list;
};

// Pop() searches for largest memeber, removes from list, and returns it.
template <typename T>
T PriorityQueue<T>::Pop()
{
	T top = _list.front();
	list<T>::iterator iter = _list.begin();
	list<T>::iterator mark = _list.begin();
	for (iter; iter != _list.end(); ++iter)
	{
		if (*top < **iter)
		{
			top = *iter;
			mark = iter;
		}
	}
	_list.erase(mark);
	return top;
}
