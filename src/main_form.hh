#ifndef CALCULATOR_MAIN_FORM_HH
#define CALCULATOR_MAIN_FORM_HH

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QJsonObject>
#include <QLabel>

#include "data.hh"

class MainForm : public QWidget {
    Q_OBJECT

    QLabel* resultLabel;
    Data data{};

public:
    explicit MainForm(QWidget* parent);

    void onEnterDataOpen();

    void onSubmit(int years, int hours);
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow() {
        setWindowTitle("Калькулятор Жизни");
        setMinimumSize(400, 400);
        setBaseSize(400, 600);

        setCentralWidget(new MainForm(this));
    }

private:
};

#endif //CALCULATOR_MAIN_FORM_HH
