#include "filterapplier.h"
#include "qimage.h"

using namespace Core;

FilterApplier::FilterApplier(IFilter * filter)
{
    filter_ = filter;
}

FilterApplier::FilterApplier()
{
    filter_ = nullptr;
}

void FilterApplier::setFilter(IFilter * filter)
{
    filter_ = filter;
}

QImage* FilterApplier::processImage(FilterSettings * filterSettings) const
{
    if (filter_) {
        return filter_->applyFilter(filterSettings);
    } else {
        throw std::exception("No filter given.");
    }
}
