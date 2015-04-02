// THIS CLASS IS DEPRICATED
// REMOVE ANY REFERENCES IN THIS SOLUTION
// SHOULD USE PriorityQueue CLASS INSTEAD

#pragma once
#include "Employee.h"
#include <list>

using namespace std;

class EmployeeQueue
{
public:
	EmployeeQueue() { ; };
	bool IsEmpty() { return _employees.empty(); }
	Employee* Pop(); 
	void Push(Employee* employee) { _employees.push_back(employee); }; 

private:
	list<Employee*> _employees;
};

Employee* EmployeeQueue::Pop() 
{
	Employee * topEmployee = _employees.front();
	list<Employee*>::iterator iter = _employees.begin(), tempIter = _employees.begin();
	++iter;
	for (iter; iter != _employees.end(); ++iter)
	{
		if (topEmployee->Priority() < (*iter)->Priority())
		{
			topEmployee = *iter;
			tempIter = iter;
		}
	}	
	_employees.erase(tempIter);
	return topEmployee;

}
