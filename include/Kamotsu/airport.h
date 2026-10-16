#ifndef AIRPORT_H
#define AIRPORT_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include <Kamotsu/filehandler.h>

namespace kamotsu {
using nlohmann::json;

class Airport
{
public:
    Airport() = default;
    Airport(const std::string& path);
    virtual ~Airport() = default;

    void save(const std::string& path);

    std::string getIata();
    void setIata(const std::string& iata);
    std::string getIcao();
    void setIcao(const std::string& icao);
    std::string getName();
    void setName(const std::string& name);
    std::string getCity();
    void setCity(const std::string& city);
    std::string getState();
    void setState(const std::string& state);
    std::string getCountry();
    void setCountry(const std::string& country);
    std::string getCountryCode();
    void setCountryCode(const std::string& countryCode);
    std::vector<std::string> getTags();
    void setTags(const std::vector<std::string>& tags);

private:
    json document;
};
}

#endif // AIRPORT_H
