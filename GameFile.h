#ifndef GAMEFILE_H
#define GAMEFILE_H

#include "GameLogic.h"
#include <QFile>
#include <QDir>
#include <QColor>
#include <QDebug>
#include <vector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//if true, can't load
extern bool DEBUG_WARNING_SIGN;

//data to json
QJsonObject infoToJson(Information info);
QJsonArray toJsonArray(std::vector<cellData> mapData);
QJsonArray toJsonArrayPair(std::vector<std::pair<int,int>> range);
QJsonObject toJsonHash(QHash<int,int> fate);
QJsonObject blockToJson(cellData block);

//json to data
Information jsonToInfo(const QJsonObject &obj);
QHash<int, int> fromJsonHash(const QJsonObject& obj);
std::vector<std::pair<int, int>> fromJsonArrayPair(const QJsonArray& array);
cellData fromJsonBlock(const QJsonObject& obj);
std::vector<cellData> fromJsonArray(const QJsonArray& array);

//load helper
void saveToFile(const Information &info);
bool isJsonLegal(const QJsonObject &jsonObj); //check password

void loadJson(Information &info);

#endif // GAMEFILE_H
