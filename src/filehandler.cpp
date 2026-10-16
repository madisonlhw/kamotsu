#include <Kamotsu/filehandler.h>

namespace kamotsu {
void FileHandler::open(const std::string& path, json document) {
    std::ifstream file(path, std::ifstream::in);

    try {
        document = json::parse(file);
        file.close();
    } catch (json::parse_error& ex) {
        std::cerr << "Could not parse JSON file. Error at byte " << ex.byte << std::endl;
    }
}

void FileHandler::save(const std::string& path, json document) {
    std::fstream file(path, std::fstream::out);
    file << document;
    file.close();
}
}