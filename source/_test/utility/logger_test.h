/*
 * logger_test.h
 *
 *  Created on: 01 июля 2014 г.
 *      Author: ?
 */





#ifndef LOGGER_TEST_H_
#define LOGGER_TEST_H_


#include "utility/logger.h"


class Test {
public:
    Test() {}

    ~Test() {}

    void log() {
        LOG_DEBUG   ("debug");
        LOG_INFO    ("info");
        LOG_WARN    ("warn");
        LOG_ERROR   ("error");
        LOG_FATAL   ("fatal");
        LOG_INFO    ("sleep 1 sec");
        sleep(1);
        LOG_INFO    ("sleep 1 sec OK");
    }

private:
    LOG_DEFINE;
};


LOG_IMPLEMENT(Test);


BOOST_AUTO_TEST_CASE(testLogger) {
    LOG_INIT;

    Test test;
    test.log();
}


#endif /* LOGGER_TEST_H_ */
