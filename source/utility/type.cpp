/*
 * type.cpp
 *
 *  Created on: 27 марта 2014 г.
 *      Author: volodja
 */





#include "type.h"


namespace utility {


TCPAddress::TCPAddress(const string &host, const uint16_t port)
:
    host(host),
    port(port)
{}


TCPAddress::~TCPAddress() {
}


string  TCPAddress::getHost() const {
    return host;
}


uint16_t TCPAddress::getPort() const {
    return port;
}


}
