/*
 * config.h
 *
 *  Created on: 19 марта 2014 г.
 *      Author: volodja
 */




#ifndef CONFIG_H_
#define CONFIG_H_


#include <string>


using namespace std;


namespace config {


/**
 *  server configuration interface
 */
class IConfig {
public:
                    IConfig() {};
    virtual        ~IConfig() {};

    virtual string  getListenHost() const = 0;
    virtual int16_t getListenPort() const = 0;

    virtual string  getDataBaseHost() const = 0;
    virtual int16_t getDataBasePort() const = 0;
};


}


#endif /* CONFIG_H_ */
