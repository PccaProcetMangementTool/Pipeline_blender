#include "MainData.h"

pipeline::MainData::MainData(std::string LokalPath,
                             std::string CloudPath)
{
    this->LokalPath = LokalPath;
    this->CloudPath = CloudPath;
}
pipeline::DataTyp *pipeline::MainData::newDataTyp(std::vector<std::string> *add_to_cache,
                                        std::string ScriptName)
{
    
    rapidjson::Document PyPc_Cache;

    //Pc_Cache.open(this->LokalPath + "\\Lokal_Cache\\Pc_Path_Cache.json", std::ios::in);
    std::string path=this->LokalPath + "\\Lokal_Cache\\Pc_Path_Cache.json";
    
    
    char* buffer=pipeutilis::read_file(path);

    PyPc_Cache.Parse(buffer);
    
    
    std::cout<<"\nVor Funktion "<<PyPc_Cache.IsObject()<<"\n";
    DataTyp *currentDataTyp = &pipeline::DataTyp(this->CloudPath + "\\Python\\Scripts\\" + ScriptName,
                                                add_to_cache, &PyPc_Cache);
    this->DataTypes.push_back(currentDataTyp);
    return currentDataTyp;

}