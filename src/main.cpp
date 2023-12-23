#include "Config/Config.hpp"

int	main(int argc, char **argv) {
	if (argc > 2) {
		std::cout << "ERROR: 42" << std::endl;
		return 0;
	}
	Config	Configs;
	if (argc == 1) {
		char	dPath[100] = "conf/default.conf";
		Configs = configParse(dPath);
	} else {
		Configs = configParse(argv[1]);
	}
	printConfig(Configs);

	
	return 0;
}
