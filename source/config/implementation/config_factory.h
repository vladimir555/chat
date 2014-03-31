/*
 * config_factory.h
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#ifndef CONFIG_FACTORY_H_
#define CONFIG_FACTORY_H_


#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>


#include "config/config.h"
#include "property_tree_json_config.h"
#include "utility/type.h"



using std::endl;
using std::cerr;
using std::string;
using boost::shared_ptr;
using boost::filesystem::exists;
using utility::TCPAddress;



namespace config {
namespace implementation {


class ConfigFactory {
public:
                            ConfigFactory();
    virtual                ~ConfigFactory();

    shared_ptr<IConfig>     buildConfig();

private:
    static const string     DEFAULT_CONFIG_FILE_NAME;
    static const string     DEFAULT_SERVER_HOST;
    static const uint16_t   DEFAULT_SERVER_PORT;
    static const string     DEFAULT_SERVER_DB_HOST;
    static const uint16_t   DEFAULT_SERVER_DB_PORT;
    static const string     DEFAULT_CLIENT_HOST;
    static const uint16_t   DEFAULT_CLIENT_PORT;

    void                    makeDefaultConfig(shared_ptr<IConfigChangeable> config);
};


} /* namespace implementation */
} /* namespace config */


#endif /* CONFIG_FACTORY_H_ */
