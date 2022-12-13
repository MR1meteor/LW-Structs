#include "StudentElement.h"

ostream& operator << (ostream& os, const StudentElement* element)
{
	os << "Student | FIO: " << element->FIO << " Discipline: " << element->Discipline << endl;
	return os;
}