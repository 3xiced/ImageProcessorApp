#ifndef FILTERSETTINGS_H
#define FILTERSETTINGS_H
#include "qimage.h"

namespace Core{
    class FilterSettings
    {
    public:
        ~FilterSettings() = default;
        QImage * image;
        int strenght;
    };
}
#endif // FILTERSETTINGS_H
