#include "pipeline_utilis.h"
namespace pipeutilis{

std::array<std::string, 2> seperate_dir_file(std::string path)
{
    std::size_t index = path.find_last_of("\\");
    std::size_t laenge = path.length();
    std::string dir=path.substr(0,index);
    std::string file=path.substr(index+1,laenge-index-4);
    return {dir,file};
}

std::array<int,6> getCurrentTime()
{   
    
    std::time_t t=std::time(NULL);
    struct tm* tmap= std::localtime(&t);
    std::array<int,6> time_array;
    
    
    time_array[0]= tmap->tm_year + 1900;
    time_array[1]= tmap->tm_mon + 1;
    time_array[2]= tmap->tm_mday;
    time_array[3]= tmap->tm_hour;
    time_array[4]= tmap->tm_min;
    time_array[5]= tmap->tm_sec;
    
    return time_array;
}

char* read_file(std::string path)
{
    std::streampos begin,end,size,eins;

    std::ifstream pc_cache;
    pc_cache.open(path.c_str(),std::ios::binary);

    begin=pc_cache.tellg();
    pc_cache.seekg(0,std::ios::end);
    end=pc_cache.tellg();
    
    size=end-begin;

    eins=1;
    char* buffer=new char[size+eins];
    pc_cache.seekg(0,std::ios::beg);

    pc_cache.read(buffer,size);
    
    pc_cache.close();
    buffer[size]=0;
    return buffer;
}

}