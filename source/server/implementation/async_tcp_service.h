/*
 * async_tcp_service.h
 *
 *  Created on: 30 апр. 2014 г.
 *      Author: volodja
 */





#ifndef ASYNC_TCP_SERVICE_H_
#define ASYNC_TCP_SERVICE_H_


#include <sstream>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/yield.hpp>


#include "utility/type.h"
#include "utility/logger.h"


using std::stringstream;
using boost::bind;
using boost::noncopyable;
using boost::asio::coroutine;
using boost::asio::streambuf;
using boost::asio::async_read_until;
using boost::asio::async_write;
using boost::asio::ip::tcp;
using boost::asio::io_service;
using boost::system::error_code;
using utility::TCPAddress;



namespace server {
namespace implementation {


class AsyncTCPAcceptor: private coroutine, noncopyable {
public:
                AsyncTCPAcceptor(io_service &service_id);
    virtual    ~AsyncTCPAcceptor();

    void        start(const tcp::endpoint &end_point);
    void        stop();

private:
    io_service     &service_id;

    streambuf       read_buffer;
    streambuf       write_buffer;

    tcp::socket     socket;

    void        stepHandler(const error_code &error, const size_t &buffer_size);

    void        parseResponse();
};


} /* namespace implementation */
} /* namespace config */


#endif /* ASYNC_TCP_SERVICE_H_ */
