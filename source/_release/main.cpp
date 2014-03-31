/*
 * main.cpp
 *
 *  Created on: 19 марта 2014 г.
 *      Author: volodja
 */





#include "main.h"


#include <boost/shared_ptr.hpp>
#include "config/config_factory.h"
#include "config/implementation/property_tree_json_config_factory.h"
#include "config/config.h"


using config::IConfigFactory;
using config::implementation::PropertyTreeJSONConfigFactory;
using config::IConfig;
using boost::shared_ptr;


int main() {
    shared_ptr<IConfigFactory>  config_factory(new PropertyTreeJSONConfigFactory());
    shared_ptr<IConfig>         config = config_factory->createConfig();

    return 0;
}
