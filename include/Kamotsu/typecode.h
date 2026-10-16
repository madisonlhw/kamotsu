#ifndef TYPECODE_H
#define TYPECODE_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

namespace kamotsu {
using nlohmann::json;

class TypeCode
{
public:
    TypeCode() = default;
    TypeCode(const std::string& path);
    virtual ~TypeCode() = default;

    void save(const std::string& path);

    std::string getIcao();
    void setIcao(const std::string& icao);
    std::string getManufacturer();
    void setManufacturer(const std::string& manufacturer);
    std::string getModel();
    void setModel(const std::string& model);
    std::vector<std::string> getTags();
    void setTags(const std::vector<std::string>& tags);

private:
    json document;
};
}

#endif // TYPECODE_H
