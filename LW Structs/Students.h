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

void InsertStudent(Students* list, int index, string fio, string discipline = "");

void DeleteStudent(Students* list, int index);

ostream& operator << (ostream& os, const Students* list);