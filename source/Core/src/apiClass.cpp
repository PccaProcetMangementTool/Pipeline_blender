#pragma once
#include "apiClass.h"

//#include "utilis.h"

void apiClass::test_core_dll()
{
	/*
	Diese Funktion ist nur f�r daf�r gedacht, die dll zu testet.
	Die Funktion wird dann von der test_app.exe aufgerufen
	*/

	pipeline::MainData Instanze = pipeline::MainData("H:\\dev\\Pipeline\\tests\\Data\\Lokal", "H:\\dev\\Pipeline\\tests\\Data\\Cloud");
	std::vector<std::string> add_to_cache;
	pipeline::DataTyp *Allgemein_Data = Instanze.newDataTyp(&add_to_cache, "Allgemeines_Script.py");
	
}
apiClass::apiClass()
{

	printf("apiClass wurde erstellt\n");
}
apiClass::~apiClass()
{
	// Destuktor
}