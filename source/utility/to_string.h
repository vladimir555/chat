/*
 * to_string.h
 *
 *  Created on: 03 мая 2014 г.
 *      Author: volodja
 */

#ifndef TO_STRING_H_
#define TO_STRING_H_


#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/asio/streambuf.hpp>


using std::string;
using std::stringstream;
using boost::lexical_cast;


namespace utility {


template<typename T>
string toString(const T &t) {
    return lexical_cast<string>(t);
}


template<>
string toString<boost::asio::streambuf>(const boost::asio::streambuf &t);


} /* utility */


#endif /* TO_STRING_H_ */
