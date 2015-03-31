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
	string GetName();
	void Archive();
	void AddtoQueue(Employee* employee); //called by addEmployee in library
	void PopulateQueue(list<Employee>& employeeList); //only to be called by addBook in library
	Employee* GetOwner();
	void SetNewOwner();
	void StartCiculation(Date date);
	Date GetPreviousPass(Date newPass);
	void updateWaitTimes(Date date);
	void SetBookPriority();
private:
	Date _previousPass;
	bool _isArchived;
	EmployeeQueue _waitingForThisBook; //pointers
	string _name;
	Employee* _Owner;
	Date _circulationDate;
};

Book::Book()
{
	_isArchived = false;
	_previousPass = Date("1-1-2000",DateFormat::US);
	_name = "";
	_Owner = NULL;
}

Book::Book(string name)
{
	_isArchived = false;
	_name = name;
	_previousPass = Date("1-1-2000", DateFormat::US);
	_Owner = NULL;
}


void Book::AddtoQueue(Employee* employee)
{
	_waitingForThisBook.Push(employee);
	if (_Owner != NULL)
		_waitingForThisBook.SetPriority();
}

void Book::PopulateQueue(list<Employee>& employeeList)
{
	list<Employee>::iterator employeeIterator = employeeList.begin();
	while (employeeIterator != employeeList.end())
	{
		_waitingForThisBook.Push(&(*employeeIterator));
	}
	_waitingForThisBook.SetPriority();
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
	if (!_waitingForThisBook.IsEmpty())
		_Owner = _waitingForThisBook.Pop(); //returns top, then removes. 
	if (_waitingForThisBook.IsEmpty())
		Archive();
}

Date Book::GetPreviousPass(Date newPass)
{
	Date temp = _previousPass;
	_previousPass = newPass;
	return temp;
}

string Book::GetName()
{
	return _name;
}

void Book::StartCiculation(Date date)
{
	_previousPass = date;	
}

void Book::updateWaitTimes(Date date)
{
	list<Employee*>::iterator iter = _waitingForThisBook.Begin();
	while (iter != _waitingForThisBook.End())
	{
		(*iter)->SetWaitTime(_previousPass, date);
		++iter;
	}
	_waitingForThisBook.SetPriority();
}

void Book::SetBookPriority()
{
	_waitingForThisBook.SetPriority();
}
