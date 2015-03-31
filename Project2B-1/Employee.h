

#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

const string STARTDATE = "1-1-2012";

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

	bool operator <(const Employee& other) const;
	bool operator >(const Employee& other) const;
	bool operator ==(const Employee& other) const;
	bool operator !=(const Employee& other) const;
	bool operator <=(const Employee& other) const;
	bool operator >=(const Employee& other) const;

private:
	int SubtractDate(Date first, Date second);
	//Date _retainTime;  //this date starts at 1-1-2000, will increase using .add_days(dateReturned - dateRecieved)
	//Date _waitTime;		//this date starts at 1-1-2000
	int _waitTime;
	int _retainTime;
	string _name;
};

Employee::Employee()
{
	//Date startDate(STARTDATE, DateFormat::US);
	//_waitTime = _retainTime = startDate;
	_waitTime = _retainTime;
	_name = "";
}

Employee::Employee(string name)
{
	//Date startDate(STARTDATE, DateFormat::US);
	//_waitTime = _retainTime = startDate;
	_waitTime = _retainTime;
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

bool Employee::operator <(const Employee& other) const
{
	if (_waitTime < other._waitTime)
		return true;
	if (_waitTime > other._waitTime)
		return false;
	if ((_waitTime == other._waitTime) && (_retainTime > other._retainTime))
		return true;
	return false;
}
bool Employee::operator >(const Employee& other) const
{
	return other.Priority() < (*this).Priority();
}
bool Employee::operator ==(const Employee& other) const
{
	return other.Priority() == Priority();
}
bool Employee::operator !=(const Employee& other) const
{
	return other.Priority() != Priority();
}
bool Employee::operator <=(const Employee& other) const
{
	return other.Priority() <= Priority();
}
bool Employee::operator >=(const Employee& other) const
{
	return other.Priority() >= Priority();
}

int Employee::SubtractDate(Date first, Date second)
{
	if (first > second)
		return first - second;
	return second - first;
}

const int Employee::Priority() const
{
	return _waitTime > _retainTime ? _waitTime - _retainTime : 0;
}