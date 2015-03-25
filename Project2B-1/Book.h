#pragma once

#include "Date.h"
#include "EmployeeQueue.h"
#include "Employee.h"

using namespace std;

class Book
{
public:
	Book();
	Book(string name);
	bool IsArchived();
	Date CirculationStart();
	Date CirculationStop();
	string GetName();
	void CirculationStart(Date date);
	void CirculationStop(Date date);
	void Archive();
	void AddtoQueue(Employee* employee); //called by addEmployee in library
	void PopulateQueue(list<Employee> employeeList); //only to be called by addBook in library
	Employee* GetOwner();
	void SetNewOwner();
	Date GetPreviousPass(Date newPass);
private:
	Date _previousPass;
	bool _isArchived;
	Date _circulationStart;
	Date _circulationStop;
	EmployeeQueue _waitingForThisBook; //pointers
	string _name;
	Employee* _Owner;
};

Book::Book()
{
	_isArchived = false;
	_circulationStart = Date(2100, 1, 1); 
	_circulationStop = Date(2100, 1, 1);
	_name = "";
}

Book::Book(string name)
{
	_isArchived = false;
	_circulationStart = Date(2100, 1, 1);
	_circulationStop = Date(2100, 1, 1);
	_name = name;
}


void Book::AddtoQueue(Employee* employee)
{
	_waitingForThisBook.Push(employee);
}

void Book::PopulateQueue(list<Employee> employeeList)
{
	list<Employee>::iterator employeeIterator = employeeList.begin();
	while (employeeIterator != employeeList.end())
	{
		_waitingForThisBook.Push(&(*employeeIterator));
	}
}

void Book::Archive()
{
	_isArchived = true;
}

bool Book::IsArchived()
{
	return _isArchived;
}

Employee* Book::GetOwner()
{
	return _Owner;
}

void Book::SetNewOwner()
{
	_Owner = _waitingForThisBook.Pop(); //returns top, then removes. 
}

Date Book::GetPreviousPass(Date newPass)
{
	Date temp = _previousPass;
	_previousPass = newPass;
	return temp;
}
