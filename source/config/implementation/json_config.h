/*
 * json_config.h
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */




#ifndef JSON_CONFIG_H_
#define JSON_CONFIG_H_


#include <string>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>


using namespace std;


namespace config {


class Chat {
public:
    Chat() {};
   ~Chat() {};

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &archive, const unsigned int version) {};
};


class Server: public Chat {
public:
    Server();
   ~Server();

    string      getHost() const;
    uint16_t    getPort() const;

private:
    friend class boost::serialization::access;

    string      host;
    uint16_t    port;

    template<class Archive>
    void serialize(Archive &archive, const unsigned int version) {
        archive & BOOST_SERIALIZATION_NVP(host);
        archive & BOOST_SERIALIZATION_NVP(port);
    };
};


class Client: public Chat {
public:
    Client();
   ~Client();

    string      getHost() const;
    uint16_t    getPort() const;

private:
    friend class boost::serialization::access;

    string      host;
    uint16_t    port;

    template<class Archive>
    void serialize(Archive &archive, const unsigned int version) {
        archive & BOOST_SERIALIZATION_NVP(host);
        archive & BOOST_SERIALIZATION_NVP(port);
    };
};


} /* namespace config */


#endif /* JSON_CONFIG_H_ */
