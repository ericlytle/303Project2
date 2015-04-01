#pragma once
#include "Employee.h"
//#include "EmployeeList.h"
#include <list>
#include <iostream>

using namespace std;

class EmployeeQueue
{
public:
	EmployeeQueue() { ; };
	bool IsEmpty() { return _employees.empty(); }
	Employee* Pop(); 
	void Push(Employee* employee) { _employees.push_back(employee); }; 
	void updateWaitTimes(Date currentDate, Date circulationDate);
	list<Employee*>::iterator Begin();
	list<Employee*>::iterator End();
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

void EmployeeQueue::updateWaitTimes(Date currentDate, Date circulationDate)
{
	list<Employee*>::iterator iter = _employees.begin();
	while (iter != _employees.end())
	{
		(*iter)->SetWaitTime(currentDate, circulationDate);
		++iter;
	}
}

list<Employee*>::iterator EmployeeQueue::Begin()
{
	list<Employee*>::iterator iter = _employees.begin();
	return iter;
}

list<Employee*>::iterator EmployeeQueue::End()
{
	list<Employee*>::iterator iter = _employees.end();
	return iter;
}