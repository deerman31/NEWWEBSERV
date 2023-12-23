#include "Config.hpp"

static std::string	servStrSplit2(const std::string& s) {
	size_t start = s.find("{");
	//size_t end = 0;
	size_t a = 1;
	size_t b = 0;
	size_t i;
	for (i = start + 1; a != b; i += 1) {
		if (s[i] == '{') {
			a += 1;
		} else if (s[i] == '}') {
			b += 1;
		}
	}
	return s.substr(0, i);
} 

std::vector<std::string>	servStrSplit(const std::string& s) {
	std::vector<std::string>	strs;
	std::string ss;
	size_t i = 0;
	while (i < s.size()) {
		ss = servStrSplit2(&s[i]);
		strs.push_back(ss);
		i += ss.size() + 1;
	}
	return strs;
}