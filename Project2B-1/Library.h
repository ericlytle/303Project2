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
	void AddBook(string bookName);

private:
	list<Employee> _employeeList;
	list<Book> _bookListActive;
	list<Book>  _bookListArchived;

};

Library::Library()
{
	;
}

void Library::AddEmployee(string employeeName)
{
	Employee tempEmployee(employeeName);
	_employeeList.push_back(tempEmployee);
	list<Book>::iterator iter = _bookListActive.begin();
	while (iter != _bookListActive.end()){
		iter->AddtoQueue(&tempEmployee);
		++iter;
	}
	
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
			if (iter->IsArchived())
			{
				_bookListArchived.push_back(*iter);
				iter = _bookListArchived.erase(iter);
				return;
			}

				iter->SetNewOwner();
		}

		++iter;
	}
}
void Library::AddBook(string bookName)
{
	Book tempBook(bookName);
	_bookListActive.push_back(tempBook);
	tempBook.PopulateQueue(_employeeList);
	

}