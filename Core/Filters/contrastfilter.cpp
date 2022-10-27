#include "contrastfilter.h"

QImage * Core::Filters::ContrastFilter::applyFilter(Core::FilterSettings * filterSettings)
{
    QImage * img = filterSettings->image;
    double contrastLevel = filterSettings->strenght;
    for (int ii = 0; ii < (*filterSettings->image).height(); ii++) {
        QRgb *pixel = reinterpret_cast<QRgb*>((*img).scanLine(ii));
        QRgb *end = pixel + (*img).width();
        for (; pixel != end; pixel++) {
            int r = qRed(*pixel);
            int g = qGreen(*pixel);
            int b = qBlue(*pixel);

            b = static_cast<int>(
                ((b / 255.0 - 0.5) * contrastLevel + 0.5) * 255.0);
            g = static_cast<int>(
                ((g / 255.0 - 0.5) * contrastLevel + 0.5) * 255.0);
            r = static_cast<int>(
                ((r / 255.0 - 0.5) * contrastLevel + 0.5) * 255.0);

            b = b > 255 ? 255 : b;
            b = b < 0 ? 0 : b;

            g = g > 255 ? 255 : g;
            g = g < 0 ? 0 : g;

            r = r > 255 ? 255 : r;
            r = r < 0 ? 0 : r;

            *pixel = qRgb(r, g, b);
        }
    }
    return img;
}
