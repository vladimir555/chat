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


namespace server {
namespace implementation {


BOOST_AUTO_TEST_CASE(testAsioTcpAcceptor) {
}


}


}


#endif /* ASIO_TCP_SERVICE_TEST_H_ */
