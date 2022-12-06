#include "DisciplineElement.h"

ostream& operator << (ostream& os, const DisciplineElement* element)
{
	os << "Discipline: " << element->Name << endl;
	return os;
}