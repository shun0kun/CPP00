#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

int	main()
{
	std::time_t	now = std::time( NULL );
	std::tm	*lt = std::localtime( &now );

	char	buf[20];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", lt);
	std::cout << buf << std::endl;
	return 0;
}
