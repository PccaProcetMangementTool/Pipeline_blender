
#ifndef MAINDATA_H
#define MAINDATA_H

#include "DataObject.h"
namespace pipeline

{
//forward delcarationen
class DataObject;

class MainData
{
public:
  std::string LokalPath;
  std::string CloudPath;

  std::vector<DataTyp *> DataTypes;
  std::vector<DataObject *> LokalObjects;

  MainData(std::string LokalPath, std::string CloudPath);
  DataTyp *newDataTyp(std::vector<std::string> *add_to_cache,
                      std::string ScriptName);
};
} // namespace pipeline
#endif