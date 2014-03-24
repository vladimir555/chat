/*
 * tcp_service.h
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */




#ifndef TCP_SERVICE_H_
#define TCP_SERVICE_H_


#include "config/config.h"
#include "server/server.h"


using config::IConfig;


namespace server {


class TcpService: public IService {
public:
                TcpService(const IConfig &configuration);
    virtual    ~TcpService();

    void        initialize();
};


} /* namespace server */


#endif /* TCP_SERVICE_H_ */
