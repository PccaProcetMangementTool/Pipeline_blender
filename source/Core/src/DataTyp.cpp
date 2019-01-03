#pragma once
#include "DataTyp.h"

namespace pipeline
{

DataTyp::DataTyp(std::string PythonScriptFile,
				 std::vector<std::string> *add_to_cache,
				 rapidjson::Document *json_doc)
{

	//std::vector<std::string> *add_to_cache;
	if(!json_doc->IsObject())
	{
		throw std::invalid_argument("die Funktion IsObject() vom Parameter des Typen rapidjson::Document ergibt False");
	}
	this->PythonScriptFile = PythonScriptFile;
	std::array<std::string, 2> dir_file = pipeutilis::seperate_dir_file(PythonScriptFile);

	std::string ScriptName = dir_file[1];
	std::string PythonScriptPath = dir_file[0];

	py::module sys = py::module::import("sys");

	py::object paths = sys.attr("path");

	bool in_path = false;

	for (auto &path : paths)
	{
		if (path.cast<std::string>() == PythonScriptPath)
		{
			in_path = true;
			break;
		}
	}

	if (!in_path)
	{
		paths.attr("append")(PythonScriptPath);
	}
	Script = py::module::import(ScriptName.c_str());
	py::object PyPc_Lokal_Cache = Script.attr("erstelle_Data_Typ")();

	std::string PathName;

	for (auto &Cache : PyPc_Lokal_Cache)
	{
		PathName = Cache.cast<std::string>();

		const char *c_str_PathName = PathName.c_str();
		
		if (!json_doc->HasMember(c_str_PathName))
		{
			add_to_cache->push_back(PathName);
		
		}else if (!json_doc->operator[](c_str_PathName).IsString())
		{
			add_to_cache->push_back(PathName);
		}
		
			
		
	}
}
DataTyp::~DataTyp()
{
}
} // namespace pipeline
