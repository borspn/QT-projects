#include "UI.h"

UI::UI(QWidget *parent) : QWidget(parent) {
    startButton = new QPushButton("Start", this);
    stopButton = new QPushButton("Stop", this);
    similarityLabel = new QLabel("Similarity: N/A", this);
    runningIndicator = new QLabel("Program is not running", this);
    runningIndicator->setStyleSheet("color: red;");
    imageLabel = new QLabel(this);
    imageLabel->setFixedSize(700, 500);
    timerLabel = new QLabel("Time until next screenshot: N/A seconds", this);

    gridLayout = new QGridLayout(this);
    setFixedSize(800, 600);
    gridLayout->addWidget(startButton, 0, 0, 1, 1, Qt::AlignLeft);
    gridLayout->addWidget(stopButton, 0, 1, 1, 1, Qt::AlignRight);
    gridLayout->addWidget(similarityLabel, 1, 0, 1, 2, Qt::AlignCenter);
    gridLayout->addWidget(imageLabel, 2, 0, 1, 2, Qt::AlignCenter);
    gridLayout->addWidget(runningIndicator, 3, 0, 1, 2, Qt::AlignCenter);
    gridLayout->addWidget(timerLabel, 4, 0, 1, 2, Qt::AlignCenter);
}

void UI::updateRunningIndicator(bool running) {
    if (running) {
        runningIndicator->setText(QString("Program is running"));
        runningIndicator->setStyleSheet("color: green;");
    } else {
        runningIndicator->setText(QString("Program is not running"));
        runningIndicator->setStyleSheet("color: red;");
    }
}
