#include <Kamotsu/airport.h>

namespace kamotsu {
Airport::Airport(const std::string& path) {
    std::ifstream file(path, std::ifstream::in);

    try {
        this->document = json::parse(file);
        file.close();
    } catch (json::parse_error& ex) {
        std::cerr << "Could not parse JSON file. Error at byte " << ex.byte << std::endl;
    }
}

void Airport::save(const std::string& path) {
    std::fstream file(path, std::fstream::out);
    file << document;
    file.close();
}

std::string Airport::getIata() {
    return document["iata"].get<std::string>();
}

void Airport::setIata(const std::string& iata) {
    document["iata"] = iata;
}

std::string Airport::getIcao() {
    return document["icao"].get<std::string>();
}

void Airport::setIcao(const std::string& icao) {
    document["icao"] = icao;
}

std::string Airport::getName() {
    return document["name"].get<std::string>();
}

void Airport::setName(const std::string& name) {
    document["name"] = name;
}

std::string Airport::getCity() {
    return document["city"].get<std::string>();
}

void Airport::setCity(const std::string& city) {
    document["city"] = city;
}

std::string Airport::getState() {
    return document["state"].get<std::string>();
}

void Airport::setState(const std::string& state) {
    document["state"] = state;
}

std::string Airport::getCountry() {
    return document["country"].get<std::string>();
}

void Airport::setCountry(const std::string& country) {
    document["country"] = country;
}

std::string Airport::getCountryCode() {
    return document["countryCode"].get<std::string>();
}

void Airport::setCountryCode(const std::string& countryCode) {
    document["countryCode"] = countryCode;
}

std::vector<std::string> Airport::getTags() {
    return document["tags"].get<std::vector<std::string>>();
}

void Airport::setTags(const std::vector<std::string>& tags) {
    document["tags"] = tags;
}

}