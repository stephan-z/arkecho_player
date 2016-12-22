#include <QJsonObject>
#include <QJsonDocument>

#include "MessageHandler.h"

const QString JSON_TYP = "Typ";
const QString JSON_MESSAGE = "Message";

QString& MessageHandler::createMessage(int typ, QString & message)
{
    QJsonObject obj;
    obj[JSON_TYP] = typ;
    obj[JSON_MESSAGE] = message;

    QJsonDocument doc;
    doc.setObject(obj);

    message = doc.toJson(QJsonDocument::Compact);

    return message;
}

int MessageHandler::handleReceivedMessage(QString &message)
{
    QJsonDocument doc;
    doc = doc.fromJson(message.toUtf8());

    QJsonObject obj = doc.object();

    int type = obj[JSON_TYP].toInt();
    message = obj[JSON_MESSAGE].toString();

    return type;
}
