#include "stdafx.h"
#include "Kommentar.h"


Kommentar::Kommentar()
{
}


Kommentar::~Kommentar()
{
}

string Kommentar::get_text(bool lesen)
{
	gelesen = lesen;
	return text;
}
