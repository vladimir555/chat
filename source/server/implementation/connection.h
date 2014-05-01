/*
 * asio_tcp_connection.h
 *
 *  Created on: 16 апр. 2014 г.
 *      Author: volodja
 */





#ifndef ASIO_TCP_CONNECTION_H_
#define ASIO_TCP_CONNECTION_H_


#include <string>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>


#include "end_point.h"
//#include "utility/logger.h"


using boost::noncopyable;
using boost::system::error_code;
using std::string;


using namespace boost::asio;


namespace server {
namespace implementation {


//class Connection: private noncopyable {
//public:
//     Connection(server::implementation::EndPoint &end_point);
//    virtual    ~Connection();
//
//private:
//    //ASIOTCPService &service;
//
//
//
//    void        addTaskConnect();
//    void        addTaskRead();
//    void        addTaskWrite(const string &message);
//
//    void        onRead   (const error_code &error, const size_t &read_size);
//    void        onWrite  (const error_code &error, const size_t &write_size);
//    void        onConnect(const error_code &error);
//};


} /* namespace implementation */
} /* namespace server */


#endif /* ASIO_TCP_CONNECTION_H_ */
