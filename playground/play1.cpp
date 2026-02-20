#include <iostream>
#include <string>
#include <iomanip>

int	main()
{
	std::string	input;

	// std::cout << "|" << std::left << std::setw(10) << "hello" << "|" << std::endl;
	std::cout << std::right;
	std::cout << std::setw(10) << "a" << std::setw(10) << "a" << std::endl;
	std::cout << std::setw(10) << "a" << std::setw(10) << "a" << std::endl;
	std::cout << std::setw(10) << "a" << std::setw(10) << "a" << std::endl;
	return 0;
}
