#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "airline.h"
#include "typecode.h"

namespace kamotsu {
using nlohmann::json;

class Aircraft
{
public:
    Aircraft() = default;
    Aircraft(const std::string& path);
    virtual ~Aircraft() = default;

    void save(const std::string& path);

    std::string getRegistration();
    void setRegistration(const std::string& registration);
    std::string getSerialNumber();
    void setSerialNumber(const std::string& serialNumber);
    std::string getLineNumber();
    void setLineNumber(const std::string& lineNumber);
    TypeCode getTypeCode();
    void setTypeCode(TypeCode typecode);
    Airline getAirline();
    void setAirline(Airline airline);

private:
    json document;
};
}

#endif // AIRCRAFT_H
