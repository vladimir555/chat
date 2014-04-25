/*
 * tcp_service.cpp
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */





#include "tcp_service.h"


namespace server {
namespace implementation {


LOG_IMPLEMENT(ASIOTCPService);


ASIOTCPService::ASIOTCPService(const TCPAddress &listening_address)
:
    listen_address      (listening_address),
    socket              (service),
    address             (ip::address::from_string(listen_address.getHost())),
    end_point           (address, listen_address.getPort()),
    acceptor            (service, end_point)
{}


ASIOTCPService::~ASIOTCPService() {
}


void ASIOTCPService::initialize() {
    LOG_DEBUG("initialize tcp service, listen address: " +
            lexical_cast<string>(listen_address.getHost()) + ":" +
            lexical_cast<string>(listen_address.getPort()));
    acceptor.async_accept(socket, bind(&ASIOTCPService::handleAccept, this, _1));
    service.run();
}


void ASIOTCPService::finalize() {
    LOG_DEBUG("finalize tcp service");
}


void ASIOTCPService::startAccept() {
}


void ASIOTCPService::handleAccept(const error_code &error) {
    LOG_DEBUG("handleAccept");
    if (error) {
        LOG_ERROR("asio handle accept error: ");
    } else {
        size_t response_size = 0;
        do {
            vector<unsigned char>   buffer(8);
            response_size = socket.read_some(boost::asio::buffer(buffer.data(), buffer.size()));
            LOG_DEBUG("read: " << string().assign(buffer.begin(), buffer.end()));
        } while (response_size > 0);
    }
    socket.close();
//    acceptor.async_accept(socket, bind(&TCPService::handleAccept, this, _1));
}


} /* namespace implementation */
} /* namespace server */
