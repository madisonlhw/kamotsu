#include <Kamotsu/photo.h>

namespace kamotsu {
Photo::Photo(const std::string& path) {
    Exiv2::XmpParser::initialize();
    Exiv2::XmpProperties::registerNs("https://kamotsu.maddiekaze.dev/", "Kamotsu");

    try {
        image = Exiv2::ImageFactory::open(path);
        image->readMetadata();

        exifData = image->exifData();
        xmpData = image->xmpData();
    } catch (Exiv2::Error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

Photo::~Photo() {
    Exiv2::XmpParser::terminate();
}

void Photo::save(const std::string& path) {
    image->setExifData(exifData);
    image->setXmpData(xmpData);
    image->writeMetadata();
}

std::string Photo::getExifData(const std::string& property) {
    return exifData[property].toString();
}

void Photo::setExifData(const std::string& property, const std::string& value) {
    exifData[property] = value;
}

std::string Photo::getIptcData(const std::string& property) {
    return iptcData[property].toString();
}

void Photo::setIptcData(const std::string& property, const std::string& value) {
    iptcData[property] = value;
}

std::string Photo::getXmpData(const std::string& property) {
    return xmpData[property].toString();
}

void Photo::setXmpData(const std::string& property, const std::string& value) {
    xmpData[property] = value;
}

}