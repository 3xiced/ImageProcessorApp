#ifndef CONTRASTFILTER_H
#define CONTRASTFILTER_H
#include "Core/ifilter.h"
#include "Core/filtersettings.h"

namespace Core
{
    namespace Filters
    {
        class ContrastFilter : public Core::IFilter
        {
        public:
            ~ContrastFilter() override = default;
            QImage* applyFilter(Core::FilterSettings * filterSettings) override;
        };
    }
}
#endif // CONTRASTFILTER_H
