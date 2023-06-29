#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "Student.h"
using namespace std;

class Mark
{
private:
    int value;
    string subject;
    Student student;
public:
    int getValue() { return value; }
    string getSubject() { return subject; }
    Student getStudent() { return student; }
    void setMark(int value, string subject, Student student)
    {
        this->value = value;
        this->subject = subject;
        this->student = student;
    }
    Mark() {};
    Mark(string subject, int value, Student student)
    {
        this->subject = subject;
        this->value = value;
        this->student = student;
    }
    void change(string subject, int value, Student student)
    {
        this->subject = subject;
        this->value = value;
        this->student = student;
    }
};