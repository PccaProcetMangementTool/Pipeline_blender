#pragma once
#include <iostream>


using namespace std;
class Benutzer
{
public:
	Benutzer();
	void setname(string nam);
	string getname();
	
private:
	string Name;
};
