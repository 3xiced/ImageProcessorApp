#include "scharrfilter.h"

#include <QtMath>

QImage* Core::Filters::ScharrFilter::applyFilter(Core::FilterSettings* filterSettings)
{
    auto img = filterSettings->image;

    const int xMatrix[3][3]{
        { -1, 0, +1 },
        { -1, 0, +1},
        { -1, 0, +1 }
    };

    const int yMatrix[3][3]{
        {-1, -1, -1},
        { 0,  0,  0},
        {+1, +1, +1}
    };


    auto grayscaleData = toGrayscaleBytes(*img);
    int m = 0;
    auto grayscaleWidth = (*img).width() + 2;
    auto grayscaleHeigth = (*img).height() + 2;

    for (auto y = 1; y < (grayscaleHeigth - 1); ++y)
    {
        auto scanline = (*img).scanLine(y - 1);
        for (auto x = 1; x < (grayscaleWidth - 1); ++x)
        {
            double gy = 0;
            double gx = 0;
            // применяем оператор
            for (auto matX = 0; matX < 3; ++matX)
            {
                for (auto matY = 0; matY < 3; matY++)
                {
                    auto currentX = x + matX - 1;
                    auto currentY = y + matY - 1;
                    auto currentGrayVal =
                        grayscaleData[(currentY * grayscaleWidth) + currentX];
                    gy += currentGrayVal * xMatrix[matX][matY];
                    gx += currentGrayVal * yMatrix[matX][matY];
                }
            }

            auto res = static_cast<int>(qSqrt(gx * gx + gy * gy));
            m = qMax(res, m);

            memcpy(scanline, &res, sizeof(res));
            scanline += sizeof(res);
        }
    }

    for (auto y = 1; y < (grayscaleHeigth - 1); ++y) {
        QRgb* pixel = reinterpret_cast<QRgb*>((*img).scanLine(y - 1));

        for (auto x = 1; x < (grayscaleWidth - 1); ++x)
        {
            int val;
            memcpy(&val, pixel, sizeof(val));
            int res = static_cast<int>(val) / (m / 255);

            *pixel = qRgb(res, res, res);
            ++pixel;
        }
    }
    return img;
}

QVector<uchar> Core::Filters::ScharrFilter::toGrayscaleBytes(const QImage& image)
{
    auto grayscaleWidth = image.width() + 2;
    auto grayscaleHeigth = image.height() + 2;
    QVector<uchar> result(grayscaleWidth * grayscaleHeigth, 0x00);

    auto index = grayscaleWidth;
    for (int ii = 0; ii < image.height(); ii++) {
        const QRgb* pixel = reinterpret_cast<const QRgb*>(image.scanLine(ii));
        const QRgb* end = pixel + image.width();
        ++index;
        for (; pixel != end; pixel++) {
            int gray = (qRed(*pixel) + qGreen(*pixel) + qBlue(*pixel)) / 0x03;
            result[index++] = static_cast<uchar>(gray);
        }
        ++index;
    }

    // с второй строки
    auto grayFromOffset = grayscaleWidth;
    // на первую
    auto grayToOffset = 0;

    // c предпоследней строки
    auto grayFromOffset2 = grayscaleWidth * (grayscaleHeigth - 2);
    // на последнюю
    auto grayToOffset2 = grayscaleWidth * (grayscaleHeigth - 1);

    for (auto x = 0; x < grayscaleWidth; x++)
    {
        result[grayToOffset++] = result[grayFromOffset++];
        result[grayToOffset2++] = result[grayFromOffset2++];
    }

    // со второго ряда
    grayFromOffset = 1;
    // на первый
    grayToOffset = 0;

    // c пердпоследнего
    grayFromOffset2 = grayscaleWidth - 2;
    // на последний
    grayToOffset2 = grayscaleWidth - 1;

    for (auto y = 0; y < grayscaleHeigth; ++y)
    {
        result[grayToOffset] = result[grayFromOffset];
        result[grayToOffset2] = result[grayFromOffset2];
        grayFromOffset += grayscaleWidth;
        grayFromOffset2 += grayscaleWidth;
        grayToOffset += grayscaleWidth;
        grayToOffset2 += grayscaleWidth;
    }

    return result;
}
