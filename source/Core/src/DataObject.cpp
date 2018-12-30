
#include "DataObject.h"

DataObject::DataObject(//DataTyp *type,
 std::string Name, int Versionen,
                       std::array<int, 3> Aenderungsdatum, std::string LokalPath,
                       std::string OneDrivePath, std::array<int, 3> Deadline)
{
    
    //this->type = type;
    this->Name = Name;
    this->Versionen = Versionen;
    this->Aenderungsdatum = Aenderungsdatum;
    this->LokalPath = LokalPath;
    this->OneDrivePath = OneDrivePath;
    this->Deadline = Deadline;
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