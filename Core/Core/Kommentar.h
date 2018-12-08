#pragma once
#include <iostream>
using namespace std;
class Kommentar
{
private:
	string text;
	Benutzer kommentar_user;
public:
	Kommentar(string geschriebener Text, Benutzer user,String );
	~Kommentar();
	bool gelesen;
	string get_text(bool lesen=true);
};

