/*
 * async_tcp_service.h
 *
 *  Created on: 30 апр. 2014 г.
 *      Author: volodja
 */





#ifndef ASYNC_TCP_SERVICE_H_
#define ASYNC_TCP_SERVICE_H_


#include <ostream>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/yield.hpp>


#include "utility/to_string.h"
#include "utility/type.h"
#include "utility/logger.h"


using std::ostream;
using boost::shared_ptr;
using boost::bind;
using boost::noncopyable;
using boost::enable_shared_from_this;
using boost::asio::coroutine;
using boost::asio::streambuf;
using boost::asio::async_read_at;
using boost::asio::async_read_until;
using boost::asio::async_write;
using boost::asio::ip::tcp;
using boost::asio::io_service;
using boost::system::error_code;
using utility::TCPAddress;
using utility::toString;


namespace server {
namespace implementation {


class AsioTcpAcceptor:
    public  enable_shared_from_this<AsioTcpAcceptor>,
    private coroutine, noncopyable
{
public:
    virtual        ~AsioTcpAcceptor();

    static shared_ptr<AsioTcpAcceptor>
                    start(const tcp::endpoint &end_point, io_service &service_id);
    void            stop();

private:
    LOG_DEFINE;
    io_service     &service_id;
    streambuf       read_buffer;
    streambuf       write_buffer;
    tcp::socket     socket;

                    AsioTcpAcceptor(io_service &service_id);
    void            stepHandler(const error_code &error, const size_t &buffer_size);
    void            parseResponse();
};


} /* namespace implementation */
} /* namespace config */


#endif /* ASYNC_TCP_SERVICE_H_ */
