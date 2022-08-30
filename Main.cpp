
#include "Main.h"
#include "demo/FactoryDemo.h"
#include "demo/ClientDemo.h"
#include <string>
#include <optional>

int main()
{
	demo::simulateClientProcess();

	std::cout << std::endl;
	demo::defaulBfvDemo();
	return 0;
}
