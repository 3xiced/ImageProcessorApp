#ifndef FILTERAPPLIER_H
#define FILTERAPPLIER_H

#include "ifilter.h"
#include "filtersettings.h"

namespace Core
{
    class FilterApplier
    {
    public:
        explicit FilterApplier(IFilter * filter);
        explicit FilterApplier();
        void setFilter(IFilter * filter);
        QImage* processImage(Core::FilterSettings * filterSettings) const;
    private:
        IFilter* filter_;
    };
}
#endif // FILTERAPPLIER_H
