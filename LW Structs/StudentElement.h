#pragma once
#include <iostream>

using namespace std;

struct StudentElement
{
	StudentElement* Next = nullptr;
	
	string FIO = "";
	string Discipline = "";
};

ostream& operator << (ostream& os, const StudentElement* element);