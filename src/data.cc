#include "data.hh"

void Data::write() const {
    QJsonObject data{};
    data["years"] = years;
    data["hours"] = hours;

    QJsonDocument document{data};
    QByteArray json = document.toJson();
    QFile file{"data.json"};
    if (file.open(QIODevice::Truncate|QIODevice::WriteOnly)) {
        file.write(json);
    }
}

void Data::read() {
    QFile file{"data.json"};
    QJsonObject data{};
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray bytes = file.readAll();
        QJsonDocument document = QJsonDocument::fromJson(bytes);
        data = document.object();
    }
    years = data["years"].toInt();
    hours = data["hours"].toInt();
}
