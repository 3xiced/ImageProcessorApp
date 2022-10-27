#include "grayscalefilter.h"

QImage * Core::Filters::GrayscaleFilter::applyFilter(Core::FilterSettings * filterSettings)
{
    QImage * image = filterSettings->image;
    for (int ii = 0; ii < (*image).height(); ii++) {
        QRgb *pixel = reinterpret_cast<QRgb*>((*image).scanLine(ii));
        QRgb *end = pixel + (*image).width();

        for (; pixel != end; pixel++) {
            int gray = qGray(*pixel);
            *pixel = QColor(gray, gray, gray).rgb();
        }
    }
    return image;
}
