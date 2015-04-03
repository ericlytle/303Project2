#pragma once
#include "Date.h"

using namespace std;

class Employee
{
public:
	Employee();
	Employee(string name);
	int GetRetainTime();
	int GetWaitTime();
	string GetName();
	void SetName(string name);
	void SetRetainTime(Date dateReceived, Date dateReturned);
	void SetWaitTime(Date circStart, Date passedNext);
	const int Priority() const;
	
	// compares Priority
	const bool operator==(const Employee other) const;
	const bool operator!=(const Employee other) const;
	const bool operator<(const Employee other) const;
	const bool operator>(const Employee other) const;
	const bool operator<=(const Employee other) const;
	const bool operator>=(const Employee other) const;

private:
	int SubtractDate(Date first, Date second);	
	int _waitTime;
	int _retainTime;
	string _name;
};

Employee::Employee()
{
	_waitTime = _retainTime = 0;
}

Employee::Employee(string name)
{
	_waitTime = _retainTime = 0;
	_name = name;
}

int Employee::GetRetainTime()
{
	return _retainTime;
}

int Employee::GetWaitTime()
{
	return _waitTime;
}

string Employee::GetName()
{
	return _name;
}

void Employee::SetName(string name)
{
	_name = name;
}

void Employee::SetRetainTime(Date circStart, Date dateReturned)
{
	_retainTime += SubtractDate(circStart,dateReturned);
}

void Employee::SetWaitTime(Date circStart, Date passedNext)
{
	_waitTime += SubtractDate(circStart, passedNext);
}

//Ensures smaller date is always subtracted from larger date, returns int of days difference.
int Employee::SubtractDate(Date first, Date second)
{
	if (first > second)
		return first - second;
	return second - first;
}

//Returns the priority of each employee.
const int Employee::Priority() const 
{
	return _waitTime - _retainTime;
}

const bool Employee::operator==(const Employee other) const
{
	return this->Priority() == other.Priority();
}

const bool Employee::operator!=(const Employee other) const
{
	return this->Priority() != other.Priority();
}

const bool Employee::operator<(const Employee other) const
{
	return this->Priority() < other.Priority();
}

const bool Employee::operator>(const Employee other) const
{
	return this->Priority() > other.Priority();
}

const bool Employee::operator<=(const Employee other) const
{
	return this->Priority() <= other.Priority();
}

const bool Employee::operator>=(const Employee other) const
{
	return this->Priority() >= other.Priority();
}
