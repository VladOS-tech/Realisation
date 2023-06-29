#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "User.h"
#include "Attendancelist.h"
#include "Marklist.h"
using namespace std;

class Teacher : public User {
public:
	Teacher(Marklist* ml, Attendancelist* al) : User(ml, al) {}
	int getUserType() { return 1; }
	virtual void addMark(string subject, int value, Student student) 
	{
		currentMarklist->addMark(subject, value, student);
	}
	virtual void addAttendance(string subject, string value, Student student, string date)
	{
		currentAttendancelist->addAttendance(subject, value, student, date);
	}
	virtual void changeMark(int index, string subject, int value, Student student)
	{
		currentMarklist->changeMark(index, subject, value, student);
	}
	virtual void changeAttendance(int index, string subject, string value, Student student, string date)
	{
		currentAttendancelist->changeAttendance(index, subject, value, student, date);
	}
};