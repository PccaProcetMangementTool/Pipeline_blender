#pragma once
#include "apiClass.h"

//#include "utilis.h"

void apiClass::test_core_dll()
{
	/*
	Diese Funktion ist nur f�r daf�r gedacht, die dll zu testet.
	Die Funktion wird dann von der test_app.exe aufgerufen
	*/

	pipeline::MainData Instanze = pipeline::MainData("C:\\Users\\an-li\\Christian\\PipelineData\\Lokal",
	"C:\\Users\\an-li\\Christian\\PipelineData\\Cloud");
	std::vector<std::string> add_to_cache;
	pipeline::DataTyp *Scene = Instanze.newDataTyp(&add_to_cache, "Scene.py");
	pipeline::DataTyp *Shoot = Instanze.newDataTyp(&add_to_cache, "Shoot.py");
	
}
apiClass::apiClass()
{

	printf("apiClass wurde erstellt\n");
}
apiClass::~apiClass()
{
	// Destuktor
}