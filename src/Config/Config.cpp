#include "Config.hpp"

void	printConfig(const Config& config) {
	for (std::vector<ConfigServer>::const_iterator it = config.servers.begin(); it != config.servers.end(); ++it) {
		std::cout << "----------------------" << "----------------------\n";
		std::cout << "Host       -> " << it->host << std::endl;
		std::cout << "Port       -> " << it->port << std::endl;
		std::cout << "serverName -> " << it->serverName << std::endl;
		for (std::map<int, std::string>::const_iterator itt = it->errorPages.begin(); itt != it->errorPages.end(); ++itt) {
			std::cout << "errorPages -> [key] " << itt->first << " [value] " <<itt->second << std::endl;
		}
		std::cout << "maxBodySize -> " << it->maxBodySize<< std::endl;
		for (std::vector<ConfigLocation>::const_iterator iit = it->locations.begin(); iit != it->locations.end(); ++iit) {
			std::cout << "-----Location-------\n";
			if (iit->path.size() != 0) {
				std::cout << "Path       -> " << iit->path << std::endl;
			}
			if (iit->root.size() != 0) {
				std::cout << "Root       -> " << iit->root << std::endl;
			}
			for (size_t i = 0; i < iit->indexFiles.size(); i += 1) {
				std::cout << "indexFiles -> " << iit->indexFiles[i] << std::endl;
			}
			for (size_t i = 0; i < iit->allowedMethods.size(); i += 1) {
				std::cout << "allowdMethods -> " << iit->allowedMethods[i] << std::endl;
			}
			if (iit->cgiHandler.size() != 0) {
				std::cout << "cgi       -> " << iit->cgiHandler << std::endl;
			}
			if (iit->redirect.size() != 0) {
				std::cout << "redirect  -> " << iit->redirect << std::endl;
			}
			if (iit->autoIndex == true) {
				std::cout << "autoIndex -> on" << std::endl;
			}
		}
	}
}

Config	configParse(char *path) {
	std::vector<ConfigServer>	servers;
	std::string	configStr;

	getFile(path, configStr);
	ConfigServer	s;
	std::vector<std::string>	serverstrs = servStrSplit(configStr);
	for (size_t i = 0; i < serverstrs.size(); i += 1) {
		std::vector<std::string> strs = delSplit(serverstrs[i], '\n');
		//s = sconfig(strs);
		s = ServerCreate(strs);
		servers.push_back(s);
	}
	Config	config;
	config.servers = servers;

	return config;
}