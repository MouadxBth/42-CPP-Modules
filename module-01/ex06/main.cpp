#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments."
                  << std::endl
                  << "Usage: " << argv[0] << " <level: {DEBUG, INFO, WARNING, ERROR}>"
                  << std::endl;
        return (1);
    }
	Harl harl;

	return (harl.complain(argv[1]), 0);
}
