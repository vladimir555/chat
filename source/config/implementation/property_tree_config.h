/*
 * property_tree_config.h
 *
 *  Created on: 26 марта 2014 г.
 *      Author: volodja
 */





#ifndef PROPERTY_TREE_CONFIG_H_
#define PROPERTY_TREE_CONFIG_H_


#include <string>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


using std::string;
using std::ifstream;
using std::ofstream;
using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


namespace config {
namespace implementation {


class PropertyTreeConfig {
public:
    void            readJSON (const string &file_name);
    void            writeJSON(const string &file_name);

protected:
                    PropertyTreeConfig();
    virtual        ~PropertyTreeConfig();

    template<typename Type>
    void setValue(const string &name, const Type &value) {
        property_tree.put(name, value);
    }

    template<typename Type>
    Type getValue(const string &name) const {
        return property_tree.get<Type>(name);
    }

private:
    ptree           property_tree;
};


} /* namespace implementation */
} /* namespace config */


#endif /* PROPERTY_TREE_CONFIG_H_ */
