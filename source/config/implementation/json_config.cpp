/*
 * json_config.cpp
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */




#include "json_config.h"


namespace config {


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


string Client::getHost() const {
    return host;
}


uint16_t Client::getPort() const {
    return port;
}


} /* namespace config */
