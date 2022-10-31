#ifndef SOBELFILTER_H
#define SOBELFILTER_H

#include "Core/ifilter.h"
#include "Core/filtersettings.h"

namespace Core
{
    namespace Filters
    {
        class SobelFilter : public Core::IFilter
        {
        public:
            ~SobelFilter() override = default;
            QImage* applyFilter(Core::FilterSettings* filterSettings) override;
        private:
            QVector<uchar> toGrayscaleBytes(const QImage& image);
        };
    }
}

#endif // SOBELFILTER_H
