# Webserv Subject

this is when you finally understand why a URL starts with HTTP

## Summary
このプロジェクトは自らのHTTPサーバーを実装することです。

このプロジェクトはブラウザでテストすることができます。

HTTPはインターネットで最も使われているプロトコルの一つです。

その難解さを知っておくことは、たとえWEBサイトを作ることがなくても役に立つでしょう。

## Introduction
**Hypertext Transfer Protocol** (HTTP) は、分散型ハイパーメディア情報システムのためのアプリケーション・プロトコルである、ハイパーメディア情報システムのためのアプリケーションプロトコルである。

HTTPはワールド・ワイド・ウェブのデータ通信の基礎であり、ハイパーテキスト文書には、ユーザーが簡単にアクセスできる他のリソースへのハイパーリンクが含まれている。
例えば、マウスクリックやウェブブラウザの画面タップによって。

HTTPは、ハイパーテキストとワールド・ワイド・ウェブを容易にするために開発された。

ウェブサーバーの主な機能は、ウェブページを保存、処理し、クライアントに配信することです。クライアントとサーバー間の通信は、ハイパーテキスト転送プロトコル（HTTP）を使って行われる。

配信されるページはHTML文書であることが多く、テキストコンテンツに加えて画像、スタイルシート、スクリプトが含まれることもあります。

トラフィックの多いウェブサイトでは、複数のウェブサーバーを使用することもある。

ユーザーエージェント（一般的にはウェブブラウザーやウェブクローラー）は、HTTPを使って特定のリソースを要求することで通信を開始し、サーバーはそのリソースのコンテンツを応答するか、それができない場合はエラーメッセージを応答する。リソースは通常、サーバーのセカンダリストレージ上の実際のファイルですが、必ずしもそうではなく、ウェブサーバーの実装方法によって異なります。

主な機能はコンテンツを提供することですが、HTTPの完全な実装には、クライアントからコンテンツを受け取る方法も含まれています。この機能は、ファイルのアップロードを含むウェブフォームの送信に使用されます。

## General rules
- あなたのプログラムはどんな状況でも（たとえメモリ不足でも）クラッシュしてはいけませんし、予期せず終了してもいけません。
もしクラッシュした場合、あなたのプロジェクトは機能しないとみなされ、成績は0点となります。
- ソースファイルをコンパイルする Makefile を提出しなければなりません。再リンクしてはいけません。
- Makefile には少なくとも以下のルールが含まれていなければなりません：
(NAME)、all、clean、fclean、re。
- c++ と -Wall -Wextra -Werror フラグを使用してコードをコンパイルしてください。
- あなたのコードは**C++ 98標準**に準拠していなければならない。その場合、-std=c++98フラグを追加してもコンパイルできるはずです。
- 常にできる限りC++の機能を使用して開発するようにしてください（例えば、<string.h>よりも<cstring>を選択してください）。C関数を使用することは許されているが、可能であれば常にC++バージョンを使用すること。
- 外部ライブラリやBoostライブラリの使用は禁止する。

## Mandatory part
| Program name | webserv |
| --- | --- |
| Turn in files | Makefile, *.{h, hpp}, *.cpp, *.tpp, *.ipp,configuration files |
| Makefile | NAME, all, clean, fclean, re |
| Arguments | [A configuration file] |
| External functs. | Everything in C++ 98.
execve, dup, dup2, pipe, strerror, gai_strerror,
errno, dup, dup2, fork, socketpair, htons, htonl,
ntohs, ntohl, select, poll, epoll (epoll_create,
epoll_ctl, epoll_wait), kqueue (kqueue, kevent),
socket, accept, listen, send, recv, chdir bind,
connect, getaddrinfo, freeaddrinfo, setsockopt,
getsockname, getprotobyname, fcntl, close, read,
write, waitpid, kill, signal, access, stat,
opendir, readdir and closedir. |
| Libft authorized | n/a |
| Description | A HTTP server in C++ 98 |
<br>

