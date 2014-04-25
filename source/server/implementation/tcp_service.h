/*
 * tcp_service.h
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */





#ifndef TCP_SERVICE_H_
#define TCP_SERVICE_H_


#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include "utility/logger.h"


#include "tcp_connection.h"
#include "server/service.h"
#include "utility/type.h"


using boost::shared_ptr;
using boost::bind;
using std::vector;
using utility::TCPAddress;
using boost::system::error_code;
using boost::lexical_cast;


using namespace boost::asio;



namespace server {
namespace implementation {


class ASIOTCPService: public IService, private boost::noncopyable {
public:
    explicit    ASIOTCPService(const TCPAddress &listen_address);
    virtual    ~ASIOTCPService();

    void        initialize();
    void        finalize();

private:
    LOG_DEFINE;

    TCPAddress          listen_address;
    io_service          service;
    ip::tcp::socket     socket;
    ip::address         address;
    ip::tcp::endpoint   end_point;
    ip::tcp::acceptor   acceptor;

    void        startAccept();

    void        handleAccept(const error_code &error);
};


} /* namespace implementation */
} /* namespace server */


#endif /* TCP_SERVICE_H_ */
