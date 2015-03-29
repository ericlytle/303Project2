

#pragma once

#include "Date.h"

using namespace std;

const string STARTDATE = "1-1-2000";

class Employee
{
public:
	Employee();
	Employee(string name);
	Date GetRetainTime();
	Date GetWaitTime();
	string GetName();
	void SetName(string name);
	void SetRetainTime(Date dateReceived, Date dateReturned);
	void SetWaitTime(Date passed, Date passedNext);

	bool operator <(const Employee& other) const;
	bool operator >(const Employee& other) const;
	bool operator ==(const Employee& other) const;
	bool operator !=(const Employee& other) const;
	bool operator <=(const Employee& other) const;
	bool operator >=(const Employee& other) const;

private:
	int SubtractDate(Date first, Date second);
	Date _retainTime;  //this date starts at 1-1-2000, will increase using .add_days(dateReturned - dateRecieved)
	Date _waitTime;		//this date starts at 1-1-2000
	string _name;
};

Employee::Employee()
{
	Date startDate(STARTDATE, DateFormat::US);
	_waitTime = _retainTime = startDate;
	_name = "";
}

Employee::Employee(string name)
{
	Date startDate(STARTDATE, DateFormat::US);
	_waitTime = _retainTime = startDate;
	_name = name;
}

Date Employee::GetRetainTime()
{
	return _retainTime;
}

Date Employee::GetWaitTime()
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

void Employee::SetRetainTime(Date dateReceived, Date dateReturned)
{
	_retainTime.add_days(SubtractDate(dateReceived,dateReturned));
}

void Employee::SetWaitTime(Date passed, Date passedNext)
{
	_waitTime.add_days(SubtractDate(passed,passedNext));
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
	return other < *this;
}
bool Employee::operator ==(const Employee& other) const
{
	return ((_waitTime == other._waitTime) && (_retainTime == other._retainTime));
}
bool Employee::operator !=(const Employee& other) const
{
	return ((_waitTime != other._waitTime) || (_retainTime != other._retainTime));
}
bool Employee::operator <=(const Employee& other) const
{
	return this->operator<(other) || this->operator==(other);
}
bool Employee::operator >=(const Employee& other) const
{
	return this->operator>(other) || this->operator==(other);
}

int Employee::SubtractDate(Date first, Date second)
{
	if (first > second)
		return first - second;
	return second - first;
}