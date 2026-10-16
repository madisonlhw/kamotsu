#include <Kamotsu/airline.h>

namespace kamotsu {
Airline::Airline(const std::string& path) {
    FileHandler::open(path, document);
}

void Airline::save(const std::string& path) {
    FileHandler::save(path, document);
}

std::string Airline::getIata() {
    return document["iata"].get<std::string>();
}

void Airline::setIata(const std::string& iata) {
    document["iata"] = iata;
}

std::string Airline::getIcao() {
    return document["icao"].get<std::string>();
}

void Airline::setIcao(const std::string& icao) {
    document["icao"] = icao;
}

std::string Airline::getName() {
    return document["name"].get<std::string>();
}

void Airline::setName(const std::string& name) {
    document["name"] = name;
}

std::string Airline::getCallsign() {
    return document["callsign"].get<std::string>();
}

void Airline::setCallsign(const std::string& callsign) {
    document["callsign"] = callsign;
}

std::vector<std::string> Airline::getTags() {
    return document["tags"].get<std::vector<std::string>>();
}

void Airline::setTags(const std::vector<std::string>& tags) {
    document["tags"] = tags;
}

}