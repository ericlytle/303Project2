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
	void SetNewOwner(Date dateCirc, Date dateReceived);
	void StartCiculation(Date date);
	Date GetCirculationDate();
	Date GetPreviousPass(Date newPass);
	void SetBookPriority();
	bool IsEmpty();
private:
	Date _previousPass;
	Date _circulationDate;
	bool _isArchived;
	EmployeeQueue _waitingForThisBook; //pointers
	string _name;
	Employee* _Owner;

};

Book::Book()
{
	_isArchived = false;
	_name = "";
	_Owner = NULL;
}

Book::Book(string name)
{
	_isArchived = false;
	_name = name;
	_Owner = NULL;
}


void Book::AddtoQueue(Employee* employee)
{
	_waitingForThisBook.Push(employee);
}

void Book::PopulateQueue(list<Employee>& employeeList)
{
	list<Employee>::iterator employeeIterator = employeeList.begin();
	while (employeeIterator != employeeList.end())
	{
		_waitingForThisBook.Push(&(*employeeIterator));
	}
}

bool Book::IsEmpty()
{
	return _waitingForThisBook.IsEmpty();
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

void Book::SetNewOwner(Date dateCirc, Date dateReceived)
{
	if (!_waitingForThisBook.IsEmpty())
		_Owner = _waitingForThisBook.Pop(); 
		_Owner->SetWaitTime(dateCirc, dateReceived);

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
	_circulationDate = date;
}

Date Book::GetCirculationDate()
{
	return _circulationDate;
}


