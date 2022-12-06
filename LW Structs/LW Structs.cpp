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
        DisciplineElement* el = new DisciplineElement();
        GetDiscipline(el, disciplinesList, 2);
        cout << el;
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }

    cout << disciplinesList << endl;


    Students* studentsList = new Students();

    AddStudent(studentsList, disciplinesList, "just fio1", "Second");
    AddStudent(studentsList, disciplinesList, "just fio2", "test disc2");
    AddStudent(studentsList, disciplinesList, "just fio3", "test disc3");

    try 
    {
        DeleteStudent(studentsList, -1);
    }
    catch (const char* msg) 
    {
        cout << "Exception: " << msg << endl;
    }
    
    cout << studentsList << endl;

    
}