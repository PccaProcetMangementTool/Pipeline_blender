#include "Benutzer.hpp"

using namespace std;
Benutzer::Benutzer()
{

}

void Benutzer::setname(string nam)
{
	Name = nam;
	return;
}

string Benutzer::getname()
{
	return Name;
}