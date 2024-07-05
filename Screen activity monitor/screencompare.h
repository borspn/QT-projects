#ifndef SCREENCOMPARE_H
#define SCREENCOMPARE_H

#include <QtWidgets>

class ScreenCompare : public QObject {
    Q_OBJECT

public:
    ScreenCompare();
    double compareImages(const QPixmap &screenshot1, const QPixmap &screenshot2);
};

#endif // SCREENCOMPARE_H
