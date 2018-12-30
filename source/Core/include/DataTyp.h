#pragma once
#include "DataObject.h"
#include "includes.h"


namespace py = pybind11;

class DataTyp
{
  public:
    std::string TypName;
    std::string PythonScriptPath;
    std::vector<DataTyp *> ErlaubteInputs;
    std::vector<DataTyp *> ErlaubteOutputs;
    std::vector<DataTyp *> AbleitbareDataTypen;
    py::module Script;

    DataTyp(std::string PythonScriptPath);
    ~DataTyp();
};
