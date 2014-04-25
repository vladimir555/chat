/*
 * logger.h
 *
 *  Created on: 08.12.2011
 *      Author: volodja
 */


#ifndef LINUX_LOGGER_H_
#define LINUX_LOGGER_H_


#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <string>


#define LOG_DEBUG(message_) LOG4CPLUS_DEBUG(logger,message_)
#define LOG_INFO(message_) LOG4CPLUS_INFO(logger,message_)
#define LOG_WARN(message_) LOG4CPLUS_WARN(logger,message_)
#define LOG_ERROR(message_) LOG4CPLUS_ERROR(logger,message_);
#define LOG_FATAL(message_) LOG4CPLUS_FATAL(logger,message_);
#define LOG_DEFINE                                                          \
static log4cplus::Logger logger;                                            \
static log4cplus::Logger loggerInit(const std::string &class_name) {        \
    log4cplus::Logger logger = log4cplus::Logger::getInstance(class_name);  \
    log4cplus::BasicConfigurator config;                                    \
    config.configure();                                                     \
    return logger;                                                          \
}
#define LOG_IMPLEMENT(class_) log4cplus::Logger class_::logger = class_::loggerInit((#class_))


/*
//#include <log4cxx/logger.h>
//#include <iomanip>
//#include <string>
//#define LOG_DEBUG(message_) LOG4CXX_DEBUG(logger,message_);
//#define LOG_INFO(message_)  LOG4CXX_INFO(logger,message_);
//#define LOG_WARN(message_)  LOG4CXX_WARN(logger,message_);
//#define LOG_ERROR(message_) LOG4CXX_ERROR(logger,message_);
//#define LOG_FATAL(message_) LOG4CXX_FATAL(logger,message_);
//#define LOG_DEFINE                                                          \
//static log4cxx::LoggerPtr logger;                                           \
//static log4cxx::LoggerPtr loggerInit(const std::string &class_name) {       \
//    return log4cxx::Logger::getLogger(class_name);                          \
//}
//#define LOG_IMPLEMENT(class_) log4cxx::LoggerPtr class_::logger = class_::loggerInit(#class_)
*/


#endif /* LINUX_LOGGER_H_ */

