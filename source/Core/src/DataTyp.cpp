#pragma once
#include "DataTyp.h"
#include "utilis.h"


DataTyp::DataTyp(std::string PythonScriptfile)
{
    std::array<std::string,2> dir_file=pipeutilis::seperate_dir_file(PythonScriptfile);
    
    std::string ScriptName= dir_file[1];
    std::string PythonScriptPath= dir_file[0];

    py::scoped_interpreter guard{};
    py::module sys=py::module::import("sys");
    
    py::object paths=sys.attr("path");

    bool in_path=false;

    for (auto &path : paths)
    {
        if(path.cast<std::string>()==PythonScriptPath)
        {
            in_path=true;
            break;
        }
        
    }

    if(!in_path){
        paths.attr("append")(PythonScriptPath);
    }

    py::module mod = py::module::import(ScriptName.c_str());
    mod.attr("test")();


}
DataTyp::~DataTyp()
{

}