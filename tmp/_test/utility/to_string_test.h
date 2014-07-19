/*
 * to_string.h
 *
 *  Created on: 03 мая 2014 г.
 *      Author: volodja
 */





#ifndef TO_STRING_TEST_H_
#define TO_STRING_TEST_H_


#include <boost/test/unit_test.hpp>


#include "utility/to_string.h"


namespace utility {


BOOST_AUTO_TEST_CASE(testToStringt) {
    BOOST_CHECK_EQUAL("5.5", toString(5.5));
}


}


#endif /* TO_STRING_TEST_H_ */
