
#ifndef DATAOBJECT_H
#define DATAOBJECT_H
#include "DataTyp.h"
//#include "MainData.h"

namespace pipeline
{
//forward delcarationen
class DataTyp;

class DataObject
{
  public:
	const DataTyp *type;
	std::string Name = "";
	std::string MainDirPath;
	int Versionen = 0;
	std::array<int, 6> Aenderungsdatum;
	std::array<int, 6> Deadline = {};
	std::string PreviewPath = "";
	//pipeline::MainData *DataBaseInstanze;

	DataObject(const DataTyp *type,
			   std::string Name, int Versionen,
			   std::array<int, 6> Aenderungsdatum, std::vector<DataObject *> Inputs,
			   std::array<int, 6> Deadline);

	void add_input(DataObject *obj);
	void add_output(DataObject *obj);
	void open(std::string PyArgs);
	static DataObject *erstellen(const DataTyp *type,
								 std::string Name, std::vector<DataObject *> Inputs,
								 std::array<int, 6> Deadline);

	void sync();

  private:
	std::vector<DataObject *> Inputs;
	std::vector<DataObject *> Outputs;
};
} // namespace pipeline

#endif