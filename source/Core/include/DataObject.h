#pragma once
#include "core_export.h"
#include "includes.h"
#include "DataTyp.h"


class DataObject{
    public:
        //DataTyp *type;
        std::string Name;
        int Versionen;
        std::array<int,3> Aenderungsdatum;
        std::string LokalPath;
        std::string OneDrivePath;
        std::array<int,3> Deadline;
        std::string PreviewPath;

        DataObject(//DataTyp *type
         std::string Name, int Versionen,
                   std::array<int, 3> Aenderungsdatum, std::string LokalPath,
                   std::string OneDrivePath, std::array<int, 3> Deadline);

        void add_input(DataObject* obj);
        void add_output(DataObject *obj);
    private:
        std::vector<DataObject *> Inputs;
        std::vector<DataObject *> Outputs;
        
		
    


};
