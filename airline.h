#ifndef AIRLINE_H
#define AIRLINE_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

namespace kamotsu {
using nlohmann::json;

class Airline
{
public:
    Airline() = default;
    Airline(const std::string& path);
    virtual ~Airline() = default;

    void save(const std::string& path);

    std::string getIata();
    void setIata(const std::string& iata);
    std::string getIcao();
    void setIcao(const std::string& icao);
    std::string getName();
    void setName(const std::string& name);
    std::string getCallsign();
    void setCallsign(const std::string& callsign);
    std::vector<std::string> getTags();
    void setTags(const std::vector<std::string>& tags);

private:
    json document;
};

}
#endif // AIRLINE_H
