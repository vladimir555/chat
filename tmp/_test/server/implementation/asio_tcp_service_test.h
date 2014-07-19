/*
 * asio_tcp_service_test.h
 *
 *  Created on: 04 мая 2014 г.
 *      Author: volodja
 */





#ifndef ASIO_TCP_SERVICE_TEST_H_
#define ASIO_TCP_SERVICE_TEST_H_


#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>


#include "server/implementation/asio_tcp_service.h"


#include "utility/logger.h"


using boost::asio::ip::tcp;
using boost::asio::ip::address;
using boost::asio::io_service;
using boost::shared_ptr;


using server::implementation::AsioTcpAcceptor;


namespace server {
namespace implementation {


BOOST_AUTO_TEST_CASE(testAsioTcpAcceptor) {
    LOG_DEFINE;

    tcp::endpoint               end_point(address::from_string("127.0.0.1"), 55555);
    io_service                  asio_service;
    shared_ptr<AsioTcpAcceptor> asio_tcp_acceptor = AsioTcpAcceptor::start(end_point, asio_service);
    LOG_DEBUG("sleep 10 sec");
    sleep(10);
    LOG_DEBUG("sleep 10 sec, OK");
}


}


}


#endif /* ASIO_TCP_SERVICE_TEST_H_ */