C++ 98でHTTPサーバーを書かなければならない。  
`You must write a HTTP server in C++ 98.`

実行ファイルは次のように実行される：  
`Your executable will be run as follows:`
<br>
<br>
```
./webserv [configuration file]
```
<br>

```
poll()が主題と評価尺度で言及されていても、select()、kqueue()、epoll()などの同等のものを使用することができる。

Even if poll() is mentionned in the subject and the evaluation scale,
you can use any equivalent such as select(), kqueue(), or epoll().
```
<br>

```
このプロジェクトを始める前に、RFCを読み、telnetとNGINXでテストを行ってください。
RFC をすべて実装する必要はなくても、RFC を読むことは必要な機能を開発するのに役立ちます。

Please read the RFC and do some tests with telnet and NGINX before
starting this project.
Even if you don’t have to implement all the RFC, reading it will help
you develop the required features.
```

## Requirements
- プログラムはコンフィギュレーション・ファイルを引数に取るか、デフォルト・パスを使用しなければなりません。  
`Your program has to take a configuration file as argument, or use a default path.`
<br>
<br>
- 他のウェブ・サーバーを実行することはできません。  
`You can’t execve another web server.`
<br>
<br>
- サーバーは決してブロックしてはならず、クライアントは必要に応じて適切にバウンスされなければなりません。  
`Your server must never block and the client can be bounced properly if necessary.`
<br>
<br>
- サーバはノンブロッキングでなければならず、クライアントとサーバ間のすべてのI/O操作（リッスンも含む）に対して**1**回のpoll()（または同等の処理）しか使用してはなりません。  
`It must be non-blocking and use only 1 poll() (or equivalent) for all the I/O operations between the client and the server (listen included).`
<br>
<br>
- poll()（または同等のもの）は、読み取りと書き込みを同時にチェックしなければならない。  
`poll() (or equivalent) must check read and write at the same time.`
<br>
<br>
- poll()（または同等のもの）を通さずに読み取りや書き込みの操作を行ってはならない。  
`You must never do a read or a write operation without going through poll() (or equivalent).`
<br>
<br>
- errnoの値をチェックすることは、readやwrite操作の後では厳禁である。  
`Checking the value of errno is strictly forbidden after a read or a write operation.`
<br>
<br>
- 設定ファイルを読み込む前に poll()（または同等のもの）を使用する必要はありません。  
`You don’t need to use poll() (or equivalent) before reading your configuration file.`
<br>
<br>

```
ノンブロッキングのファイル・ディスクリプタを使用する必要があるため、poll()を使用しないread/recvまたはwrite/send関数を使用することが可能です。
poll()（またはそれに相当するもの）を使わずにread/recvやwrite/send関数を使うことができる。
(またはそれに相当するもの)を使わずにread/recvやwrite/send関数を使用することは可能で、サーバーはブロッキングしない。
しかし、より多くのシステム・リソースを消費することになります。
したがって、poll() (または同等のもの) を使用せずにファイル記述子で read/recv や write/send を行おうとすると、成績は 0 になります。  

Because you have to use non-blocking file descriptors, it is
possible to use read/recv or write/send functions with no poll()
(or equivalent), and your server wouldn’t be blocking.
But it would consume more system resources.
Thus, if you try to read/recv or write/send in any file descriptor
without using poll() (or equivalent), your grade will be 0.
```
<br>
<br>

