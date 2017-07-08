#include "jsonconnection.h"

QString JSONConnection::path;

JSONConnection::JSONConnection()
{
    //Path should be given once not on every constructor call
    JSONConnection::path = QDir::currentPath() +QString("/json.json");    

}

void JSONConnection::ReadAll(QVector<Floor> &_floors, QWidget *_window)
{
    //info if there is file we are trying to read
    QFileInfo fileInfo(JSONConnection::path);
    QString infoTxt = (!fileInfo.exists()) ? (JSONConnection::path+" can not be read") : ("JSON read successfuly");
    qDebug() << infoTxt;

    //read file
    QFile jsonFile(JSONConnection::path);
    jsonFile.open(QFile::ReadOnly);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonFile.readAll());
    QJsonObject jsonObj = jsonDoc.object();
    //for each floor
    QJsonArray jsonFloors = jsonObj.value("building").toArray();
    foreach (QJsonValue jsonFloor, jsonFloors) {
        Floor floor;
        floor.nameID = jsonFloor.toObject().value("nameID").toString();
        //for each room
        QJsonArray jsonRooms = jsonFloor.toObject().value("rooms").toArray();
        foreach (QJsonValue jsonRoom, jsonRooms) {
            Room room(_window);
            room.nameID = jsonRoom.toObject().value("nameID").toString();
            //for each point
            QJsonArray jsonPoints = jsonRoom.toObject().value("points").toArray();
            foreach (QJsonValue jsonPoint, jsonPoints) {
                room.AddPoint(QPoint(jsonPoint.toObject().value("x").toInt(), jsonPoint.toObject().value("y").toInt()));
            }
            floor.AddRoom(room, _window);
        }
        _floors.push_back(floor);
    }

}

void JSONConnection::WriteAll(Floor &_floor)
{

}
