/*
 * asio_tcp_service.cpp
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */





#include "end_point.h"


namespace server {
namespace implementation {


LOG_IMPLEMENT(EndPoint);


EndPoint::EndPoint(const TCPAddress &listen_address)
:
    end_point(ip::address::from_string(listen_address.getHost()), listen_address.getPort()),
    service()
{}


EndPoint::~EndPoint() {
}


void EndPoint::start() {
    LOG_INFO("start tcp service, listen address: " +
            lexical_cast<string>(end_point.address()) + ":" +
            lexical_cast<string>(end_point.port()));

//    service.run();
}


void EndPoint::stop() {
    LOG_INFO("stop tcp service");
}


} /* namespace implementation */
} /* namespace server */
