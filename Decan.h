#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "User.h"
#include "Attendancelist.h"
#include "Marklist.h"
using namespace std;

class Decan : public User {
	Attendancelist* al;
	Marklist* ml;
public:
	Decan(Marklist* pl, Attendancelist* al) : User(pl, al) { this->al = al; this->al = al; }
	int getUserType() { return 2; }
	virtual vector<Mark>* getGroupMarks(string group) 
	{
		vector<Mark> GroupMarkArray;
		for (int i = 0; i < ml->getArray()->size() && ml->getArray()->size() != 0; i++)
		{
			if (ml->getArray()->at(i).getStudent().getGroup() == group) GroupMarkArray.push_back(ml->getArray()->at(i));
		}
		return &GroupMarkArray;
	}
	virtual vector<Mark>* getStreamMarks(string stream)
	{
		vector<Mark> StreamMarkArray;
		for (int i = 0; i < ml->getArray()->size() && ml->getArray()->size() != 0; i++)
		{
			if (ml->getArray()->at(i).getStudent().getStream() == stream) StreamMarkArray.push_back(ml->getArray()->at(i));
		}
		return &StreamMarkArray;
	}
	virtual vector<Mark>* getSubjectMarks(string subject)
	{
		vector<Mark> SubjectMarkArray;
		for (int i = 0; i < ml->getArray()->size() && ml->getArray()->size() != 0; i++)
		{
			if (ml->getArray()->at(i).getSubject() == subject) SubjectMarkArray.push_back(ml->getArray()->at(i));
		}
		return &SubjectMarkArray;
	}
	virtual void Expulsion(Student student, string status) {
		student.setStatus(status);
	}
};