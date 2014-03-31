/*
 * property_tree_config.cpp
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#include "property_tree_config.h"


namespace config {
namespace implementation {


PropertyTreeConfig::PropertyTreeConfig() {
}


PropertyTreeConfig::~PropertyTreeConfig() {
}


void PropertyTreeConfig::readJSON (const string &file_name) {
    ifstream json_config_file(file_name);
    read_json(json_config_file, property_tree);
}


void PropertyTreeConfig::writeJSON(const string &file_name) {
    ofstream json_config_file(file_name);
    write_json(json_config_file, property_tree);
}


} /* namespace implementation */
} /* namespace config */
