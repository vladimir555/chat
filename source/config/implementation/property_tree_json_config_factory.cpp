/*
 * property_tree_json_config_factory.cpp
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#include "property_tree_json_config_factory.h"


namespace config {
namespace implementation {


LOG_IMPLEMENT(PropertyTreeJSONConfigFactory);


PropertyTreeJSONConfigFactory::PropertyTreeJSONConfigFactory() {
}


PropertyTreeJSONConfigFactory::~PropertyTreeJSONConfigFactory() {
}


shared_ptr<const IConfig> PropertyTreeJSONConfigFactory::createConfig() {
    shared_ptr<PropertyTreeJSONConfig> property_tree_json_config(new PropertyTreeJSONConfig("config.json"));

    try {
        if (exists(DEFAULT_CONFIG_FILE_NAME))
            property_tree_json_config->readJSON(DEFAULT_CONFIG_FILE_NAME);
        else {
            LOG_WARN("config not found create default config '" + DEFAULT_CONFIG_FILE_NAME + "'");
            makeDefaultConfig(property_tree_json_config);
            property_tree_json_config->writeJSON(DEFAULT_CONFIG_FILE_NAME);
        }
    } catch (const ptree_error &e) {
        LOG_ERROR(e.what());
        throw;
    }

    return shared_ptr<const IConfig>(property_tree_json_config);
}


} /* namespace implementation */
} /* namespace config */
