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
	void CirculateBook(string bookName, Date currentDate);
	void PassOn(string bookName, Date currentDate);
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

//Creates a new employee, adds them to the main employee list, and adds pointer to the employee
//in every active books queue.
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

//Passes a book into library circulation, gives book to highest priority employee in book queue.
void Library::CirculateBook(string bookName, Date currentDate)
{
	list<Book>::iterator iter = _bookListActive.begin();
	while (iter != _bookListActive.end())
	{
		if (iter->GetName() == bookName)
		{
			iter->StartCiculation(currentDate);
			iter->SetNewOwner(currentDate, currentDate);
		}
		++iter;
	}
}

//Updates info of current owner of book and passes book to next owner which is popped from queue, if book queue 
//is empty, the book is archived and removed from active book list.
void Library::PassOn(string bookName, Date currentDate)
{
	list<Book>::iterator iter = _bookListActive.begin();	
	while (iter != _bookListActive.end())
	{
		if (iter->GetName() == bookName)
		{
			if (iter->IsEmpty())
			{
				iter->GetOwner()->SetRetainTime(iter->GetPreviousPass(currentDate), currentDate);
				archiveBook(*iter, iter);
				return;
			}
			else
			{
				iter->GetOwner()->SetRetainTime(iter->GetPreviousPass(currentDate), currentDate);
				iter->SetNewOwner(iter->GetCirculationDate(), currentDate);
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

//Removes book from active list and places in archived list.
void Library::archiveBook(Book& book, list<Book>::iterator& iter)
{
	iter->Archive();
	_bookListArchived.push_back(book);
	_bookListActive.erase(iter);
}
