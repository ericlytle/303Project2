#pragma once
#include "Book.h"
#include "Employee.h"
#include <list>
#include <string>
using namespace std;



class Library
{
public:
	Library();
	void AddEmployee(string employeeName);
	void CirculateBook(string bookName, Date date);
	void PassOn(string bookName, Date date);

private:
	list<Employee> _employeeList;
	list<Book> _bookListActive;
	list<Book>  _bookListArchived;

};

Library::Library()
{
	;
}

void AddEmployee(string employeeName)
{
	;
}

void CirculateBook(string bookName, Date date)
{
	;
}

void Library::PassOn(string bookName, Date date)
{
	list<Book>::iterator iter = _bookListActive.begin();

	while (iter != _bookListActive.end())
	{
		if (iter->GetName() == bookName)
		{
			iter->SetNewOwner();
		}

		++iter;
	}
}