/*
 * config_serialization.h
 *
 *  Created on: 24 марта 2014 г.
 *      Author: volodja
 */




#ifndef CONFIG_SERIALIZATION_H_
#define CONFIG_SERIALIZATION_H_


#include <string>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>


using namespace std;


namespace config {


namespace implementation {


class Chat {
public:
    Chat() {};
   ~Chat() {};

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &archive, const unsigned int version) {};
};


class Server {
public:
    Server();
   ~Server();

    string      getHost() const;
    uint16_t    getPort() const;

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &archive, const unsigned int version) {
        archive & BOOST_SERIALIZATION_NVP(host);
        archive & BOOST_SERIALIZATION_NVP(port);
    };

    string      host;
    uint16_t    port;
};


class Client: public Chat {
public:
    Client();
   ~Client();

    string      getHost() const;
    uint16_t    getPort() const;

private:
    string      host;
    uint16_t    port;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &archive, const unsigned int version) {
        archive & BOOST_SERIALIZATION_NVP(host);
        archive & BOOST_SERIALIZATION_NVP(port);
    };
};


} /* namespace implementation */


} /* namespace config */


#endif /* CONFIG_SERIALIZATION_H_ */
