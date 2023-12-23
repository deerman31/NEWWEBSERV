#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

void send_html(int client_socket, const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        // ファイルが開けない場合は、404 Not Foundを送信する
        std::string response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body>404 Not Found</body></html>\n";
        write(client_socket, response.c_str(), response.size());
        return;
    }

    // ファイルの内容を読み込む
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content = buffer.str();

    // HTTPヘッダを送信
    std::stringstream header;
    header << "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " << content.size() << "\r\n\r\n";
    write(client_socket, header.str().c_str(), header.str().size());

    // HTMLコンテンツを送信
    write(client_socket, content.c_str(), content.size());
}

// handle_connection関数とmain関数は前述のコードと同じなので省略しています
// handle_connection関数内で、以下のようにsend_html関数を呼び出すだけです：

void handle_connection(int client_socket, const std::string &file_path) {
    // ファイルのパスを指定します
    //send_html(client_socket, "html.html");
    send_html(client_socket, file_path);
    //"/Users/yoshinarikusano/Documents/42/Real-World-HTTP/html.html"
    // ソケットのクローズ
    close(client_socket);
}

int main(int argc, char **argv) {
    if (!(argc == 1 || argc == 2)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    int server_socket, client_socket;
    sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "Socket creation failed\n";
        exit(EXIT_FAILURE);
    }

    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(18888);

    // ポートにソケットをバインド
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Binding failed\n";
        exit(EXIT_FAILURE);
    }

    // リスニング開始
    if (listen(server_socket, 5) == -1) {
        std::cerr << "Listen failed\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "start http listening :18888\n";

    // クライアントからの接続を待機
    while (true) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            std::cerr << "Accept failed\n";
            continue;
        }
        std::string file_path;
        if (argc == 1)
            file_path = "default.html";
        else
            file_path = (std::string)argv[1];
        handle_connection(client_socket, file_path);
    }

    // ソケットのクローズ
    close(server_socket);
    return 0;
}
