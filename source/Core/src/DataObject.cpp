#pragma once
#include "DataObject.h"
namespace pipeline
{
DataObject::DataObject(const DataTyp *type,
					   std::string Name, int Versionen,
					   std::string Aenderungsdatum, std::vector<DataObject *> Inputs, 
					   std::array<int, 3> Deadline)
{
	//Var setzten
	this->type = type;
	this->Name = Name;
	this->Versionen = Versionen;
	this->Aenderungsdatum = Aenderungsdatum;
	this->Deadline = Deadline;

	//
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