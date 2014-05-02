/*
 * to_string.cpp
 *
 *  Created on: 03 мая 2014 г.
 *      Author: volodja
 */





#include "to_string.h"


namespace utility {


template<>
string toString<boost::asio::streambuf>(const boost::asio::streambuf &t) {
    stringstream ss;
    ss << &t;
    return ss.str();
}


}
