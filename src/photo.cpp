#include <Kamotsu/photo.h>

namespace kamotsu {
Photo::Photo(const std::string& path) {
    Exiv2::XmpParser::initialize();

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

}