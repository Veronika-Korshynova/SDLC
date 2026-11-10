#ifndef CALCULATOR_DATA_HH
#define CALCULATOR_DATA_HH

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>

struct Data {
    int years{};
    int hours{};

    Data() = default;
    Data(int years, int hours) : years{years}, hours{hours} {
    }

    void write() const;

    void read();
};


#endif //CALCULATOR_DATA_HH
