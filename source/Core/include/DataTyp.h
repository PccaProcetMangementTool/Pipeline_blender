#pragma once
//#include "DataObject.h"
//include "includes.h"
#include "pipeline_utilis.h"
#include "MainData.h"
namespace py = pybind11;

namespace pipeline{
class MainData;

class DataTyp
{
  public:
    std::string TypName;
    std::string PythonScriptFile;
    std::vector<DataTyp *> ErlaubteInputs;
    std::vector<DataTyp *> ErlaubteOutputs;
    std::vector<DataTyp *> AbleitbareDataTypen;
    py::module Script;
    MainData* Instanze;

    DataTyp(std::string PythonScriptFile,std::vector<std::string> *add_to_cache,
     rapidjson::Document *json_doc, MainData* Instanze);
    ~DataTyp();
    
};
}