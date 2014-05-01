/*
 * tcp_service.h
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */





#ifndef ASIO_TCP_SERVICE_H_
#define ASIO_TCP_SERVICE_H_


#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>


#include "server/service.h"
#include "utility/type.h"
#include "utility/logger.h"


using boost::shared_ptr;
using boost::bind;
using std::vector;
using utility::TCPAddress;
using boost::system::error_code;
using boost::lexical_cast;


using namespace boost::asio;


namespace server {
namespace implementation {


class EndPoint {
public:
    explicit    EndPoint(const TCPAddress &listen_address);
    virtual    ~EndPoint();

    void        start();
    void        stop();

private:
    LOG_DEFINE;

    ip::tcp::endpoint   end_point;
    io_service          service;
};


} /* namespace implementation */
} /* namespace server */


#endif /* ASIO_TCP_SERVICE_H_ */
