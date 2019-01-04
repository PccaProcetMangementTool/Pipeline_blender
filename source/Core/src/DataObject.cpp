#pragma once
#include "DataObject.h"
namespace pipeline
{
DataObject::DataObject(const DataTyp *type,
					   std::string Name, int Versionen,
					   std::array<int, 6> Aenderungsdatum, std::vector<DataObject *> Inputs,
					   std::array<int, 6> Deadline)
{
	//Var setzten
	this->type = type;
	this->Name = Name;
	this->Versionen = Versionen;
	this->Aenderungsdatum = Aenderungsdatum;
	this->Deadline = Deadline;

	//erstellen
	for (DataObject *Input : Inputs)
	{
		this->add_input(Input);
	}
}

DataObject *DataObject::erstellen(const DataTyp *type,
								  std::string Name, std::vector<DataObject *> Inputs,
								  std::array<int, 6> Deadline)
{
	//Erstellt ein Object. Läd es nicht so wie der Konstruktor
	DataObject *newobj;
	newobj = new DataObject(type, Name, 0, pipeutilis::getCurrentTime(), Inputs, Deadline);

	//input list
	std::vector<std::vector<std::string>> input_list;

	std::vector<std::string> currentInput;

	for (DataObject *Input : Inputs)
	{
		currentInput = {Input->type->TypName, Input->MainDirPath};
		input_list.push_back(
			currentInput);
	}
	std::string PC_Lokal_Cache = type->Instanze->LokalPath + "\\Lokal_Cache\\Pc_Path_Cache.json";

	py::object PyMainDirPath = type->Script.attr("erstellen")(Name, input_list,
															  type->Instanze->LokalPath,
															  PC_Lokal_Cache);
	newobj=PyMainDirPath.cast<std::string>();

	return newobj;
}

void DataObject::add_input(DataObject *obj)
{
	for (int i = 0; i < Inputs.size(); i++)
	{
		if (Inputs[i] == obj)
			return;
	}
	Inputs.push_back(obj);
	obj->add_output(this);
}

void DataObject::add_output(DataObject *obj)
{
	for (int i = 0; i < Outputs.size(); i++)
	{
		if (Outputs[i] == obj)
		{
			return;
		}
	}
	Outputs.push_back(obj);
	obj->add_input(this);
}

void DataObject::open(std::string PyArgs)
{

	sync();
	this->type->Script.attr("open")();
}
void DataObject::sync()
{
}

} // namespace pipeline