#ifndef IFILTER_H
#define IFILTER_H
#include "qimage.h"
#include "filtersettings.h"

namespace Core
{
    class IFilter
    {
    public:
        virtual ~IFilter() = default;
        virtual QImage* applyFilter(Core::FilterSettings * filterSettings) = 0;
    };
}
#endif // IFILTER_H
