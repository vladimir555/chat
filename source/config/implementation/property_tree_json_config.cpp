/*
 * property_tree_json_config.cpp
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#include "property_tree_json_config.h"


namespace config {
namespace implementation {


PropertyTreeJSONConfig::PropertyTreeJSONConfig(const string &file_name)
:
    file_name(file_name)
{}


PropertyTreeJSONConfig::~PropertyTreeJSONConfig() {
}


TCPAddress PropertyTreeJSONConfig::getServerAddress() const {
    return TCPAddress(getValue<string>("server.host"), getValue<uint16_t>("server.port"));
}


TCPAddress PropertyTreeJSONConfig::getServerDBAddress() const {
    return TCPAddress(getValue<string>("server.db.host"), getValue<uint16_t>("server.db.port"));
}


TCPAddress PropertyTreeJSONConfig::getClientAddress() const {
    return TCPAddress(getValue<string>("client.host"), getValue<uint16_t>("client.port"));
}


void PropertyTreeJSONConfig::setServerAddress(const TCPAddress &tcp_address) {
    setValue("server.host", tcp_address.getHost());
    setValue("server.port", tcp_address.getPort());
}


void PropertyTreeJSONConfig::setServerDBAddress(const TCPAddress &tcp_address) {
    setValue("server.db.host", tcp_address.getHost());
    setValue("server.db.port", tcp_address.getPort());
}


void PropertyTreeJSONConfig::setClientAddress  (const TCPAddress &tcp_address) {
    setValue("client.host", tcp_address.getHost());
    setValue("client.port", tcp_address.getPort());
}


} /* namespace implementation */
} /* namespace config */
