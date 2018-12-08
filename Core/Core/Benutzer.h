#pragma once
#include <iostream>


using namespace std;

class Benutzer
{
public:
	string Name;

	Benutzer();
	~Benutzer();

};

Benutzer::Benutzer(string nam)
{
	Name = nam;
}

Benutzer::~Benutzer(string nam)
{
	Name = nam;
}