#pragma once
#include "DisciplineElement.h"

struct Disciplines
{
	DisciplineElement* Head = nullptr;
	DisciplineElement* Tail = nullptr;
	int Length = 0;
};

void AddDiscipline(Disciplines* list, string name);

void InsertDiscipline(Disciplines* list, int index, string name);

void DeleteDiscipline(Disciplines* list, int index);

DisciplineElement* GetDiscipline(Disciplines* list, int index);

DisciplineElement* GetDiscipline(Disciplines* list, string name);

void DeleteDisciplinesList(Disciplines* list);

ostream& operator << (ostream& os, const Disciplines* list);