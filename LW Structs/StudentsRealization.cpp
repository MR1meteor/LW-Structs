#include "Students.h"
#include "Disciplines.h"
#include "DisciplineElement.h"

void AddStudent(Students* list, Disciplines* disciplinesList, string fio, string discipline = "")
{
	StudentElement* newElement = new StudentElement{ nullptr, fio };

	try
	{
		DisciplineElement* disciplineElement = new DisciplineElement();
		GetDiscipline(disciplineElement, disciplinesList, discipline);
		newElement->Discipline = discipline;
	}
	catch (const char* msg)
	{
		cout << "Exception: " << msg << " => Student added without discipline" << endl;
	}

	if (list->Length == 0)
	{
		list->Head = newElement;
		list->Tail = newElement;
		list->Length++;
		//throw "Element added successfully";
		return;
	}

	list->Tail->Next = newElement;
	list->Tail = newElement;
	list->Length++;
	//throw "Element added successfully";
}

void DeleteStudent(Students* list, int index)
{
	if (list->Length <= index)
		throw "Out of length";

	if (index < 0)
		throw "Wrong index";

	if (list->Length == 1)
	{
		delete(list->Head);
		list->Head = nullptr;
		list->Tail = nullptr;
		list->Length--;
		return;
		//throw "Element deleted successfully";
	}

	if (index == 0)
	{
		StudentElement* meta = list->Head;
		list->Head = list->Head->Next;
		list->Length--;
		delete(meta);
		return;
		//throw "Element deleted successfully";
	}

	StudentElement* previousElement = nullptr;
	StudentElement* currentElement = list->Head;

	for (int i = 0; i < index; i++)
	{
		previousElement = currentElement;
		currentElement = currentElement->Next;
	}

	previousElement->Next = currentElement->Next;
	list->Length--;
	delete(currentElement);
	//throw "Element deleted successfully";
}

ostream& operator << (ostream& os, const Students* list)
{
	StudentElement* currentElement = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		os << i << " | " << "FIO: " << currentElement->FIO << " Discipline: " << currentElement->Discipline << endl;
		currentElement = currentElement->Next;
	}

	return os;
}