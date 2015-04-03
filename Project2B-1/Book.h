#pragma once

#include "Date.h"
#include "Employee.h"
#include "PriorityQueue.h"

using namespace std;

class Book
{
public:
	Book();
	Book(string name);
	bool IsArchived();
	string GetName();
	void Archive();
	void AddtoQueue(Employee* employee);
	void PopulateQueue(list<Employee>& employeeList);
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
	PriorityQueue<Employee*> _waiting;
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
	_waiting.Push(employee);
}

//Pushes entire list of employees to book queue if new book is added.
void Book::PopulateQueue(list<Employee>& employeeList)
{
	list<Employee>::iterator employeeIterator = employeeList.begin();
	while (employeeIterator != employeeList.end())
	{
		_waiting.Push(&(*employeeIterator));
	}
}

bool Book::IsEmpty()
{
	return _waiting.IsEmpty(); 
}

void Book::Archive()
{
	_isArchived = true;
	_Owner = NULL;
}

bool Book::IsArchived()
{
	return _isArchived;
}

Employee* Book::GetOwner()
{
	return _Owner;
}

//Removes priority employee from queue and stores in _Owner variable, sets owners wait time.
void Book::SetNewOwner(Date dateCirc, Date dateReceived)
{
	if (!_waiting.IsEmpty())
	{
		_Owner = _waiting.Pop();
		_Owner->SetWaitTime(dateCirc, dateReceived);
	}
}

//Returns the previous pass and sets current pass to previous pass.
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

//Sets the circulation date and sets initial pass date.
void Book::StartCiculation(Date date)
{
	_previousPass = date;
	_circulationDate = date;
}

Date Book::GetCirculationDate()
{
	return _circulationDate;
}


