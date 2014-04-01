/*
 * property_tree_json_config_factory.h
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#ifndef PROPERTY_TREE_JSON_CONFIG_FACTORY_H_
#define PROPERTY_TREE_JSON_CONFIG_FACTORY_H_


#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/property_tree/exceptions.hpp>


#include "config/config.h"
#include "config/config_factory.h"
#include "property_tree_json_config.h"
#include "default_config_factory.h"
#include "utility/type.h"


using std::endl;
using std::cerr;
using std::string;
using boost::shared_ptr;
using boost::filesystem::exists;
using boost::property_tree::ptree_error;
using utility::TCPAddress;


namespace config {
namespace implementation {


class PropertyTreeJSONConfigFactory: public DefaultConfigFactory, public IConfigFactory {
public:
                PropertyTreeJSONConfigFactory();
    virtual    ~PropertyTreeJSONConfigFactory();

    virtual shared_ptr<const IConfig> createConfig();
};


} /* namespace implementation */
} /* namespace config */


#endif /* PROPERTY_TREE_JSON_CONFIG_FACTORY_H_ */
