/*
 * logger.h
 *
 *  Created on: 08.12.2011
 *      Author: volodja
 */


#ifndef LINUX_LOGGER_H_
#define LINUX_LOGGER_H_


//-----BoostLog
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <iostream>


#define LOG_INIT                                                                            \
{                                                                                           \
    using namespace boost::log;                                                             \
                                                                                            \
    formatter f(                                                                            \
        expressions::stream <<                                                              \
        expressions::format_date_time< boost::posix_time::ptime >                           \
            ("TimeStamp", "%Y-%m-%d %H:%M:%S") <<                                           \
            " │ "  <<                                                                       \
            trivial::severity <<                                                            \
            "\t│ " <<                                                                       \
            expressions::smessage                                                           \
    );                                                                                      \
                                                                                            \
    boost::shared_ptr<sinks::synchronous_sink<sinks::text_ostream_backend> > console_sink(  \
        new           sinks::synchronous_sink<sinks::text_ostream_backend> ()               \
    );                                                                                      \
    console_sink->locked_backend()->add_stream(                                             \
        boost::shared_ptr<std::ostream>(&std::cout, [](std::ostream*){}));                  \
    console_sink->set_formatter(f);                                                         \
                                                                                            \
    boost::shared_ptr<sinks::synchronous_sink<sinks::text_file_backend> > file_sink (       \
        new           sinks::synchronous_sink<sinks::text_file_backend> (                   \
            keywords::file_name             = "chat-%N.log",                                \
            keywords::rotation_size         = 10 * 1024 * 1024,                             \
            keywords::auto_flush            = true,                                         \
            keywords::time_based_rotation   =                                               \
                sinks::file::rotation_at_time_point(0, 0, 0)                                \
        )                                                                                   \
    );                                                                                      \
    file_sink->locked_backend()->set_file_collector(                                        \
        sinks::file::make_collector(                                                        \
            keywords::target                = "./",                                         \
            keywords::max_size              = 100*1024*1024,                                \
            keywords::min_free_space        = 100*1024*1024                                 \
        )                                                                                   \
    );                                                                                      \
    file_sink->set_formatter(f);                                                            \
    file_sink->locked_backend()->scan_for_files();                                          \
                                                                                            \
    core::get()->add_sink(file_sink);                                                       \
    core::get()->add_sink(console_sink);                                                    \
                                                                                            \
    add_common_attributes();                                                                \
};
#define LOG_FUNCTION(level, message) {          \
    BOOST_LOG_SEV(logger, level) << message;    \
};
#define LOG_DEBUG(message) LOG_FUNCTION(boost::log::trivial::debug, message);
#define  LOG_INFO(message) LOG_FUNCTION(boost::log::trivial::info, message);
#define  LOG_WARN(message) LOG_FUNCTION(boost::log::trivial::warning, message);
#define LOG_ERROR(message) LOG_FUNCTION(boost::log::trivial::error, message);
#define LOG_FATAL(message) LOG_FUNCTION(boost::log::trivial::fatal, message);
#define LOG_DEFINE                                                                                  \
    static boost::log::sources::severity_logger< boost::log::trivial::severity_level > logger;
#define LOG_IMPLEMENT(class_)                                                                       \
    boost::log::sources::severity_logger< boost::log::trivial::severity_level > class_::logger =    \
    boost::log::sources::severity_logger< boost::log::trivial::severity_level >();
//-----


/*
//LogCap
#define LOG_INIT ;
#define LOG_DEBUG(message_);
#define LOG_INFO(message_);
#define LOG_WARN(message_);
#define LOG_ERROR(message_);
#define LOG_FATAL(message_);
#define LOG_DEFINE
#define LOG_IMPLEMENT(class_);
*/


/*
//Log4CPlus
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <string>


#define LOG_INIT ;
#define LOG_DEBUG(message_) LOG4CPLUS_DEBUG(logger,message_);
#define LOG_INFO(message_) LOG4CPLUS_INFO(logger,message_);
#define LOG_WARN(message_) LOG4CPLUS_WARN(logger,message_);
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
*/


/*
//Log4Cxx
#include <log4cxx/logger.h>
#include <iomanip>
#include <string>
#define LOG_INIT ;
#define LOG_DEBUG(message_) LOG4CXX_DEBUG(logger,message_);
#define LOG_INFO(message_)  LOG4CXX_INFO(logger,message_);
#define LOG_WARN(message_)  LOG4CXX_WARN(logger,message_);
#define LOG_ERROR(message_) LOG4CXX_ERROR(logger,message_);
#define LOG_FATAL(message_) LOG4CXX_FATAL(logger,message_);
#define LOG_DEFINE                                                          \
static log4cxx::LoggerPtr logger;                                           \
static log4cxx::LoggerPtr loggerInit(const std::string &class_name) {       \
    return log4cxx::Logger::getLogger(class_name);                          \
}
#define LOG_IMPLEMENT(class_) log4cxx::LoggerPtr class_::logger = class_::loggerInit(#class_)
*/


#endif /* LINUX_LOGGER_H_ */
