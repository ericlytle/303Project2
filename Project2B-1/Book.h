#pragma once

#include "Date.h"
#include "EmployeeQueue.h"

using namespace std;

class Book
{
public:
	Book();
	Book(string name);
	bool IsArchived();
	Date CirculationStart();
	Date CirculationStop();
	string Name();
	void CirculationStart(Date date);
	void CirculationStop(Date date);
	void Archive();
	void Name(string name);
	void PassOn();
private:
	bool _isArchived;
	Date _circulationStart;
	Date _circulationStop;
	EmployeeQueue _waitingForThisBook;
	string _name;
};