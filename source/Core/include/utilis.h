#include "includes.h"
namespace pipeutilis{

std::array<std::string, 2> seperate_dir_file(std::string path)
{
    std::size_t index = path.find_last_of("\\");
    std::size_t laenge = path.length();
    std::string dir=path.substr(0,index);
    std::string file=path.substr(index+1,laenge-index-4);
    return {dir,file};
}
}