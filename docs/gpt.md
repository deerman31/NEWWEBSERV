# 使用可能関数
Everything in C++ 98.
execve, dup, dup2, pipe, strerror, gai_strerror,
errno, dup, dup2, fork, socketpair, htons, htonl,
ntohs, ntohl, select, poll, epoll (epoll_create,
epoll_ctl, epoll_wait), kqueue (kqueue, kevent),
socket, accept, listen, send, recv, chdir bind,
connect, getaddrinfo, freeaddrinfo, setsockopt,
getsockname, getprotobyname, fcntl, close, read,
write, waitpid, kill, signal, access, stat,
opendir, readdir and closedir.

pollもしくはselect, kqueue, epollなどから一つを使用することができる。

# Requirements
- プログラムはコンフィギュレーション・ファイルを引数に取るか、デフォルト・パスを使用しなければなりません。
- 他のウェブ・サーバーを実行することはできません。
- サーバーは決してブロックしてはならず、クライアントは必要に応じて適切にバウンスされなければなりません。
- サーバはノンブロッキングでなければならず、クライアントとサーバ間のすべてのI/O操作（リッスンも含む）に対して1回のpoll()（または同等の処理）しか使用してはなりません。
- poll()（または同等のもの）は、読み取りと書き込みを同時にチェックしなければならない。
- poll()（または同等のもの）を通さずに読み取りや書き込みの操作を行ってはならない。
- errnoの値をチェックすることは、readやwrite操作の後では厳禁である。
- 設定ファイルを読み込む前に poll()（または同等のもの）を使用する必要はありません。

ノンブロッキングのファイル・ディスクリプタを使用する必要があるため、poll()を使用しないread/recvまたはwrite/send関数を使用することが可能です。
poll()（またはそれに相当するもの）を使わずにread/recvやwrite/send関数を使うことができる。
(またはそれに相当するもの)を使わずにread/recvやwrite/send関数を使用することは可能で、サーバーはブロッキングしない。
しかし、より多くのシステム・リソースを消費することになります。
したがって、poll() (または同等のもの) を使用せずにファイル記述子で read/recv や write/send を行おうとすると、成績は 0 になります。

- FD_SET、FD_CLR、FD_ISSET、FD_ZEROのようなあらゆるマクロや定義を使うことができる（何がどのように行われるかを理解することは非常に役に立つ）。
- サーバーへのリクエストは、永遠にハングしてはいけません。
- サーバーは、選択したウェブブラウザと互換性がなければなりません。
- NGINXはHTTP 1.1に準拠しており、ヘッダーとレスポンスの動作を比較するために使用することができます。
- HTTPレスポンスのステータスコードは正確でなければなりません。
- デフォルトのエラーページが提供されていない場合は、サーバーにデフォルトのエラーページがなければなりません。
- CGI以外のもの（PHPやPythonなど）にforkを使用することはできません。
- 完全に静的なウェブサイトを提供できなければなりません。
- クライアントはファイルをアップロードできなければなりません。
- 少なくとも GET、POST、DELETE メソッドが必要です。
- サーバーのストレステスト サーバーは常に利用可能でなければなりません。
- サーバーは複数のポートをリッスンできなければなりません（設定ファイルを参照）。

# For MacOS only
MacOSは他のUnix OSと同じようにwrite()を実装していないので、fcntl()を使うことが許されている。
他のUnix OSと同様の動作を得るためには、ファイル・ディスクリプタをノンブロッキング・モードで使用しなければならない。

ただし、fcntl()を使用できるのは以下の場合のみである：
fcntl(fd, F_SETFL, O_NONBLOCK, FD_CLOEXEC); それ以外のフラグは禁止されている。