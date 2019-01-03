
#ifndef DATAOBJECT_H
#define DATAOBJECT_H
#include "DataTyp.h"
#include "MainData.h"

namespace pipeline
{
//forward delcarationen
class MainData;

class DataObject
{
public:
	const DataTyp *type;
	std::string Name = "";
	int Versionen = 0;
	std::string Aenderungsdatum = "";
	std::array<int, 3> Deadline = {};
	std::string PreviewPath = "";
	pipeline::MainData *DataBaseInstanze;

	DataObject(const DataTyp *type,
						 std::string Name, int Versionen,
						 std::string Aenderungsdatum, std::vector<DataObject *> Inputs,
						 std::array<int, 3> Deadline);

	void add_input(DataObject *obj);
	void add_output(DataObject *obj);
	void open(std::string PyArgs);
	void sync();

private:
	std::vector<DataObject *> Inputs;
	std::vector<DataObject *> Outputs;
};
} // namespace pipeline

#endif