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
	void SetPriority();
	void DisplayList();
private:
	void insertionSort(list<Employee*> & employeeList);
	list<Employee*> _employees;
};

Employee* EmployeeQueue::Pop() 
{
	list<Employee*>::iterator temp = _employees.begin(); //a pointer to a pointer
	_employees.pop_front();
	return *temp; //a pointer to the orioginal list
}

void EmployeeQueue::SetPriority()
{
	insertionSort(_employees);

}

void EmployeeQueue::DisplayList()
{
	list<Employee*>::iterator temp = _employees.begin();

	while (temp != _employees.end())
	{
		cout << (**temp).GetName() << endl;
		++temp;
	}

}

void EmployeeQueue::insertionSort(list<Employee*> & employeeList)
{
	list<Employee*> temp;
	list<Employee*>::iterator outer = employeeList.begin();
	bool insertionneeded = false;

	temp.push_back(*outer);
	outer = employeeList.erase(outer);


	list<Employee*>::iterator inner = temp.begin();
	while (outer != employeeList.end())
	{
		insertionneeded = false;
		for (inner = temp.begin(); inner != temp.end(); ++inner)
		{
			if (**outer >= **inner)
			{
				temp.insert(inner, *outer);
				insertionneeded = true;
				break;
			}

		}
		if (insertionneeded == false)
		{
			temp.push_front(*outer);

		}
		outer = employeeList.erase(outer);
	}

	employeeList = temp;
}