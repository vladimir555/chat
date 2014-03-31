/*
 * config_factory.cpp
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#include "config_factory.h"


namespace config {
namespace implementation {


const string    ConfigFactory::DEFAULT_CONFIG_FILE_NAME ("config.json");
const string    ConfigFactory::DEFAULT_SERVER_HOST      ("localhost");
const uint16_t  ConfigFactory::DEFAULT_SERVER_PORT      (55555);
const string    ConfigFactory::DEFAULT_SERVER_DB_HOST   ("localhost");;
const uint16_t  ConfigFactory::DEFAULT_SERVER_DB_PORT   (3306);
const string    ConfigFactory::DEFAULT_CLIENT_HOST      ("localhost");;
const uint16_t  ConfigFactory::DEFAULT_CLIENT_PORT      (55555);;


ConfigFactory::ConfigFactory() {
}


ConfigFactory::~ConfigFactory() {
}


shared_ptr<IConfig> ConfigFactory::buildConfig() {
    shared_ptr<PropertyTreeJSONConfig> property_tree_json_config(new PropertyTreeJSONConfig("config.json"));

    try {
        if (exists(DEFAULT_CONFIG_FILE_NAME))
            property_tree_json_config->readJSON(DEFAULT_CONFIG_FILE_NAME);
        else {
            cerr << "config not found create default config '" << DEFAULT_CONFIG_FILE_NAME << "'" << endl;
            makeDefaultConfig(property_tree_json_config);
            property_tree_json_config->writeJSON(DEFAULT_CONFIG_FILE_NAME);
        }
    } catch (const boost::property_tree::ptree_error &e) {
        cerr << e.what() << endl;
        throw;
    }

    return shared_ptr<IConfig>(property_tree_json_config);
}


void ConfigFactory::makeDefaultConfig(shared_ptr<IConfigChangeable> config) {
    config->setServerAddress  (TCPAddress(DEFAULT_SERVER_HOST   , DEFAULT_SERVER_PORT));
    config->setServerDBAddress(TCPAddress(DEFAULT_SERVER_DB_HOST, DEFAULT_SERVER_DB_PORT));
    config->setClientAddress  (TCPAddress(DEFAULT_CLIENT_HOST   , DEFAULT_CLIENT_PORT));
}


} /* namespace implementation */
} /* namespace config */
