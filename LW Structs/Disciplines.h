#pragma once
#include "DisciplineElement.h"

struct Disciplines
{
	DisciplineElement* Head = nullptr;
	DisciplineElement* Tail = nullptr;
	int Length = 0;
};

void AddDiscipline(Disciplines* list, string name);

void DeleteDiscipline(Disciplines* list, int index);

void GetDiscipline(DisciplineElement* destination, Disciplines* list, int index);

void GetDiscipline(DisciplineElement* destination, Disciplines* list, string name);

ostream& operator << (ostream& os, const Disciplines* list);