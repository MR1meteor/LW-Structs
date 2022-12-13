#include <iostream>
#include "Students.h"
#include "Disciplines.h";

int main()
{
    Disciplines* disciplinesList = new Disciplines();

    AddDiscipline(disciplinesList, "First");
    AddDiscipline(disciplinesList, "Second");
    try
    {
        InsertDiscipline(disciplinesList, 1, "Tirst");
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }

    try
    {
        DisciplineElement* el = GetDiscipline(disciplinesList, 2);
        cout << el;
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }

    cout << disciplinesList << endl;



    Students* studentsList = new Students();

    try
    {
        AddStudent(studentsList, disciplinesList, "just fio1", "Second");
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }


    try
    {
        InsertStudent(studentsList, disciplinesList, 1, "just fio15", "Second");
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }

    try
    {
        AddStudent(studentsList, disciplinesList, "just fio2", "test disc2");
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }


    try
    {
        AddStudent(studentsList, disciplinesList, "just fio3", "Second");
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }


    try
    {
        DeleteStudent(studentsList, -1);
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }


    cout << studentsList << endl;


    try
    {
        StudentElement* el = GetStudent(studentsList, 2);
        cout << el;
    }
    catch (const std::exception&)
    {

    }

    DeleteStudentsList(studentsList);
    DeleteDisciplinesList(disciplinesList);
}