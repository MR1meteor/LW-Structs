#include "Disciplines.h"

void AddDiscipline(Disciplines* list, string name)
{
	DisciplineElement* newElement = new DisciplineElement{ nullptr, name };


	if (list->Length == 0)
	{
		list->Head = newElement;
		list->Tail = newElement;
		list->Length++;
		return;
	}

	list->Tail->Next = newElement;
	list->Tail = newElement;
	list->Length++;
}

void DeleteDiscipline(Disciplines* list, int index)
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
	}

	if (index == 0)
	{
		DisciplineElement* meta = list->Head;
		list->Head = list->Head->Next;
		list->Length--;
		delete(meta);
		return;
	}

	DisciplineElement* previousElement = nullptr;
	DisciplineElement* currentElement = list->Head;

	for (int i = 0; i < index; i++)
	{
		previousElement = currentElement;
		currentElement = currentElement->Next;
	}

	previousElement->Next = currentElement->Next;
	list->Length--;
	delete(currentElement);
}

void GetDiscipline(DisciplineElement* destination, Disciplines* list, int index)
{
	if (list->Length <= index)
		throw "Out of length";

	if (index < 0)
		throw "Wrong index";

	DisciplineElement* currentElement = list->Head;

	for (int i = 0; i < index; i++)
		currentElement = currentElement->Next;

	*destination = *currentElement;
}

void GetDiscipline(DisciplineElement* destination, Disciplines* list, string name)
{
	bool success = false;
	DisciplineElement* currentElement = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		if (currentElement->Name == name)
		{
			success = true;
			break;
		}

		currentElement = currentElement->Next;
	}

	if (success)
		*destination = *currentElement;
	else
		throw "Wrong discipline name";
}

ostream& operator << (ostream& os, const Disciplines* list)
{
	DisciplineElement* currentElement = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		os << i << " | " << "Name: " << currentElement->Name << endl;
		currentElement = currentElement->Next;
	}

	return os;
}