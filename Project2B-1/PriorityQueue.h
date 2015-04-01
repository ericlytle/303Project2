#pragma once

#include <list>

// PriorityQueue class
// Uses a list to implement a priority queue.
// Always returns largest member.

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

// Pop() searches for largest memeber, removes from list, and returns it
template <typename T>
T PriorityQueue<T>::Pop()
{
	if (!_list.empty())
	{
		T top = _list.front();
		list<T>::iterator iter = _list.begin();
		list<T>::iterator index = _list.begin();
		for (iter; iter != _list.end(); ++iter)
		{
			if (top < *iter)
			{
				top = *iter;
				index = iter;
			}
		}
		_list.erase(index);
		return top;
	}
	throw exception("EMPTY PRIORITY_QUEUE");
}