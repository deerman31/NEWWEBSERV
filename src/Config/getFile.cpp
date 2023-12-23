#include "Config.hpp"

static bool	isComment(const std::string& line) {
	if (line.size() == 0) {
		return false;
	}

	size_t i = 0;
	while (line[i] == ' ') {
		i += 1;
	}
	if (i == line.size()) {
		return false;
	}
	if (line[i] == '#') {
		return false;
	}
	return true;
}

static std::string	spaceDel(const std::string& line) {
	size_t i = 0;
	while (line[i] == ' ')
		i += 1;
	std::string s = line.substr(i);
	return s;
}

static void trimEnd(std::string &str) {
    while (!str.empty()) {
        char lastChar = str.back();
        if (lastChar == ';' || lastChar == ' ') {
            str.pop_back();
        } else {
            break; // 末尾の文字が削除対象でない場合、ループを抜ける
        }
    }
}

bool	getFile(char* path, std::string& configFile) {
	std::ifstream	inputFile(path);

	if (!inputFile) {
		return false;
	}
	std::string	line;
	while (std::getline(inputFile, line)) {
		if (isComment(line)) {
			line = spaceDel(line);
			trimEnd(line);
			configFile += line + "\n";
		}
	}
	inputFile.close();
	return true;
}