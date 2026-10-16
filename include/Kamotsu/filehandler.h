#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

namespace kamotsu {
using nlohmann::json;

class FileHandler
{
public:
    static void open(const std::string& path, json document);
    static void save(const std::string& path, json document);
};
}

#endif // FILEHANDLER_H