- FD_SET、FD_CLR、FD_ISSET、FD_ZEROのようなあらゆるマクロや定義を使うことができる（何がどのように行われるかを理解することは非常に役に立つ）。  
`You can use every macro and define like FD_SET, FD_CLR, FD_ISSET, FD_ZERO (understanding what and how they do it is very useful).`
<br>
<br>
- サーバーへのリクエストは、永遠にハングしてはいけません。  
`A request to your server should never hang forever.`
<br>
<br>
- サーバーは、選択した**ウェブブラウザ**と互換性がなければなりません。  
`Your server must be compatible with the web browser of your choice.`
<br>
<br>
- NGINXはHTTP 1.1に準拠しており、ヘッダーとレスポンスの動作を比較するために使用することができます。  
`We will consider that NGINX is HTTP 1.1 compliant and may be used to compare headers and answer behaviors.`
<br>
<br>
- HTTPレスポンスのステータスコードは正確でなければなりません。  
`Your HTTP response status codes must be accurate.`
<br>
<br>
- デフォルトのエラーページが提供されていない場合は、サーバーに**デフォルトのエラーページ**がなければなりません。  
`You server must have default error pages if none are provided.`
<br>
<br>
- CGI以外のもの（PHPやPythonなど）にforkを使用することはできません。  
`You can’t use fork for something else than CGI (like PHP, or Python, and so forth).`
<br>
<br>
- **完全に静的なウェブサイト**を提供できなければなりません。  
`You must be able to serve a fully static website.`
<br>
<br>
- クライアントは**ファイルをアップロード**できなければなりません。  
`You must be able to serve a fully static website.`
<br>
<br>
- 少なくとも GET、POST、DELETE メソッドが必要です。  
`You need at least GET, POST, and DELETE methods.`
<br>
<br>
- サーバーのストレステスト サーバーは常に利用可能でなければなりません。  
`Stress tests your server. It must stay available at all cost.`
<br>
<br>
- サーバーは複数のポートをリッスンできなければなりません（設定ファイルを参照）。  
` Your server must be able to listen to multiple ports (see Configuration file).`
<br>
<br>

## For MacOS only
```
MacOSは他のUnix OSと同じようにwrite()を実装していないので、fcntl()を使うことが許されている。  
他のUnix OSと同様の動作を得るためには、ファイル・ディスクリプタをノンブロッキング・モードで使用しなければならない。
Since MacOS doesn’t implement write() the same way as other Unix
OSes, you are allowed to use fcntl().
You must use file descriptors in non-blocking mode in order to get a
behavior similar to the one of other Unix OSes.
```
<br>
<br>

```
ただし、fcntl()を使用できるのは以下の場合のみである：  
fcntl(fd, F_SETFL, O_NONBLOCK, FD_CLOEXEC); それ以外のフラグは禁止されている。
However, you are allowed to use fcntl() only as follows:
fcntl(fd, F_SETFL, O_NONBLOCK, FD_CLOEXEC);
Any other flag is forbidden.
```
<br>
<br>

## Configuration file
```
NGINX設定ファイルの'server'部分からヒントを得ることができます。
You can get some inspiration from the ’server’ part of NGINX
configuration file.
```
<br>
コンフィギュレーション・ファイルでは、以下のことができるはずだ：`In the configuration file, you should be able to:`
<br>
<br>

* 各「サーバー」のポートとホストを選択する。  
`Choose the port and host of each ’server’.`
<br>
<br>
* server_namesを設定するかどうか。  
`Setup the server_names or not.`
<br>
<br>
* あるホスト:ポートに対する最初のサーバーがそのホスト:ポートのデフォルトになります (つまり、他のサーバーに属さないすべてのリクエストに応答します)。  
`The first server for a host:port will be the default for this host:port (that means it will answer to all the requests that don’t belong to an other server).`
<br>
<br>
* デフォルトのエラーページを設定する。  
`Setup default error pages.`
<br>
<br>
* クライアントボディのサイズを制限する。  
`Limit client body size.`
<br>
<br>
* 1つまたは複数の以下のルール/設定でルートを設定する（ルートは正規表現を使用しません）：  
`• Setup routes with one or multiple of the following rules/configuration (routes wont be using regexp):`
<br>
<br>


	* ルートに受け入れられるHTTPメソッドのリストを定義する。  
	`Define a list of accepted HTTP methods for the route.`
<br>
<br>
	* HTTP リダイレクトを定義する。  
	`Define a HTTP redirection.`
