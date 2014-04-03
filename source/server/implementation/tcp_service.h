/*
 * tcp_service.h
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */





#ifndef TCP_SERVICE_H_
#define TCP_SERVICE_H_


#include <boost/shared_ptr.hpp>


//#include "config/config.h"
#include "server/service.h"


using boost::shared_ptr;
//using config::IConfig;


namespace server {


class TCPService: public IService {
public:
                TCPService(/*const shared_ptr<IConfig> config*/);
    virtual    ~TCPService();

    void        initialize();
};


} /* namespace server */


#endif /* TCP_SERVICE_H_ */
