#include "input_form.hh"

#include "data.hh"
#include "main_form.hh"

InputForm::InputForm(MainForm *parent, Data data) {
    setWindowTitle("Ввод данных");
    setFixedSize(400, 200);

    QGridLayout *layout = new QGridLayout(this);
    setLayout(layout);

    QLabel *yearsLabel = new QLabel("Количество лет", this);
    layout->addWidget(yearsLabel, 1, 1, 1, 2);

    QLineEdit *yearsInput = new QLineEdit(this);
    layout->addWidget(yearsInput, 2, 1, 1, 2);


    QLabel *dayHoursLabel = new QLabel("Количество часов в день за компьютером", this);
    layout->addWidget(dayHoursLabel, 3, 1, 1, 2);

    QLineEdit *dayHoursInput = new QLineEdit(this);
    layout->addWidget(dayHoursInput, 4, 1, 1, 2);

    QLabel *message = new QLabel(this);
    layout->addWidget(message, 5, 1, 1, 2);

    yearsInput->setText(data.years > 0 ? QString::number(data.years) : "");
    dayHoursInput->setText(data.hours > 0 ? QString::number(data.hours) : "");

    QPushButton *submitButton = new QPushButton("Рассчитать", this);
    layout->addWidget(submitButton, 6, 1, 1, 2);

    connect(submitButton, &QPushButton::clicked, [dayHoursInput, yearsInput, message, parent, this]() {
        QString yearString = yearsInput->text();
        QString hoursString = dayHoursInput->text();

        bool ok = false;
        int years = yearString.toInt(&ok);
        if (yearString.isEmpty() || !ok || years <= 0 || years > 100) {
            message->setText("Неверное количество лет. Значение должно быть больше 0 и меньше 100.");
            return;
        }

        int hours = hoursString.toInt(&ok);
        if (hoursString.isEmpty() || !ok || hours <= 0 || hours > 24) {
            message->setText("Неверное количество лет. Значение должно быть больше 0 и меньше 100.");
            return;
        }

        parent->onSubmit(years, hours);
        close();
    });
}
