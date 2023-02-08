
#include "Main.h"
#include "demo/FactoryDemo.h"
#include "demo/ClientDemo.h"
#include <string>
#include <optional>
#include <StringUtils.h>
#include <iostream>

int main()
{
	
	std::cout << "LOOOOOOOO " << utils::generateUUID() << std::endl;
	demo::simulateClientProcess();

	std::cout << std::endl;
	demo::defaulBfvDemo();
	return 0;
}
