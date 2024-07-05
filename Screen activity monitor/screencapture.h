#ifndef SCREENCAPTURE_H
#define SCREENCAPTURE_H

#include <QtWidgets>
#include "UI.h"
#include "ScreenCompare.h"

class ScreenCapture : public QObject {
    Q_OBJECT

public:
    ScreenCapture(UI *ui);
    ~ScreenCapture();

public slots:
    void startCapture();
    void stopCapture();
    void captureScreen();

signals:
    void updateImage(const QPixmap &screenshot);

private:
    UI *ui;
    QTimer *captureTimer;
    QTimer *timeTrackerTimer;
    QThread *compareThread;
    QPixmap previousScreenshot;
    ScreenCompare *screenCompare;

    void updateUI(double similarityPercentage);
    void displayScreenshot(const QPixmap &screenshot);
    void updateTimer();
};

#endif // SCREENCAPTURE_H
