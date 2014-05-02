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


AsyncTCPAcceptor::ptr_t AsyncTCPAcceptor::start(const tcp::endpoint &end_point, io_service &service_id) {
    ptr_t   ptr(new AsyncTCPAcceptor(service_id));
    auto    stepHandler = bind(&AsyncTCPAcceptor::stepHandler, ptr, _1, 0);

    ptr->socket.async_connect(end_point, stepHandler);

    return ptr->shared_from_this();
}


void AsyncTCPAcceptor::stop() {
    LOG_DEBUG("stop");
}


void AsyncTCPAcceptor::stepHandler(const error_code &error, const size_t &buffer_size) {
    auto stepHandler    = bind(&AsyncTCPAcceptor::stepHandler, this, _1, _2);

    LOG_DEBUG("size = " + utility::toString(buffer_size));

    reenter(this) {
        LOG_DEBUG("on connect");
        while (true) {
            yield {
                LOG_DEBUG("on async_read_until");
                async_read_until(socket, read_buffer, string("0"), stepHandler);
            }
//            yield {
//                LOG_DEBUG("parse");
//                auto parseResponse  = bind(&AsyncTCPAcceptor::parseResponse, this);
//                service_id.post(parseResponse);
//            }
            yield {
                LOG_DEBUG("async_write");
                std::ostream buffer(&write_buffer);
                buffer << "write_buffer";
                async_write(socket, write_buffer, stepHandler);
            }
        };
    };
}


void AsyncTCPAcceptor::parseResponse() {
//    stringstream ss;
//    ss << &read_buffer;
//    LOG_DEBUG("response: '" + ss.str() + "'");
}


} /* namespace implementation */
} /* namespace config */
