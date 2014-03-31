/*
 * default_config_factory.h
 *
 *  Created on: 31 марта 2014 г.
 *      Author: volodja
 */





#ifndef DEFAULT_CONFIG_FACTORY_H_
#define DEFAULT_CONFIG_FACTORY_H_


#include <string>
#include <boost/shared_ptr.hpp>


#include "config/config.h"


using std::string;
using boost::shared_ptr;


namespace config {
namespace implementation {


class DefaultConfigFactory {
protected:
                DefaultConfigFactory();
    virtual    ~DefaultConfigFactory();

    void        makeDefaultConfig(shared_ptr<IConfigChangeable> config);

    static const string     DEFAULT_CONFIG_FILE_NAME;
    static const string     DEFAULT_SERVER_HOST;
    static const uint16_t   DEFAULT_SERVER_PORT;
    static const string     DEFAULT_SERVER_DB_HOST;
    static const uint16_t   DEFAULT_SERVER_DB_PORT;
    static const string     DEFAULT_CLIENT_HOST;
    static const uint16_t   DEFAULT_CLIENT_PORT;
};


} /* namespace implementation */
} /* namespace config */


#endif /* DEFAULT_CONFIG_FACTORY_H_ */
