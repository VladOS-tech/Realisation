#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "Mark.h"
#include "Student.h"
using namespace std;

class Marklist
{
private:
    vector<Mark> MarklistArray;
public:
    vector<Mark>* getArray()
    {
        return &MarklistArray;
    }
    void addMark(string subject, int value, Student student)
    {
        MarklistArray.push_back(Mark(subject, value, student));
    }
    void changeMark(int index, string subject, int value, Student student)
    {
        MarklistArray[index].change(subject, value, student);
    }
};