#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "Student.h"
using namespace std;

class Attendance
{
private:
    string subject, value, date;
    Student student;
public:
    string getValue() { return value; }
    string getSubject() { return subject; }
    Student getStudent() { return student; }
    string getDate() { return date; }
    void setAttendance(string value, string subject, Student student, string date)
    {
        this->value = value;
        this->subject = subject;
        this->student = student;
        this->date = date;
    }
    Attendance() {};
    Attendance(string subject, string value, Student student, string date)
    {
        this->subject = subject;
        this->value = value;
        this->student = student;
        this->date = date;
    }
    void change(string subject, string value, Student student, string date)
    {
        this->subject = subject;
        this->value = value;
        this->student = student;
        this->date = date;
    }
};