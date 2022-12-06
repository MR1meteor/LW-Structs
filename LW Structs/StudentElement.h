#pragma once
#include <iostream>

using namespace std;

struct StudentElement
{
	StudentElement* Next = nullptr;
	
	string FIO = "";
	string Discipline = "";
};