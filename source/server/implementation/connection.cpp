/*
 * asio_tcp_connection.cpp
 *
 *  Created on: 16 апр. 2014 г.
 *      Author: volodja
 */





#include "connection.h"


namespace server {
namespace implementation {


//Connection::Connection(EndPoint &end_point)
//{}
//
//
//Connection::~Connection() {
//}
//
//
//void Connection::addTaskConnect() {
////    socket.async_connect(end_point, bind(&ASIOTCPService::onConnect, this, _1));
//}
//
//
//void Connection::addTaskRead() {
////    socket.async_read_some(buffer(read_buffer), bind(&ASIOTCPService::onRead, boost::shared_ptr<ASIOTCPService>(this), _1, _2));
//}
//
//
//void Connection::addTaskWrite(const string &message) {
////    socket.async_write_some(buffer(message), bind(&ASIOTCPService::onWrite, this, _1, _2));
//}
//
//
//void Connection::onRead(const error_code &error, const size_t &read_size) {
////    LOG_DEBUG("read: " + string().assign(read_buffer.begin(), read_buffer.end()));
//    addTaskWrite("test message");
//}
//
//
//void Connection::onWrite(const error_code &error, const size_t &write_size) {
////    LOG_DEBUG("write");
//    addTaskConnect();
//}
//
//
//void Connection::onConnect(const error_code &error) {
////    LOG_DEBUG("connect");
//    addTaskRead();
//}


} /* namespace implementation */
} /* namespace server */
