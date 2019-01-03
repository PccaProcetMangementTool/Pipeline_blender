#pragma once
#include "includes.h"
namespace pipeutilis{

std::array<std::string, 2> seperate_dir_file(std::string path);

std::array<int,6> getCurrentTime();

char* read_file(std::string Path);
}