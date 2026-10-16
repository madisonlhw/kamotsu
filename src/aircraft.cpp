#include "aircraft.h"

namespace kamotsu {
Aircraft::Aircraft(const std::string& path) {
    std::ifstream file(path, std::ifstream::in);

    try {
        this->document = json::parse(file);
        file.close();
    } catch (json::parse_error& ex) {
        std::cerr << "Could not parse JSON file. Error at byte " << ex.byte << std::endl;
    }
}

void Aircraft::save(const std::string& path) {
    std::fstream file(path, std::fstream::out);
    file << document;
    file.close();
}

std::string Aircraft::getRegistration() {
    return document["registration"].get<std::string>();
}

void Aircraft::setRegistration(const std::string& registration) {
    document["registration"] = registration;
}

std::string Aircraft::getSerialNumber() {
    return document["serialNumber"].get<std::string>();
}

void Aircraft::setSerialNumber(const std::string& serialNumber) {
    document["serialNumber"] = serialNumber;
}

std::string Aircraft::getLineNumber() {
    return document["lineNumber"].get<std::string>();
}

void Aircraft::setLineNumber(const std::string& lineNumber) {
    document["lineNumber"] = lineNumber;
}

TypeCode Aircraft::getTypeCode() {
    TypeCode tc;

    try {
        tc.setIcao(document["typeCode"]["icao"].get<std::string>());
        tc.setManufacturer(document["typeCode"]["manufacturer"].get<std::string>());
        tc.setModel(document["typeCode"]["model"].get<std::string>());
        tc.setTags(document["typeCode"]["tags"].get<std::vector<std::string>>());
    } catch (json::parse_error& ex) {
        std::cerr << "Could not parse JSON file. Error at byte " << ex.byte << std::endl;
    }

    return tc;
}

void Aircraft::setTypeCode(TypeCode typeCode) {
    document["typeCode"]["icao"] = typeCode.getIcao();
    document["typeCode"]["manufacturer"] = typeCode.getManufacturer();
    document["typeCode"]["model"] = typeCode.getModel();
    document["typeCode"]["tags"] = typeCode.getTags();
}

Airline Aircraft::getAirline() {
    Airline al;

    try {
        al.setIata(document["airline"]["iata"].get<std::string>());
        al.setIcao(document["airline"]["icao"].get<std::string>());
        al.setName(document["airline"]["name"].get<std::string>());
        al.setCallsign(document["airline"]["callsign"].get<std::string>());
        al.setTags(document["airline"]["tags"].get<std::vector<std::string>>());
    } catch (json::parse_error& ex) {
        std::cerr << "Could not parse JSON file. Error at byte " << ex.byte << std::endl;
    }

    return al;
}

void Aircraft::setAirline(Airline airline) {
    document["airline"]["iata"] = airline.getIata();
    document["airline"]["icao"] = airline.getIcao();
    document["airline"]["name"] = airline.getName();
    document["airline"]["callsign"] = airline.getCallsign();
    document["airline"]["tags"] = airline.getTags();
}

}