# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <cstring>

static void	sendHtml(int clientSocket, const std::string &path) {
	std::ifstream	file(path);
	if (!file.is_open()) {
        std::string response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body>404 Not Found</body></html>\n";
        write(clientSocket, response.c_str(), response.size());
        return;
	}
	std::stringstream	buffer;
	buffer << file.rdbuf();
	file.close();
    std::string content = buffer.str();
	std::stringstream	header;
	header << "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " << content.size() << "\r\n\r\n";
	write(clientSocket, header.str().c_str(), header.str().size());

	write(clientSocket, content.c_str(), content.size());

}

static void	handleConnection(int clientSocket, const std::string &path) {
	sendHtml(clientSocket, path);
	close(clientSocket);
}

bool	server(const std::string &path) {
	int			serverSocket;
	int			clientSocket;
	sockaddr_in	serverAddr;
	sockaddr_in	clientAddr;
	socklen_t	clientAddrSize = sizeof(clientAddr);

	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		std::cerr << "socket failed!" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(18888);

	if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
		std::cerr << "bind failed!" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (listen(serverSocket, 5) == -1) {
		std::cerr << "listen failed!" << std::endl;
		exit(EXIT_FAILURE);
	}

	while(1) {
		clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
		if (clientSocket == -1) {
			std::cerr << "accept failed!" << std::endl;
			exit(EXIT_FAILURE);
		}
		handleConnection(clientSocket, path);
	}

	return true;
}

int	main(int argc, char **argv) {
	if (argc > 2) {
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	server("index.html");
	return EXIT_SUCCESS;
}