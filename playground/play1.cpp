#include <iostream>
#include <string>

int	main()
{
	std::string	input;

	while (true)
	{
		std::cout << "> " << std::flush;
		if (!std::getline(std::cin, input))
			break ;
		std::cout << input << '\n';
	}
	return 0;
}
