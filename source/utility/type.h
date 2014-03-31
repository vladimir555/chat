/*
 * type.h
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */




#ifndef TYPE_H_
#define TYPE_H_


#include <string>


using std::string;


namespace utility {


class TCPAddress {
public:
    TCPAddress(const string &host, const uint16_t port);
   ~TCPAddress();

    string      getHost() const;
    uint16_t    getPort() const;

private:
    string      host;
    uint16_t    port;
};


} /* namespace utility */


#endif /* TYPE_H_ */
