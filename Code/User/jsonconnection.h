#ifndef JSONCONNECTION_H
#define JSONCONNECTION_H

#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QPoint>

#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "User/floor.h"


class JSONConnection
{
public:
    JSONConnection();
    static QString path;

    void ReadAll(QVector<Floor>& _floors, QWidget *_window);
    void WriteAll(QVector<Floor> &_floors);

};

#endif // JSONCONNECTION_H
