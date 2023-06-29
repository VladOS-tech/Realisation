#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "User.h"
#include "Attendancelist.h"
#include "Marklist.h"
using namespace std;

class Student : public User {
private:
    string surname, group, stream, status;
    Attendancelist* al;
    Marklist* ml;
public:
    Student(Marklist* pl, Attendancelist* al) : User(pl, al) { this->al = al; this->al = al; }
    int getUserType() { return 3; }
    Student() { surname = "Ivanov"; group = "IS1"; stream = "IS"; status = "Learning"; }
    string getSurname() { return surname; }
    string getGroup() { return group; }
    string getStream() { return stream; }
    string getStatus() { return status; }
    void setStatus(string status) { this->status = status; }
    void setSurname(string surname) { this->surname = surname; }
    virtual vector<Attendance>* getAttendance()
    {
        vector<Attendance> AttendanceArray;
        for (int i = 0; i < al->getArray()->size() && al->getArray()->size() != 0; i++)
        {
            if (al->getArray()->at(i).getStudent().getSurname() == surname) AttendanceArray.push_back(al->getArray()->at(i));
        }
        return &AttendanceArray;
    }
    virtual vector<Mark>* getMarks()
    {
        vector<Mark> MarkArray;
        for (int i = 0; i < ml->getArray()->size() && ml->getArray()->size() != 0; i++)
        {
            if (ml->getArray()->at(i).getStudent().getSurname() == surname) MarkArray.push_back(ml->getArray()->at(i));
        }
        return &MarkArray;
    }
    virtual vector<Mark>* getDebts() 
    {
        vector<Mark> DebtArray;
        for (int i = 0; i < ml->getArray()->size() && ml->getArray()->size() != 0; i++)
        {
            if (ml->getArray()->at(i).getStudent().getSurname() == surname && ml->getArray()->at(i).getValue() == 2) DebtArray.push_back(ml->getArray()->at(i));
        }
        return &DebtArray;
    }
    virtual vector<Attendance>* getSpaces() 
    {
        vector<Attendance> SpaceArray;
        for (int i = 0; i < al->getArray()->size() && al->getArray()->size() != 0; i++)
        {
            if (al->getArray()->at(i).getStudent().getSurname() == surname && al->getArray()->at(i).getValue() == "H") SpaceArray.push_back(al->getArray()->at(i));
        }
        return &SpaceArray;
    }
};