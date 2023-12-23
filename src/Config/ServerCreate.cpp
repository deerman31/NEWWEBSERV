#include "Config.hpp"

static int	ft_stoi(const std::string& s) {
	int		n;
	std::istringstream	iss(s);
	iss >> n;
	return n;
}

static void errorPageCreate(std::map<int, std::string>& map, const std::string& line) {
	std::vector<std::string>	strs = delSplit(line, ' ');
	int n = ft_stoi(strs[0]);
	map[n] = strs[1];
}

static size_t	maxBodySizeCreate(const std::string& line) {
/* バイト単位：client_max_body_size 500 などと指定すると、サイズはバイト単位で設定されます。
キロバイト（K）：client_max_body_size 10K は 10 キロバイトを意味します。
メガバイト（M）：client_max_body_size 10M は 10 メガバイトを意味します。これは非常に一般的な使用法です。
ギガバイト（G）：client_max_body_size 2G は 2 ギガバイトを意味します。これは大きなファイルのアップロードを許可する場合に使用されます。*/
	size_t x = 1;
	if (line.find("M") != std::string::npos) {
		x = 1024;
	} else if (line.find("M") != std::string::npos) {
		x = 1048576;
	} else if (line.find("G") != std::string::npos) {
		x = 1073741824;
	} 
	return x * ft_stoi(line);
}

static void trimEndUsingPopBack(std::string &str) {
    while (!str.empty()) {
        char lastChar = str.back();
        if (lastChar == '{' || lastChar == ' ') {
            str.pop_back();
        } else {
            break; // 末尾の文字が削除対象でない場合、ループを抜ける
        }
    }
}

static ConfigLocation	locationCreate(std::vector<std::string> strs) {
	ConfigLocation	l;

	l.path = strs[0].substr(9);
	trimEndUsingPopBack(l.path);

	l.autoIndex = false;
	for (size_t i = 1; i < strs.size(); i += 1) {
		if (strs[i].find("root ") == 0) {
			l.root = strs[i].substr(5);
		} else if (strs[i].find("index ") == 0) {
			l.indexFiles = delSplit(strs[i].substr(6), ' ');
		} else if (strs[i].find("allow_methods ") == 0) {
			l.allowedMethods = delSplit(strs[i].substr(14), ' ');
		} else if (strs[i].find("cgi ") == 0) {
			l.cgiHandler = strs[i].substr(4);
		} else if (strs[i].find("redirect ") == 0) {
			l.redirect = strs[i].substr(9);
		} else if (strs[i].find("autoindex on") == 0) {
			l.autoIndex = true;
		}
	}
	return l;
}

ConfigServer	ServerCreate(std::vector<std::string> strs) {
	std::vector<std::string> ss;
	ConfigServer	s;

	for (size_t i = 0; i < strs.size(); i += 1) {
		if (strs[i].find("host ") == 0) {
			s.host = strs[i].substr(5);
		} else if (strs[i].find("port ") == 0) {
			s.port = ft_stoi(strs[i].substr(5));
		} else if (strs[i].find("server_name ") == 0) {
			s.serverName = strs[i].substr(12);
		} else if (strs[i].find("error_page ") == 0) {
			errorPageCreate(s.errorPages, strs[i].substr(11));
		} else if (strs[i].find("client_max_body_size ") == 0) {
			s.maxBodySize = maxBodySizeCreate(strs[i].substr(21));
		} else if (strs[i].find("location ") == 0) {
			ss.clear();
			while (strs[i].find("}") == std::string::npos) {
				ss.push_back(strs[i]);
				i += 1;
			}
			s.locations.push_back(locationCreate(ss));
		}
	}
	return s;
}
