#ifndef GAMECLIENT_CONNECTION_H
#define GAMECLIENT_CONNECTION_H

#include "string"
#include "iostream"
#include "boost/asio.hpp"

using boost::asio::ip::tcp;

class Connection {
private:
    const std::string _host;
    const unsigned short _port;
    boost::asio::io_service _io_service;   // Provides core I/O functionality
    tcp::socket _socket;

public:
    Connection(std::string host, short port);
    virtual ~Connection();

    // Connect to the remote machine
    bool connect();

    // Read a fixed number of bytes from the server - blocking.
    // Returns false in case the connection is closed before bytesToRead bytes can be read.
    bool recv(char bytes[], unsigned int size);

    // Send a fixed number of bytes from the client - blocking.
    // Returns false in case the connection is closed before all the data is sent.
    bool send(const char bytes[], int size);

    // Close down the connection properly.
    void close();

}; //class Connection

#endif
