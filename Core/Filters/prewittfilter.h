#ifndef PREWITT_H
#define PREWITT_H

#include "Core/ifilter.h"
#include "Core/filtersettings.h"

namespace Core
{
    namespace Filters
    {
        class PrewittFilter : public Core::IFilter
        {
        public:
            ~PrewittFilter() override = default;
            QImage* applyFilter(Core::FilterSettings* filterSettings) override;
        private:
            QVector<uchar> toGrayscaleBytes(const QImage& image);
        };
    }
}

#endif // PREWITT_H
