#include "Students.h"
#include "Disciplines.h"
#include "DisciplineElement.h"

void AddStudent(Students* list, Disciplines* disciplinesList, string fio, string discipline = "")
{
	StudentElement* newElement = new StudentElement{ nullptr, fio };

	if (fio.empty())
	{
		throw "Parameter 'FIO' can't be empty";
	}

	try
	{
		DisciplineElement* disciplineElement = GetDiscipline(disciplinesList, discipline);
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

void InsertStudent(Students* list, Disciplines* disciplinesList, int index, string fio, string discipline = "")
{
	if (list->Length < index)
		throw "Out of length";

	if (index < 0)
		throw "Wrong index";

	if (list->Length == index)
	{
		try
		{
			AddStudent(list, disciplinesList, fio, discipline);
			return;
		}
		catch (const char* msg)
		{
			throw msg;
		}
	}


	StudentElement* newElement = new StudentElement{ nullptr, fio };

	StudentElement* previousElement = nullptr;
	StudentElement* currentElement = list->Head;

	try
	{
		DisciplineElement* disciplineElement = GetDiscipline(disciplinesList, discipline);
		newElement->Discipline = discipline;
	}
	catch (const char* msg)
	{
		cout << "Exception: " << msg << " => Student added without discipline" << endl;
	}

	if (index == 0)
	{
		list->Head = newElement;
		newElement->Next = currentElement;
		list->Length++;
		return;
	}

	for (int i = 0; i < index; i++)
	{
		previousElement = currentElement;
		currentElement = currentElement->Next;
	}

	previousElement->Next = newElement;
	newElement->Next = currentElement;
	list->Length++;
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

StudentElement* GetStudent(Students* list, int index)
{
	if (list->Length <= index)
		throw "Out of length";

	if (index < 0)
		throw "Wrong index";

	StudentElement* currentElement = list->Head;

	for (int i = 0; i < index; i++)
		currentElement = currentElement->Next;

	return currentElement;
}

Students* GetStudents(Students* list, Disciplines* disciplinesList, string discipline)
{
	Students* students = new Students();

	StudentElement* currentElement = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		if (currentElement->Discipline == discipline)
		{
			try
			{
				AddStudent(students, disciplinesList, currentElement->FIO, currentElement->Discipline);
			}
			catch (const char* msg)
			{
				cout << "Exception: " << msg << endl;
			}
		}

		currentElement = currentElement->Next;
	}

	return students;
}

void DeleteStudentsList(Students* list)
{
	if (list->Length == 0)
	{
		delete list;
		list = nullptr;
		return;
	}

	StudentElement* elementToDelete = nullptr;
	StudentElement* currentElement = list->Head;

	for (int i = 0; i < list->Length; i++)
	{
		elementToDelete = currentElement;
		currentElement = currentElement->Next;

		delete elementToDelete;
	}

	delete list;
	list = nullptr;
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