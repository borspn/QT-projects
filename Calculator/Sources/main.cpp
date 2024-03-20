#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>


class Calc : public QWidget {
private:
    QPushButton *button;
    QVBoxLayout* layout;
    QLineEdit *value1;
    QLineEdit *value2;
    QLineEdit *operation;
    QLabel* result;
public:
    Calc(QWidget *parent = nullptr) : QWidget(parent) {
        layout = new QVBoxLayout(this);

        // Create a horizontal layout for value1 and value2
        QHBoxLayout* horizontalLayout = new QHBoxLayout();

        value1 = new QLineEdit(this);
        value1->setPlaceholderText("Enter first value");
        horizontalLayout->addWidget(value1);

        value2 = new QLineEdit(this);
        value2->setPlaceholderText("Enter second value");
        horizontalLayout->addWidget(value2);

        operation = new QLineEdit(this);
        operation->setPlaceholderText("Enter operation");
        horizontalLayout->addWidget(operation);

        layout->addLayout(horizontalLayout); // Add the horizontal layout to the vertical layout

        button = new QPushButton("Calculate", this);
        result = new QLabel();
        layout->addWidget(button);
        layout->addWidget(result);


        connect(button, &QPushButton::clicked, this, &Calc::calculate);
    }
private slots:
    void calculate() {
        // Read values from line edits
        QString text1 = value1->text();
        QString text2 = value2->text();
        QString op = operation->text();
        // Convert to integers
        bool ok1, ok2;
        int intValue1 = text1.toInt(&ok1);
        int intValue2 = text2.toInt(&ok2);
        int res = NULL;
        // Check if conversion was successful
        if (ok1 && ok2) {
            // Conversion successful, perform calculations
            if(op == "+"){
                res = intValue1 + intValue2;
            }else if(op == "-"){
                res = intValue1 - intValue2;
            }else if(op == "/"){
                res = intValue1 / intValue2;
            }else if(op == "*"){
                res = intValue1 * intValue2;
            }else{
                result->setText("Invalid operator");
                return;
            }
            result->setText("Result: " + QString::number(res));
        } else {
            // Conversion failed, display error message
            qDebug() << "Invalid input. Please enter valid integers.";
        }
    }
};


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Calc calc;
    calc.setWindowTitle("Calculator");
    calc.resize(500, 300);
    calc.show();

    return app.exec();
}
