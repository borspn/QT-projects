#include <QtWidgets>
#include "UI.h"
#include "ScreenCapture.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    UI ui;
    ScreenCapture screenCapture(&ui);
    ui.show();

    return a.exec();
}
