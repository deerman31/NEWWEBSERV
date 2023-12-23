#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

struct ConfigLocation {
	std::string	path;
	std::string	root;
	std::vector<std::string>	indexFiles;
	std::vector<std::string>	allowedMethods;
	std::string					cgiHandler;
	//std::string					uploadPath;
	std::string					redirect;
	bool						autoIndex;
};

struct ConfigServer {
	std::string					host;
	int							port;
	std::string					serverName;
	std::map<int, std::string>	errorPages;
	size_t						maxBodySize;
	std::vector<ConfigLocation>	locations;
};

struct Config {
	std::vector<ConfigServer>	servers;
};

Config	configParse(char *path);
bool	getFile(char* path, std::string& configFile);
std::vector<std::string>	servStrSplit(const std::string& s);
std::vector<std::string>	delSplit(const std::string& s, char del);
ConfigServer	ServerCreate(std::vector<std::string> strs);
void	printConfig(const Config& config);

#endif