#ifndef UI_H
#define UI_H

#include <QtWidgets>

class UI : public QWidget {
    Q_OBJECT

public:
    UI(QWidget *parent = nullptr);
    QPushButton *startButton;
    QPushButton *stopButton;
    QLabel *similarityLabel;
    QLabel *runningIndicator;
    QLabel *imageLabel;
    QLabel *timerLabel;
    QGridLayout *gridLayout;

    void updateRunningIndicator(bool running);
};

#endif // UI_H
