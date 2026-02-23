#include <iostream>
#include <string>
#include <iomanip>

void	put_len(const std::string& str)
{
	std::cout << str.length() << std::endl;
}

int	main()
{
	put_len("ADD");
	return 0;
}
