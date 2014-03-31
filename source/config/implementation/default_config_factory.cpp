/*
 * default_config_factory.cpp
 *
 *  Created on: 31 марта 2014 г.
 *      Author: volodja
 */





#include "default_config_factory.h"


namespace config {
namespace implementation {


const string    DefaultConfigFactory::DEFAULT_CONFIG_FILE_NAME ("config.json");
const string    DefaultConfigFactory::DEFAULT_SERVER_HOST      ("localhost");
const uint16_t  DefaultConfigFactory::DEFAULT_SERVER_PORT      (55555);
const string    DefaultConfigFactory::DEFAULT_SERVER_DB_HOST   ("localhost");;
const uint16_t  DefaultConfigFactory::DEFAULT_SERVER_DB_PORT   (3306);
const string    DefaultConfigFactory::DEFAULT_CLIENT_HOST      ("localhost");;
const uint16_t  DefaultConfigFactory::DEFAULT_CLIENT_PORT      (55555);;


DefaultConfigFactory::DefaultConfigFactory() {
}


DefaultConfigFactory::~DefaultConfigFactory() {
}


void DefaultConfigFactory::makeDefaultConfig(shared_ptr<IConfigChangeable> config) {
    config->setServerAddress  (TCPAddress(DEFAULT_SERVER_HOST   , DEFAULT_SERVER_PORT));
    config->setServerDBAddress(TCPAddress(DEFAULT_SERVER_DB_HOST, DEFAULT_SERVER_DB_PORT));
    config->setClientAddress  (TCPAddress(DEFAULT_CLIENT_HOST   , DEFAULT_CLIENT_PORT));
}


} /* namespace implementation */
} /* namespace config */
