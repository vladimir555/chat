/*
 * property_tree_json_config.h
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#ifndef PROPERTY_TREE_JSON_CONFIG_H_
#define PROPERTY_TREE_JSON_CONFIG_H_


#include <string>


#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


#include "property_tree_config.h"
#include "config/config.h"
#include "utility/type.h"


using utility::TCPAddress;
using std::string;
using boost::property_tree::ptree;
using boost::property_tree::json_parser::read_json;


namespace config {
namespace implementation {


class PropertyTreeJSONConfig: public PropertyTreeConfig, public IConfigChangeable {
public:
                PropertyTreeJSONConfig(const string &file_name);
    virtual    ~PropertyTreeJSONConfig();

    //---IConfig
    virtual TCPAddress  getServerAddress()   const;
    virtual TCPAddress  getDBAddress()       const;
    virtual TCPAddress  getClientAddress()   const;

    virtual void setServerAddress  (const TCPAddress &tcp_address);
    virtual void setServerDBAddress(const TCPAddress &tcp_address);
    virtual void setClientAddress  (const TCPAddress &tcp_address);
    //---

private:
    string              file_name;
};


} /* namespace implementation */
} /* namespace config */


#endif /* PROPERTY_TREE_JSON_CONFIG_H_ */
