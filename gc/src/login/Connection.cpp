#include "boost/array.hpp"
#include "Connection.h"

using boost::asio::ip::tcp;

Connection::Connection(std::string host, short port) :
        _host(host), _port(port),
        _io_service(), _socket(_io_service) {}

Connection::~Connection() {
    close();
}

bool Connection::connect() {
    std::clog << "Starting connect to " << _host << ":" << _port << std::endl;
    try {
        tcp::resolver::iterator endpoint_iterator =
                tcp::resolver(_io_service).resolve(
                        tcp::resolver::query(_host,
                                             std::string(std::to_string(_port))));
        tcp::endpoint endpoint = *endpoint_iterator;
        boost::system::error_code error;
        _socket.connect(endpoint, error);
        if (error)
            throw boost::system::system_error(error);
    } catch (std::exception& e) {
        std::cerr << "Connection failed (Error: " << e.what() << ')' << std::endl;
        return false;
    }
    return true;
}

bool Connection::recv(char bytes[], unsigned int size) {

    boost::array<char, 128> buf;
    boost::system::error_code error;
    size_t len = _socket.read_some(boost::asio::buffer(buf), error);
    for (int i = 0; i < len; ++i)
        std::clog<<buf.elems[i];
    return true;
}

bool Connection::send(const char bytes[], int size) {
    int tmp = 0;
    boost::system::error_code error;
    try {
        while (!error && size > tmp ) {
            tmp += _socket.write_some(boost::asio::buffer(bytes + tmp, size - tmp), error);
        }
        if(error)
            throw boost::system::system_error(error);
    } catch (std::exception& e) {
        std::cerr << "recv failed (Error: " << e.what() << ')' << std::endl;
        return false;
    }
    return true;
}

// Close down the connection properly.
void Connection::close() {
    try{
        _socket.close();
    } catch (...) {
        std::clog << "closing failed: connection already closed" << std::endl;
    }
}