#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>

#include <exiv2/exiv2.hpp>

namespace kamotsu {
class Photo {
public:
    Photo(const std::string& path);
    ~Photo();

    std::string getXmpData(const std::string& property);
    void setXmpData(const std::string& property, const std::string& value);

private:
    Exiv2::Image::UniquePtr image;

    Exiv2::ExifData exifData;
    Exiv2::XmpData xmpData;
};
}

#endif // PHOTO_H
