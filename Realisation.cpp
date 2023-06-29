#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Attendance.h"
#include "Attendancelist.h"
#include "Decan.h"
#include "Mark.h"
#include "Marklist.h"
#include "Student.h"
#include "Teacher.h"
#include "User.h"
using namespace std;

int main() 
{
    Marklist marks;
    Attendancelist attendance;
    string StudentSurname;
    bool correct = false, StillRunning = true, roleChosen = false;
    char dec;
    int value, num, num1;
    string subject, surname, date, value1, group, stream, subject;
    User* user;
    Student student;

    while (StillRunning)
    {
        correct = false;
        while (!correct && !roleChosen)
        {
            system("cls");
            cout << "Who are you?\nTeacher-1\nDecan-2\nStudent-3\n";
            char dec = getch();
            switch (dec)
            {
            case ('1'):
                user = new Teacher(&marks, &attendance);
                correct = 1;
                roleChosen = 1;
                break;
            case ('2'):
                user = new Decan(&marks, &attendance);
                correct = 1;
                roleChosen = 1;
                break;
            case ('3'):
                user = new Student(&marks, &attendance);
                cout << "Enter your surname - ";
                cin >> StudentSurname;
                user->setSurname(StudentSurname);
                correct = 1;
                roleChosen = 1;
                break;
            default:
                correct = 0;
                break;
            }
        }
        system("cls");
        correct = 0;
        switch (user->getUserType())
        {
        case (1):
        {
            cout << "Add new mark - 1\nAdd new attendance - 2\nChange mark - 3\nChange attendance - 4\nChange role - 5\nClose program - 6 " << endl;
            while (!correct)
            {
                fflush(stdin);
                dec = getch();
                switch (dec)
                {
                case('1'):
                {
                    system("cls");
                    correct = 1;
                    fflush(stdin);
                    cout << "Enter subject:";
                    getline(cin, subject);
                    cout << "Enter value:";
                    fflush(stdin);
                    cin >> value;
                    cout << "Enter student's surname:";
                    fflush(stdin);
                    getline(cin, surname);
                    student.setSurname(surname);
                    user->addMark(subject, value, student);
                    break;
                }
                case('2'):
                {
                    system("cls");
                    correct = 1;
                    fflush(stdin);
                    cout << "Enter subject:";
                    getline(cin, subject);
                    cout << "Enter value:";
                    fflush(stdin);
                    cin >> value1;
                    cout << "Enter student's surname:";
                    fflush(stdin);
                    getline(cin, surname);
                    student.setSurname(surname);
                    cout << "Enter date:";
                    cin >> date;
                    user->addAttendance(subject, value1, student, date);
                    break;
                }
                case('3'):
                {
                    correct = 1;
                    system("cls");
                    cout << "Enter index:";
                    cin >> num;
                    system("cls");
                    correct = 1;
                    fflush(stdin);
                    cout << "Enter new subject:";
                    getline(cin, subject);
                    cout << "Enter new value:";
                    cin >> value;
                    cout << "Enter new student's surname:";
                    fflush(stdin);
                    getline(cin, surname);
                    student.setSurname(surname);
                    user->changeMark(num, subject, value, student);
                    break;
                }
                case('4'):
                {
                    correct = 1;
                    system("cls");
                    cout << "Enter index:";
                    cin >> num;
                    system("cls");
                    correct = 1;
                    fflush(stdin);
                    cout << "Enter new subject:";
                    getline(cin, subject);
                    cout << "Enter new value:";
                    cin >> value1;
                    cout << "Enter new student's surname:";
                    fflush(stdin);
                    getline(cin, surname);
                    student.setSurname(surname);
                    cout << "Enter new date:";
                    fflush(stdin);
                    getline(cin, date);
                    user->changeAttendance(num, subject, value1, student, date);
                    break;
                }
                case('5'):
                {
                    roleChosen = 0;
                    correct = 1;
                    delete user;
                    break;
                }
                case('6'):
                {
                    StillRunning = 0;
                    correct = 1;
                    break;
                }
                default: correct = 0; break;
                }
            }
            break;
        }
        case (2):
        {
            cout << "Get group's marks - 1\nGet stream's marks - 2\nGet subject's marks - 3\nExpulsion student - 4\nChange role - 5\nClose program - 6" << endl;
            while (!correct)
            {
                fflush(stdin);
                dec = getch();
                switch (dec)
                {
                case('1'):
                {
                    correct = 1;
                    system("cls");
                    cout << "Enter group name: ";
                    getline(cin, group);
                    if (!user->getMarks()->empty())
                    {
                        for (int i = 0; i < user->getMarkList()->size() && student.getGroup() == group; i++)
                        {
                            cout << user->getMarks()->at(i).getStudent().getSurname() << "    "
                                << user->getMarks()->at(i).getValue() << "    " << user->getMarks()->at(i).getSubject() << endl;
                        }
                    }
                    else {
                        cout << "No marks\n";
                    }
                    getch();
                    break;
                }
                case('2'):
                {
                    correct = 1;
                    system("cls");
                    cout << "Enter stream name: ";
                    getline(cin, stream);
                    if (!user->getMarks()->empty())
                    {
                        for (int i = 0; i < user->getMarkList()->size() && student.getStream() == stream; i++)
                        {
                            cout << user->getMarks()->at(i).getStudent().getSurname() << "    "
                                << user->getMarks()->at(i).getValue() << "    " << user->getMarks()->at(i).getSubject() << endl;
                        }
                    }
                    else {
                        cout << "No marks\n";
                    }
                    getch();
                    break;
                }
                case('3'):
                {
                    correct = 1;
                    system("cls");
                    cout << "Enter subject name: ";
                    getline(cin, subject);
                    if (!user->getMarks()->empty())
                    {
                        Mark mark;
                        for (int i = 0; i < user->getMarkList()->size() && mark.getSubject() == subject; i++)
                        {
                            cout << user->getMarks()->at(i).getStudent().getSurname() << "    "
                                << user->getMarks()->at(i).getValue() << "    " << user->getMarks()->at(i).getSubject() << endl;
                        }
                    }
                    else {
                        cout << "No marks\n";
                    }
                    getch();
                    break;
                }
                case('4'):
                {
                    correct = 1;
                    cout << "Enter student's surname: ";
                    cin >> surname;
                    user->Expulsion(student, "expulsed");
                    break;
                }
                case('5'):
                {
                    roleChosen = 0;
                    correct = 1;
                    delete user;
                    break;
                }
                case('6'):
                {
                    StillRunning = 0;
                    correct = 1;
                    break;
                }
                default: correct = 0; break;

                }
            }
            break;
        }
        case (3):
        {
            cout << "Get marks - 1\nGet attendance - 2\nGet debts - 3\nGet spaces - 4\nChange role - 5\nClose program - 6" << endl;
            while (!correct)
            {
                fflush(stdin);
                dec = getch();
                switch (dec)
                {
                case('1'):
                {
                    correct = 1;
                    system("cls");
                    if (!user->getMarks()->empty())
                    {
                        for (int i = 0; i < user->getMarkList()->size() && student.getSurname() == user->getSurname(); i++)
                        {
                            cout << user->getMarks()->at(i).getStudent().getSurname() << "    "
                                << user->getMarks()->at(i).getValue() << "    " << user->getMarks()->at(i).getSubject() << endl;
                        }
                    }
                    else {
                        cout << "No marks\n";
                    }
                    getch();
                    break;
                }
                case('2'):
                {
                    correct = 1;
                    system("cls");
                    if (!user->getAttendance()->empty())
                    {
                        for (int i = 0; i < user->getAttendanceList()->size() && student.getSurname() == user->getSurname(); i++)
                        {
                            cout << user->getAttendance()->at(i).getStudent().getSurname() << "    "
                                << user->getAttendance()->at(i).getValue() << "    " << user->getAttendance()->at(i).getSubject() << endl;
                        }
                    }
                    else {
                        cout << "No marks\n";
                    }
                    getch();
                    break;
                }
                case('3'):
                {
                    correct = 1;
                    system("cls");
                    if (!user->getMarks()->empty())
                    {
                        for (int i = 0; i < user->getMarkList()->size() && student.getSurname() == user->getSurname(); i++)
                        {
                            if(user->getMarks()->at(i).getValue() == 2)
                                cout << user->getMarks()->at(i).getStudent().getSurname() << "    "
                                    << user->getMarks()->at(i).getValue() << "    " << user->getMarks()->at(i).getSubject() << endl;
                        }
                    }
                    else {
                        cout << "No marks\n";
                    }
                    getch();
                    break;
                }
                case('4'):
                {
                    correct = 1;
                    system("cls");
                    if (!user->getAttendance()->empty())
                    {
                        for (int i = 0; i < user->getAttendanceList()->size() && student.getSurname() == user->getSurname(); i++)
                        {
                            if (user->getAttendance()->at(i).getValue() == "H")
                            cout << user->getAttendance()->at(i).getStudent().getSurname() << "    "
                                << user->getAttendance()->at(i).getValue() << "    " << user->getAttendance()->at(i).getSubject() << endl;
                        }
                    }
                    else {
                        cout << "No marks\n";
                    }
                    getch();
                    break;
                }
                case('5'):
                {
                    roleChosen = 0;
                    correct = 1;
                    delete user;
                    break;
                }
                case('6'):
                {
                    StillRunning = 0;
                    correct = 1;
                    break;
                }
                default: correct = 0; break;

                }
            }
            break;
        }
        default:
        {
            cout << "error" << endl;
        }
        }
    }
    delete user;
}