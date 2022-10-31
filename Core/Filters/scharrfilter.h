#ifndef SCHARR_H
#define SCHARR_H

#include "Core/ifilter.h"
#include "Core/filtersettings.h"

namespace Core
{
    namespace Filters
    {
        class ScharrFilter : public Core::IFilter
        {
        public:
            ~ScharrFilter() override = default;
            QImage* applyFilter(Core::FilterSettings* filterSettings) override;
        private:
            QVector<uchar> toGrayscaleBytes(const QImage& image);
        };
    }
}


#endif // SCHARR_H
