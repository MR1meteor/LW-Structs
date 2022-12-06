#pragma once
#include <iostream>

using namespace std;

struct DisciplineElement
{
	DisciplineElement* Next = nullptr;

	string Name = "";
};

ostream& operator << (ostream& os, const DisciplineElement* element);