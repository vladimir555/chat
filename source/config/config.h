/*
 * config.h
 *
 *  Created on: 19 марта 2014 г.
 *      Author: volodja
 */





#ifndef CONFIG_H_
#define CONFIG_H_


#include <string>


#include "utility/type.h"


using utility::TCPAddress;


namespace config {


class IConfig {
public:
                    IConfig() {};
    virtual        ~IConfig() {};

    virtual TCPAddress getServerAddress()   const = 0;
    virtual TCPAddress getServerDBAddress()       const = 0;
    virtual TCPAddress getClientAddress()   const = 0;
};


class IConfigChangeable: public IConfig {
public:
    IConfigChangeable() {};
   ~IConfigChangeable() {};

   virtual void setServerAddress  (const TCPAddress &tcp_address) = 0;
   virtual void setServerDBAddress(const TCPAddress &tcp_address) = 0;
   virtual void setClientAddress  (const TCPAddress &tcp_address) = 0;
};


}


#endif /* CONFIG_H_ */
