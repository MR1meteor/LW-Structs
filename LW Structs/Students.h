#pragma once
#include "StudentElement.h"
#include "Disciplines.h"

using namespace std;

struct Students
{
	StudentElement* Head = nullptr;
	StudentElement* Tail = nullptr;
	int Length = 0;
};

void AddStudent(Students* list, Disciplines* disciplinesList, string fio, string discipline);

void InsertStudent(Students* list, Disciplines* disciplinesList, int index, string fio, string discipline);

void DeleteStudent(Students* list, int index);

StudentElement* GetStudent(Students* list, int index);

Students* GetStudents(Students* list, Disciplines* disciplinesList, string discipline);

void DeleteStudentsList(Students* list);

ostream& operator << (ostream& os, const Students* list);