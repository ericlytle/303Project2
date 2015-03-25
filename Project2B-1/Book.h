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
	void PassOn();
	void AddtoQueue(Employee* employee); //called by addEmployee in library
	void PopulateQueue(list<Employee> employeeList); //only to be called by addBook in library
private:
	bool _isArchived;
	Date _circulationStart;
	Date _circulationStop;
	EmployeeQueue _waitingForThisBook; //pointers
	string _name;
	
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