#include "apiClass.h"
#include <iostream>

int main(int argc, char *argv[])
{
	try
	{
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