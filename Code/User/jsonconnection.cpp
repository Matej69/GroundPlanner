#include "jsonconnection.h"

QString JSONConnection::path;

JSONConnection::JSONConnection()
{
    //Path should be given once not on every constructor call
    JSONConnection::path = QDir::currentPath() +QString("/json.json");
    qDebug() << path;
}

void JSONConnection::ReadAll(QVector<Floor> &_floors, QWidget *_window)
{
    //info if there is file we are trying to read
    QFileInfo fileInfo(JSONConnection::path);
    QString infoTxt = (!fileInfo.exists()) ? (JSONConnection::path+" can not be read") : ("JSON read successfuly");
    qDebug() << infoTxt;
    if(!fileInfo.exists())
        return;

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
        int i = 0;
        foreach (QJsonValue jsonRoom, jsonRooms) {
            Room room(_window);
            //room.nameID = jsonRoom.toObject().value("nameID").toString();
            room.SetName(jsonRoom.toObject().value("nameID").toString());
            //for each point
            QJsonArray jsonPoints = jsonRoom.toObject().value("points").toArray();
            foreach (QJsonValue jsonPoint, jsonPoints) {
                room.AddPoint(QPoint(jsonPoint.toObject().value("x").toInt(), jsonPoint.toObject().value("y").toInt()));
            }
            floor.AddRoom(room, _window, false);
        }        
        //at first, all textboxes will be invisible and later only active room ones will be visible
        floor.SetAllTextBoxVisiblity(false);
        _floors.push_back(floor);        
    }

}

void JSONConnection::WriteAll(QVector<Floor> &_floors)
{
    //info if there is file we are trying to read
    QFileInfo fileInfo(JSONConnection::path);
    QString infoTxt = (!fileInfo.exists()) ? (JSONConnection::path+" can not be read") : ("JSON read successfuly");
    qDebug() << infoTxt;
    if(!fileInfo.exists())
        return;

    //read file
    QFile jsonFile(JSONConnection::path);
    jsonFile.open(QFile::WriteOnly);

    //call to get const * char from string
    auto getCharP = [](string& _str) -> const char*{
        return _str.c_str();
    };
    //call to get string from QString
    auto getStr = [](QString& _str) -> string{
        return _str.toUtf8().constData();
    };

    jsonFile.write("{\"building\": [");
    for (int i = 0; i < _floors.length(); ++i) {
        Floor &floor = _floors[i];
        jsonFile.write("\n\t {");
        jsonFile.write(getCharP(string("\n\t\t \"nameID\"") + ":\""+ getStr(floor.nameID)+"\", "));

        jsonFile.write("\n\t\t \"rooms\":[");
         for (int i = 0; i < floor.rooms.length(); ++i) {
             Room& room = floor.rooms[i];
             //jsonFile.write(getCharP(string("\n\t\t\t {\"nameID\":\"")+ getStr(room.nameID)+ "\"," ));
             jsonFile.write(getCharP(string("\n\t\t\t {\"nameID\":\"")+ getStr(room.GetName())+ "\"," ));

             jsonFile.write("\n\t\t\t \"points\": [");
             for (int i = 0; i < room.points.length(); ++i) {
                 QPoint& point = room.points[i];
                 string str = (i == room.points.length() - 1) ?
                             (string("\n\t\t\t\t {\"x\":") + to_string(point.x())+ "," + "\"y\":" + to_string(point.y()) + "}") :
                             (string("\n\t\t\t\t {\"x\":") + to_string(point.x())+ "," + "\"y\":" + to_string(point.y()) + "},");
                 jsonFile.write(getCharP(str));
             }
             jsonFile.write("\n\t\t\t ]");


             string str = (i == floor.rooms.length() - 1) ? "\n\t\t\t }" : "\n\t\t\t },";       //room end
             jsonFile.write(str.c_str());
        }
        jsonFile.write("\n\t\t ]");                                                         //room array end

        string str = (i == _floors.length() - 1) ? "\n\t }" : "\n\t }," ;                   //floor end
        jsonFile.write(str.c_str());
    }
    jsonFile.write("\n]}");
}
