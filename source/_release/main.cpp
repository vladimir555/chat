/*
 * main.cpp
 *
 *  Created on: 19 марта 2014 г.
 *      Author: volodja
 */





#include "main.h"


#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>


#include "config/config_factory.h"
#include "config/implementation/property_tree_json_config_factory.h"
#include "config/config.h"
#include "server/server_config.h"
#include "server/implementation/server_config_adapter.h"
#include "server/implementation/async_tcp_service.h"


using config::IConfigFactory;
using config::implementation::PropertyTreeJSONConfigFactory;
using config::IConfig;
using boost::shared_ptr;
using server::IServerConfig;
using server::implementation::ServerConfigAdapter;
using server::implementation::AsyncTCPAcceptor;


using namespace boost::asio;


int main() {
    shared_ptr<IConfigFactory>      config_factory(new PropertyTreeJSONConfigFactory());
    shared_ptr<const IConfig>       config = config_factory->createConfig();
    shared_ptr<const IServerConfig> server_config(new ServerConfigAdapter(config));

    TCPAddress          address("127.0.0.1", 8888);
    io_service          service_id;
    ip::tcp::endpoint   end_point(ip::address::from_string("127.0.0.1"), 8888);
    AsyncTCPAcceptor    async_tcp_acceptor(service_id);

    async_tcp_acceptor.start(end_point);
    LOG_DEBUG("service run");
    service_id.run();
    LOG_DEBUG("sleep 10 sec");
    sleep(10);
    async_tcp_acceptor.stop();

    return 0;
}
