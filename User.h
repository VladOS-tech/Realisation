#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "Mark.h"
#include "Marklist.h"
#include "Attendance.h"
#include "Attendancelist.h"
using namespace std;

class User {

public:
    virtual int getUserType() = 0;
    Marklist* currentMarklist;
    Attendancelist* currentAttendancelist;
    vector<Mark>* getMarkList()
    {
        return currentMarklist->getArray();
    };
    vector<Attendance>* getAttendanceList()
    {
        return currentAttendancelist->getArray();
    };
    User() {};
    User(Marklist* ml, Attendancelist* al)
    {
        currentMarklist = ml;
        currentAttendancelist = al;
    }

    //teacher
    virtual void addMark(string subject, int value, Student student) {};
    virtual void addAttendance(string subject, string value, Student student, string date) {};
    virtual void changeMark(int index, string subject, int value, Student student) {};
    virtual void changeAttendance(int index, string subject, string value, Student student, string date) {};

    //student
    virtual vector<Mark>* getMarks() {};
    virtual vector<Attendance>* getAttendance() {};
    virtual vector<Mark>* getDebts() {};
    virtual vector<Attendance>* getSpaces() {};

    //decan
    virtual vector<Mark>* getGroupMarks(string group) {};
    virtual vector<Mark>* getStreamMarks(string stream) {};
    virtual vector<Mark>* getSubjectMarks(string subject) {};
    virtual void Expulsion() {};
};