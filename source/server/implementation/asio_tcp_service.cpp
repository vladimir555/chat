/*
 * asio_tcp_service.cpp
 *
 *  Created on: 30 апр. 2014 г.
 *      Author: volodja
 */





#include "asio_tcp_service.h"


namespace server {
namespace implementation {


LOG_IMPLEMENT(AsioTcpAcceptor);


AsioTcpAcceptor::AsioTcpAcceptor(io_service &service_id)
:
    service_id  (service_id),
    socket      (service_id)
{}


AsioTcpAcceptor::~AsioTcpAcceptor() {
}


shared_ptr<AsioTcpAcceptor> AsioTcpAcceptor::start(const tcp::endpoint &end_point, io_service &service_id) {
    shared_ptr<AsioTcpAcceptor> asio_tcp_acceptor(new AsioTcpAcceptor(service_id));
    auto    stepHandler = bind(&AsioTcpAcceptor::stepHandler, asio_tcp_acceptor, _1, 0);

    //do connect
    asio_tcp_acceptor->socket.async_connect(end_point, stepHandler);

    LOG_DEBUG("start");

    return asio_tcp_acceptor->shared_from_this();
}


void AsioTcpAcceptor::stop() {
    LOG_DEBUG("stop");
}


void AsioTcpAcceptor::stepHandler(const error_code &error, const size_t &buffer_size) {
    auto stepHandler    = bind(&AsioTcpAcceptor::stepHandler, this, _1, _2);

    static int step_handler_i = 0;

    LOG_DEBUG("step_handler_i = " + utility::toString(step_handler_i));

    reenter(this) {
        LOG_DEBUG("connect");
        // on connect
        while (true) {

            // on write
            yield {
//                LOG_DEBUG("was written " + toString(buffer_size) + " bytes");
                // do read
                async_read_until(socket, read_buffer, string("\n"), stepHandler);
            }

//            yield {
//                LOG_DEBUG("parse");
//                auto parseResponse  = bind(&AsyncTCPAcceptor::parseResponse, this);
//                service_id.post(parseResponse);
//            }

            // on read
            yield {
                LOG_DEBUG("was read " + toString(buffer_size) + " bytes");

                string  write_string = "sdfsdf";
                ostream out(&write_buffer);

                out << write_string;

                LOG_DEBUG("write '" + write_string + "'");

                //do write
                if (buffer_size > 0)
                    async_write(socket, write_buffer, stepHandler);
                else
                    LOG_DEBUG("empty read_buffer, exit");
            }
        };
    };
}


void AsioTcpAcceptor::parseResponse() {
//    stringstream ss;
//    ss << &read_buffer;
//    LOG_DEBUG("response: '" + ss.str() + "'");
}


} /* namespace implementation */
} /* namespace config */
