#include"apiClass.h"
#include<iostream>

#include <pybind11/pybind11.h>

void apiClass::test_core_dll() {
	/*
	Diese Funktion ist nur für dafür gedacht, die dll zu testet.
	Die Funktion wird dann von der test_app.exe aufgerufen
	*/
	std::cout << "Hallo hier ist die test_core_dll Funktion\n";
}
apiClass::apiClass() {
	printf("apiClass wurde erstellt\n");
}
apiClass::~apiClass() {
	// Destuktor
}