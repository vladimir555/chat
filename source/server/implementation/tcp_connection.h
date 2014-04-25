/*
 * tcp_connection.h
 *
 *  Created on: 16 апр. 2014 г.
 *      Author: volodja
 */





#ifndef TCP_CONNECTION_H_
#define TCP_CONNECTION_H_


#include <boost/noncopyable.hpp>


using boost::noncopyable;


namespace server {
namespace implementation {


class TCPConnection: private noncopyable {
public:
    TCPConnection();
    virtual ~TCPConnection();
};


} /* namespace implementation */
} /* namespace server */


#endif /* TCP_CONNECTION_H_ */
