#include "apiClass.h"
#include <iostream>

int main(int argc, char *argv[])
{
	try
	{
		pybind11::scoped_interpreter guard{};
		apiClass test;
		test.test_core_dll();
		
		
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	system("PAUSE");
	return 0;
}