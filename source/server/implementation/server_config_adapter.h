/*
 * server_config_adapter.h
 *
 *  Created on: 05 апр. 2014 г.
 *      Author: volodja
 */





#ifndef SERVER_CONFIG_ADAPTER_H_
#define SERVER_CONFIG_ADAPTER_H_


#include <boost/shared_ptr.hpp>


#include "config/config.h"
#include "server/server_config.h"


using boost::shared_ptr;
using config::IConfig;


namespace server {
namespace implementation {


class ServerConfigAdapter: public IServerConfig {
public:
                ServerConfigAdapter(shared_ptr<const IConfig> config);
    virtual    ~ServerConfigAdapter();

    virtual TCPAddress getAddress()   const;
    virtual TCPAddress getDBAddress() const;

private:
    shared_ptr<const IConfig> config;
};


} /* namespace implementation */
} /* namespace server */


#endif /* SERVER_CONFIG_ADAPTER_H_ */
