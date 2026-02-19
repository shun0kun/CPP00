#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string	s(argv[i]);
		for (std::size_t j = 0; j < s.length(); ++j)
		{
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(s[j])));
		}
	}
	std::cout << std::endl;
	return 0;
}