<br>
<br>
	* ファイルが検索されるべきディレクトリまたはファイルを定義します (例えば、 url /kapouet が /tmp/www にルートされている場合、 url /kapouet/pouic/toto/pouet は /tmp/www/pouic/toto/pouet となります)。  
	`Define a directory or a file from where the file should be searched (for example, if url /kapouet is rooted to /tmp/www, url /kapouet/pouic/toto/pouet is /tmp/www/pouic/toto/pouet).`
<br>
<br>
	* ディレクトリ・リスティングをオンまたはオフにします。  
	`Turn on or off directory listing.`
<br>
<br>
	* リクエストがディレクトリである場合に答えるデフォルトファイルを設定します。  
	`Set a default file to answer if the request is a directory`
<br>
<br>
	* 特定のファイル拡張子(例えば.php)に基づいてCGIを実行します。  
	`Execute CGI based on certain file extension (for example .php).`
<br>
<br>
	* POSTとGETメソッドで動作するようにする。  
	`Make it work with POST and GET methods.`
<br>
<br>
	* アップロードされたファイルを受け入れることができるルートを作成し、ファイルを保存する場所を設定します。  
	`Make the route able to accept uploaded files and configure where they should be saved.`
<br>
<br>
		∗ [CGI](https://en.wikipedia.org/wiki/Common_Gateway_Interface)って何だろう？  
		`Do you wonder what a CGI is?`
<br>
<br>
		∗ CGIを直接呼び出すことはないので、PATH_INFOとしてフルパスを使用してください。  
		`Because you won’t call the CGI directly, use the full path as PATH_INFO.`
<br>
<br>
		∗ CGIはボディの終わりとしてEOFを期待します。  
		`Just remember that, for chunked request, your server needs to unchunk it, the CGI will expect EOF as end of the body.`
<br>
<br>

		∗ CGIの出力も同じです。CGIからcontent_lengthが返されない場合、EOFは返されたデータの終わりを示します。  
		`Same things for the output of the CGI. If no content_length is returned from the CGI, EOF will mark the end of the returned data.`
<br>
<br>
		∗ プログラムは、要求されたファイルを第一引数としてCGIを呼び出す必要があります。  
		`Your program should call the CGI with the file requested as first argument.`
<br>
<br>
		∗ CGIは、相対パスのファイルアクセスのために正しいディレクトリで実行されなければなりません。  
		`The CGI should be run in the correct directory for relative path file access.`
<br>
<br>
		∗ サーバーは1つのCGI（php-CGI、Pythonなど）で動作する必要があります。  
		`Your server should work with one CGI (php-CGI, Python, and so forth).`
<br>
<br>


評価中にすべての機能が動作することをテストし、実証するために、いくつかの設定ファイルとデフォルトの基本ファイルを提供する必要があります。`You must provide some configuration files and default basic files to test and demonstrate every feature works during evaluation.`
```

ある動作について疑問がある場合、NGINXの動作とあなたのプログラムの動作を比較する必要があります。  
例えば、server_nameがどのように動作するかを確認してください。  
小さなテスターを用意しました。 ブラウザとテストがすべて問題なく動作するのであれば、このテストに合格することは必須ではありませんが、いくつかのバグを見つけるのに役立ちます。
If you’ve got a question about one behavior, you should compare your
program behavior with NGINX’s.
For example, check how does server_name work.
We’ve shared with you a small tester. It’s not mandatory to pass it
if everything works fine with your browser and tests, but it can help
you hunt some bugs.
```
```
重要なのは回復力だ。 サーバーは決して死ぬべきではありません。
The important thing is resilience. Your server should never die.
```

```
1 つのプログラムだけでテストしないでください。 より多くの要素を使用してテストを作成します  
PythonやGolangなどの便利な言語。 必要に応じて C または C++ でも。
Do not test with only one program. Write your tests with a more
convenient language such as Python or Golang, and so forth. Even in
C or C++ if you want to.
```