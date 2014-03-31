/*
 * config_factory.h
 *
 *  Created on: 31 марта 2014 г.
 *      Author: volodja
 */

#ifndef CONFIG_FACTORY_H_
#define CONFIG_FACTORY_H_


#include <boost/shared_ptr.hpp>


#include "config.h"


using boost::shared_ptr;


namespace config {


class IConfigFactory {
public:
                IConfigFactory() {};
    virtual    ~IConfigFactory() {};

    virtual shared_ptr<IConfig> createConfig() const = 0;
};


}


#endif /* CONFIG_FACTORY_H_ */
