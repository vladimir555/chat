/*
 * configuration.h
 *
 *  Created on: 19 марта 2014 г.
 *      Author: volodja
 */




#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_


#include <string>


using namespace std;


namespace configuration {


/**
 *  server configuration interface
 */
class Server {
public:
                    Server(){};
    virtual        ~Server(){};

    virtual string  getHost() const = 0;
    virtual string  getPort() const = 0;
};


/**
 *  client configuration interface
 */
class Client {
public:
                    Client(){};
    virtual        ~Client(){};

    virtual string  getHost() const = 0;
    virtual string  getPort() const = 0;
};


}


#endif /* CONFIGURATION_H_ */
