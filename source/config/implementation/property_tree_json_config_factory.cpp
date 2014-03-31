/*
 * property_tree_json_config_factory.cpp
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#include "property_tree_json_config_factory.h"


namespace config {
namespace implementation {


PropertyTreeJSONConfigFactory::PropertyTreeJSONConfigFactory() {
}


PropertyTreeJSONConfigFactory::~PropertyTreeJSONConfigFactory() {
}


shared_ptr<IConfig> PropertyTreeJSONConfigFactory::createConfig() const {
    shared_ptr<PropertyTreeJSONConfig> property_tree_json_config(new PropertyTreeJSONConfig("config.json"));

    try {
        if (exists(DEFAULT_CONFIG_FILE_NAME))
            property_tree_json_config->readJSON(DEFAULT_CONFIG_FILE_NAME);
        else {
            cerr << "config not found create default config '" << DEFAULT_CONFIG_FILE_NAME << "'" << endl;
            makeDefaultConfig(property_tree_json_config);
            property_tree_json_config->writeJSON(DEFAULT_CONFIG_FILE_NAME);
        }
    } catch (const ptree_error &e) {
        cerr << e.what() << endl;
        throw;
    }

    return shared_ptr<IConfig>(property_tree_json_config);
}


} /* namespace implementation */
} /* namespace config */
