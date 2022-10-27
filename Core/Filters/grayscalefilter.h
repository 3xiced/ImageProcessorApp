#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "Core/ifilter.h"
#include "Core/filtersettings.h"

namespace Core
{
    namespace Filters
    {
        class GrayscaleFilter : public Core::IFilter
        {
        public:
            ~GrayscaleFilter() override = default;
            QImage* applyFilter(Core::FilterSettings * filterSettings) override;
        };
    }
}
#endif // GRAYSCALEFILTER_H
