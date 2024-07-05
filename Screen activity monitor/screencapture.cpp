#include "ScreenCapture.h"

ScreenCapture::ScreenCapture(UI *ui) : ui(ui) {
    captureTimer = new QTimer(this);
    connect(captureTimer, &QTimer::timeout, this, &ScreenCapture::captureScreen);
    compareThread = new QThread(this);

    timeTrackerTimer = new QTimer(this);
    screenCompare = new ScreenCompare;

    connect(ui->startButton, &QPushButton::clicked, this, &ScreenCapture::startCapture);
    connect(ui->stopButton, &QPushButton::clicked, this, &ScreenCapture::stopCapture);
    connect(this, &ScreenCapture::updateImage, this, &ScreenCapture::displayScreenshot, Qt::QueuedConnection);
    connect(timeTrackerTimer, &QTimer::timeout, this, &ScreenCapture::updateTimer);

    moveToThread(compareThread);
    compareThread->start();

    // Take a screenshot of the initial screen after launching the program
    previousScreenshot = QGuiApplication::primaryScreen()->grabWindow(0);
    // Rescale screenshot of the initial screen to fit in our program window and display it
    ui->imageLabel->setPixmap(previousScreenshot.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

ScreenCapture::~ScreenCapture() {
    compareThread->quit();
    compareThread->wait();
}

void ScreenCapture::startCapture() {
    captureTimer->start(60000);
    timeTrackerTimer->start(1000);
    ui->updateRunningIndicator(true);
}

void ScreenCapture::stopCapture() {
    captureTimer->stop();
    ui->updateRunningIndicator(false);
}

void ScreenCapture::captureScreen() {
    QPixmap screenshot = QGuiApplication::primaryScreen()->grabWindow(0);
    emit updateImage(screenshot);

    double similarityPercentage = screenCompare->compareImages(screenshot, previousScreenshot);
    updateUI(similarityPercentage);
    previousScreenshot = screenshot;
}

void ScreenCapture::updateUI(double similarityPercentage) {
    ui->similarityLabel->setText(QString("Similarity: %1%").arg(similarityPercentage, 0, 'f', 2));
}

void ScreenCapture::displayScreenshot(const QPixmap &screenshot) {
    QPixmap scaledPixmap = screenshot.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->imageLabel->setPixmap(scaledPixmap);
}

void ScreenCapture::updateTimer() {
    int remainingSeconds = captureTimer->remainingTime() / 1000;
    ui->timerLabel->setText(QString("Time to next screenshot: %1 seconds").arg(remainingSeconds));
}
