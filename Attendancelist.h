#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "Attendance.h"
using namespace std;

class Attendancelist
{
private:
    vector<Attendance> AttendancelistArray;
public:
    vector<Attendance>* getArray()
    {
        return &AttendancelistArray;
    }
    void addAttendance(string subject, string value, Student student, string date)
    {
        AttendancelistArray.push_back(Attendance(subject, value, student, date));
    }
    void changeAttendance(int index, string subject, string value, Student student, string date)
    {
        AttendancelistArray[index].change(subject, value, student, date);
    }
};