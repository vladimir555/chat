/*
 * server_config.h
 *
 *  Created on: 04 апр. 2014 г.
 *      Author: volodja
 */





#ifndef SERVER_CONFIG_H_
#define SERVER_CONFIG_H_


#include "utility/type.h"


using utility::TCPAddress;


namespace server {


class IServerConfig {
public:
            IServerConfig() {};
   virtual ~IServerConfig() {};

   virtual TCPAddress getAddress()   const = 0;
   virtual TCPAddress getDBAddress() const = 0;
};


}


#endif /* SERVER_CONFIG_H_ */
