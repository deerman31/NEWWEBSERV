#include "Config.hpp"

std::vector<std::string>	delSplit(const std::string& s, char del) {
	std::vector<std::string>	strs;
	size_t start = 0;
	size_t end = 0;

	while ((end = s.find(del, start)) != std::string::npos) {
		strs.push_back(s.substr(start, end - start));
		start = end + 1;
	}
	strs.push_back(s.substr(start));
	return strs;
}
