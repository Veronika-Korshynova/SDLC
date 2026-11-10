#ifndef CALCULATOR_INPUT_FORM_HH
#define CALCULATOR_INPUT_FORM_HH

#include <QDialog>
#include <QJsonObject>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


struct Data;
class MainForm;

class InputForm : public QDialog {
    Q_OBJECT
public:
    InputForm(MainForm* parent, Data data);
};

#endif //CALCULATOR_INPUT_FORM_HH
