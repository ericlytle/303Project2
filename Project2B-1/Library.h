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
	void updateWaitTimes(Book & book, Date date);
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
	Employee temp(employeeName);
	_employeeList.push_back(temp);
	Employee * tempPtr = &(_employeeList.back());

	list<Book>::iterator iter = _bookListActive.begin();
	while (iter != _bookListActive.end())
	{		
		iter->AddtoQueue(tempPtr);
		++iter;
	}	
}

void Library::CirculateBook(string bookName, Date date)
{
	list<Book>::iterator iter = _bookListActive.begin();
	while (iter != _bookListActive.end())
	{
		if (iter->GetName() == bookName)
		{
			iter->StartCiculation(date);
			iter->SetNewOwner();
		}
		++iter;
	}
}

void Library::PassOn(string bookName, Date date)
{
	list<Book>::iterator iter = _bookListActive.begin();
	
	
	while (iter != _bookListActive.end())
	{
		
		bool setNewOwner = false;
		if (iter->GetName() == bookName)
		{
			if (iter->IsArchived())
			{
				iter->GetOwner()->SetRetainTime(iter->GetPreviousPass(date), date);
				_bookListArchived.push_back(*iter);
				iter = _bookListActive.erase(iter);
				while (iter != _bookListActive.end())
				{
					iter->SetBookPriority();
					++iter;
				}
				return;
			}
			else
			{
				setNewOwner = true;
				updateWaitTimes(*iter, date);
				iter->GetOwner()->SetRetainTime(iter->GetPreviousPass(date), date);
				//iter->SetBookPriority();
				//iter->SetNewOwner();
			}
		}
		iter->SetBookPriority();
		if (setNewOwner)
		{
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

void Library::updateWaitTimes(Book &book, Date date)
{
	book.updateWaitTimes(date);
}

