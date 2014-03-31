/*
 * config_serialization.cpp
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */




#include "config_serialization.h"


namespace config {


namespace implementation {


Server::Server()
:
    host("localhost"),
    port(55555)
{}


Server::~Server() {
};


string Server::getHost() const {
    return host;
}


uint16_t Server::getPort() const {
    return port;
}


Client::Client()
:
    host("localhost"),
    port(55555)
{}


Client::~Client() {
}


string Client::getHost() const {
    return host;
}


uint16_t Client::getPort() const {
    return port;
}


} /* namespace implementation */


} /* namespace config */
