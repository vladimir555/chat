/*
 * server_config_adapter.cpp
 *
 *  Created on: 05 апр. 2014 г.
 *      Author: volodja
 */





#include <server/implementation/server_config_adapter.h>


namespace server {
namespace implementation {


ServerConfigAdapter::ServerConfigAdapter(shared_ptr<const IConfig> config)
:
    config(config)
{}


ServerConfigAdapter::~ServerConfigAdapter() {
}


TCPAddress ServerConfigAdapter::getAddress() const {
    return config->getServerAddress();
}


TCPAddress ServerConfigAdapter::getDBAddress() const {
    return config->getServerDBAddress();
}


} /* namespace implementation */
} /* namespace server */
