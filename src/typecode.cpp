#include <Kamotsu/typecode.h>

namespace kamotsu {
TypeCode::TypeCode(const std::string& path) {
    FileHandler::open(path, document);
}

void TypeCode::save(const std::string& path) {
    FileHandler::save(path, document);
}

std::string TypeCode::getIcao() {
    return document["icao"].get<std::string>();
}

void TypeCode::setIcao(const std::string& icao) {
    document["icao"] = icao;
}

std::string TypeCode::getManufacturer() {
    return document["manufacturer"].get<std::string>();
}

void TypeCode::setManufacturer(const std::string& manufacturer) {
    document["manufacturer"] = manufacturer;
}

std::string TypeCode::getModel() {
    return document["model"].get<std::string>();
}

void TypeCode::setModel(const std::string& model) {
    document["model"] = model;
}

std::vector<std::string> TypeCode::getTags() {
    return document["tags"].get<std::vector<std::string>>();
}

void TypeCode::setTags(const std::vector<std::string>& tags) {
    document["tags"] = tags;
}

}