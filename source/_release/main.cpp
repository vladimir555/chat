/*
 * main.cpp
 *
 *  Created on: 19 марта 2014 г.
 *      Author: volodja
 */





#include "main.h"


#include <boost/shared_ptr.hpp>
#include "config/implementation/config_factory.h"
#include "config/config.h"


using config::implementation::ConfigFactory;
using config::IConfig;
using boost::shared_ptr;


int main() {
    ConfigFactory       config_factory;
    shared_ptr<IConfig> config = config_factory.buildConfig();

    return 0;
}
