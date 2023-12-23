#ifndef BASESOCKET_HPP
#define BASESOCKET_HPP

#include <poll.h>
#include "../Config/Config.hpp"

enum StatusSocket {
	NONE,
	ACCEPT,
	RECV,
	PARSE,
	GET,
	POST,
	DELETE,
	CGI,
	CLOSE,
	ERROR,
};

class BaseSocket {
	protected:
		pollfd	_pollfd;
		const ConfigServer&	_servConfig;
		StatusSocket		_status;
	public:
		//BaseSocket();
		BaseSocket(const ConfigServer&	_servConfig);
		~BaseSocket();
		BaseSocket(const BaseSocket& src);
		BaseSocket&	operator=(const BaseSocket& src);
};

#endif