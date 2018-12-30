#include"apiClass.h"
#include "DataTyp.h"




void apiClass::test_core_dll() {
	/*
	Diese Funktion ist nur f�r daf�r gedacht, die dll zu testet.
	Die Funktion wird dann von der test_app.exe aufgerufen
	*/
	std::cout << "Hallo hier ist die test_core_dll Funktion\n";
	DataTyp("H:\\dev\\Pipeline\\Github\\Pipeline_blender\\source\\Python_Scripts\\Allgemeines_Script.py");
}
apiClass::apiClass() {
	
	
	
	
	
	
	
	printf("apiClass wurde erstellt\n");


}
apiClass::~apiClass() {
	// Destuktor
	
}