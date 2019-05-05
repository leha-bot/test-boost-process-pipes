#include "terminal.hpp"
#include <boost/asio/io_context.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read.hpp>
#include <boost/process/async_pipe.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
	namespace bp = boost::process;
	namespace asio = boost::asio;
	utils::adjust_terminal_charset();
	asio::io_context pipe_context;
	try {
		std::cout << "S: Creating pipe " << argv[1];

		bp::async_pipe pipe(pipe_context, argv[1]);
		asio::streambuf buf;
		std::string s;
		std::getline(std::cin, s);
		
		asio::async_read(pipe, buf,
			[&buf](const boost::system::error_code &ec, std::size_t size) {
			if (size != 0) {
				std::cout << "S: got string from pipe: \"" << &buf << "\"" << std::endl;
			}
			else {
				std::cerr << "error " << ec << std::endl;
			}
		}
		);
		pipe_context.run();
	} catch (std::system_error &ec) {
		std::cout << "S: system error: " << ec.what() << ", error code: " << ec.code() << std::endl;
	} 
}

