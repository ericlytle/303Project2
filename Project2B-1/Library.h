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
	void archiveBook(Book& book, list<Book>::iterator& iter);

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
			iter->SetNewOwner(date, date);
		}
		++iter;
	}
}

void Library::PassOn(string bookName, Date date)
{
	list<Book>::iterator iter = _bookListActive.begin();	
	while (iter != _bookListActive.end())
	{
		if (iter->GetName() == bookName)
		{
			if (iter->IsEmpty())
			{
				iter->GetOwner()->SetRetainTime(iter->GetPreviousPass(date), date);
				archiveBook(*iter, iter);
				return;
			}
			else
			{
				iter->GetOwner()->SetRetainTime(iter->GetPreviousPass(date), date);
				iter->SetNewOwner(iter->GetCirculationDate(),date);
			}
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

void Library::archiveBook(Book& book, list<Book>::iterator& iter)
{
	iter->Archive();
	_bookListArchived.push_back(book);
	_bookListActive.erase(iter);
}
