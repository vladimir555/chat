/*
 * async_tcp_service.cpp
 *
 *  Created on: 30 апр. 2014 г.
 *      Author: volodja
 */





#include "async_tcp_service.h"


namespace server {
namespace implementation {


AsyncTCPAcceptor::AsyncTCPAcceptor(io_service &service_id)
:
    service_id  (service_id),
    socket      (service_id)
{}


AsyncTCPAcceptor::~AsyncTCPAcceptor() {
}


void AsyncTCPAcceptor::start(const tcp::endpoint &end_point) {
    LOG_DEBUG("start");
    auto stepHandler    = bind(&AsyncTCPAcceptor::stepHandler, this, _1, 0);
    socket.async_connect(end_point, stepHandler);
}


void AsyncTCPAcceptor::stop() {
    LOG_DEBUG("stop");
}


void AsyncTCPAcceptor::stepHandler(const error_code &error, const size_t &buffer_size) {
    auto stepHandler    = bind(&AsyncTCPAcceptor::stepHandler, this, _1, _2);
    auto parseResponse  = bind(&AsyncTCPAcceptor::parseResponse, this);
    LOG_DEBUG("connect");
    reenter(this) {
//        while (true) {
        for (;;) {
            yield async_read_until  (socket, read_buffer, string("\n"), stepHandler);
            yield service_id.post(parseResponse);
            yield async_write       (socket, write_buffer, stepHandler);
        };
    };
}


void AsyncTCPAcceptor::parseResponse() {
    stringstream ss;
    ss << &read_buffer;
    LOG_DEBUG("response: " + ss.str());
}


} /* namespace implementation */
} /* namespace config */
