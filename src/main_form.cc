#include "main_form.hh"

#include <QFile>
#include <QJsonDocument>

#include "input_form.hh"

MainForm::MainForm(QWidget *parent): QWidget{parent} {
    QGridLayout *layout = new QGridLayout(this);
    setLayout(layout);

    QPushButton *enterDataButton = new QPushButton("Ввести данные", this);
    layout->addWidget(enterDataButton, 1, 1, 1, 2);

    resultLabel = new QLabel(this);
    layout->addWidget(resultLabel, 2, 1, 2, 2);

    connect(enterDataButton, &QPushButton::clicked, [this]() {
        onEnterDataOpen();
    });

    data.read();
    if (data.years > 0 && data.hours > 0) {
        onSubmit(data.years, data.hours);
    }
}

void MainForm::onEnterDataOpen() {
    data.read();
    (new InputForm(this, data))->show();
}

void MainForm::onSubmit(int years, int hours) {
    float tFloatHours = years * 365.25 * hours;
    long tHours = (long)tFloatHours;
    long tDays = (long)(tFloatHours / 24);

    float pointerSpeedKmh = 0.1143;
    float clicksPerH = 592;
    float keystrokesPerH = 1862;

    long pointerKm = (long)(tFloatHours * pointerSpeedKmh);
    long clicks = (long)(tFloatHours * clicksPerH);
    long keystrokes = (long)(tFloatHours * keystrokesPerH);

    resultLabel->setText(QString().append("Данные:\n")
        .append(QString("Лет за компьютером: %1\n").arg(years))
        .append(QString("Ср. часов в день: %1\n\n").arg(hours))
        .append("Результат:\n")
        .append(QString("Часов за компьютером: %1 ч.\n").arg(tHours))
        .append(QString("Суток за компьютером: %1 сут.\n").arg(tDays))
        .append(QString("Пройдено курсором: %1 км\n").arg(pointerKm))
        .append(QString("Всего кликов мыши: %1 кликов\n").arg(clicks))
        .append(QString("Всего нажатий клавиатуры: %1 нажатий\n").arg(keystrokes)));

    data.years = years;
    data.hours = hours;
    data.write();
}