// Auch wenn man Debugt wird die Release lib von Python importiert
#pragma once
#ifdef _DEBUG
#define _DEBUG_WAS_DEFINED 1
#undef _DEBUG
#endif

#include <Python.h>
//#include <arrayobject.h>

#ifdef _DEBUG_WAS_DEFINED
#define _DEBUG 1
#endif
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include "core_export.h"
#include <ctime>
#include <fstream>
#include <rapidjson/document.h>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>