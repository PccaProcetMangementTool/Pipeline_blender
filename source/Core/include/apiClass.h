#pragma once
#include "include_python.h"
#include "core_export.h"
class CORE_EXPORT apiClass {
	/*
	In dieser Klasse sind alle Exportierten Funktionen exportiert
	Vieleicht werden wir auch mehr als eine Klasse exportieren, wuerde es aber besser finden, wenn wir nur diese Exportieren
	*/
public:
	apiClass();
	~apiClass();
	void test_core_dll();
};