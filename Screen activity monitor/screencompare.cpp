#include "ScreenCompare.h"

ScreenCompare::ScreenCompare() {}

double ScreenCompare::compareImages(const QPixmap &screenshot1, const QPixmap &screenshot2) {
    QImage img1 = screenshot1.toImage();
    QImage img2 = screenshot2.toImage();

    if (img1.size() != img2.size()) {
        qWarning("Images have different sizes");
        return 0.0;
    }

    int width = img1.width();
    int height = img1.height();

    int similarPixels = 0;
    QRgb pixel1;
    QRgb pixel2;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            pixel1 = img1.pixel(x, y);
            pixel2 = img2.pixel(x, y);

            if (pixel1 == pixel2) {
                similarPixels++;
            }
        }
    }

    double similarityPercentage = (static_cast<double>(similarPixels) / (width * height)) * 100.0;
    return similarityPercentage;
}
