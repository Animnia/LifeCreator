#include <GameFile.h>
#include <QFileDialog>
#include <QMessageBox>


bool DEBUG_WARNING_SIGN = false;

QJsonObject infoToJson(Information info)
{
    QJsonObject obj;

    obj["zZ_A_T_T_N_P_M_I_A"] = "!%!^$$^*!^!$^#";
    obj["size"] = info.getSize();
    obj["title"] = info.getMainTitle();
    obj["color"] = info.getMainColor().name();
    obj["rangeNumber"] = info.getRangeNumber();
    obj["range"] = toJsonArrayPair(info.getRange());
    obj["fate"] = toJsonHash(info.getFate());
    obj["mapData"] = toJsonArray(info.getMapData());

    return obj;
}


QJsonObject blockToJson(cellData block)// one cell
{
    QJsonObject obj;

    obj["row"] = block.row;
    obj["col"] = block.col;
    obj["color"] = block.color.name();
    return obj;
}


QJsonArray toJsonArray(std::vector<cellData> mapData)//all cells
{
    QJsonArray array;

    for (const auto& block : mapData) {
        array.append(blockToJson(block));
    }
    return array;
}


QJsonArray toJsonArrayPair(std::vector<std::pair<int,int>> range)//range
{
    QJsonArray array;

    for (const auto& pair : range) {
        QJsonArray pairArray;
        pairArray.append(pair.first);
        pairArray.append(pair.second);
        array.append(pairArray);
    }
    return array;
}


QJsonObject toJsonHash(QHash<int,int> fate)//fate
{
    QJsonObject obj;

    for (auto it = fate.constBegin(); it != fate.constEnd(); ++it) {
        obj[QString::number(it.key())] = it.value();
    }
    return obj;
}


void saveToFile(const Information &info) {

    QJsonObject jsonObj = infoToJson(info);
    QJsonDocument jsonDoc(jsonObj);
    QString fileName = QFileDialog::getSaveFileName(nullptr, "保存文件", "", "JSON 文件 (*.json);;所有文件 (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    file.write(jsonDoc.toJson());
    file.close();
}


bool isJsonLegal(const QJsonObject &jsonObj)
{
    return jsonObj.contains("zZ_A_T_T_N_P_M_I_A") && jsonObj["zZ_A_T_T_N_P_M_I_A"] == "!%!^$$^*!^!$^#";
}


void loadJson(Information &info)
{
    DEBUG_WARNING_SIGN = false;

    QString fileName = QFileDialog::getOpenFileName(nullptr, "选择文件", "", "JSON 文件 (*.json);;所有文件 (*)");
    if (fileName.isEmpty()) {
        DEBUG_WARNING_SIGN = true;
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "错误", "无法打开文件进行读取");
        DEBUG_WARNING_SIGN = true;
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    if (!jsonDoc.isObject()) {
        QMessageBox::warning(nullptr, "错误", "JSON 文件格式错误");
        DEBUG_WARNING_SIGN = true;
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    if(!(jsonObj.contains("zZ_A_T_T_N_P_M_I_A") && jsonObj["zZ_A_T_T_N_P_M_I_A"] == "!%!^$$^*!^!$^#")){
        QMessageBox::warning(nullptr, "错误", "JSON 文件格式错误");
        DEBUG_WARNING_SIGN = true;
        return;
    }

    info = jsonToInfo(jsonObj);
}


Information jsonToInfo(const QJsonObject &obj)
{
    Information info;
    QColor color;
    std::vector<std::pair<int,int>> range;
    int rangeNumber;
    QHash<int,int> fate;

    QString colorName = obj["color"].toString();
    color.setRgb(
        QString(colorName.mid(1, 2)).toInt(nullptr, 16), // red
        QString(colorName.mid(3, 2)).toInt(nullptr, 16), // green
        QString(colorName.mid(5, 2)).toInt(nullptr, 16)  // blue
        );

    range = fromJsonArrayPair(obj["range"].toArray());
    rangeNumber = obj["rangeNumber"].toInt();
    fate = fromJsonHash(obj["fate"].toObject());

    info.setMainTitle(obj["title"].toString());
    info.setSize(obj["size"].toInt());
    info.setMainColor(color);
    info.setMainRule(range, rangeNumber, fate);
    info.cleanMapData();
    info.initMapData();
    info.setAllMapData(fromJsonArray(obj["mapData"].toArray()));

    return info;
}


QHash<int, int> fromJsonHash(const QJsonObject& obj)//fate
{
    QHash<int, int> hash;

    for (auto it = obj.constBegin(); it != obj.constEnd(); ++it) {
        hash[it.key().toInt()] = it.value().toInt();
    }
    return hash;
}


std::vector<std::pair<int, int>> fromJsonArrayPair(const QJsonArray& array)//range
{
    std::vector<std::pair<int, int>> vector;

    for (const auto& value : array) {
        QJsonArray pairArray = value.toArray();
        if (pairArray.size() == 2) {
            int first = pairArray[0].toInt();
            int second = pairArray[1].toInt();
            vector.emplace_back(first, second);
        }
    }
    return vector;
}


cellData fromJsonBlock(const QJsonObject& obj)//one cell
{
    cellData block;
    block.row = obj["row"].toInt();
    block.col = obj["col"].toInt();

    QString colorName = obj["color"].toString();
    block.color.setRgb(
        QString(colorName.mid(1, 2)).toInt(nullptr, 16), // red
        QString(colorName.mid(3, 2)).toInt(nullptr, 16), // green
        QString(colorName.mid(5, 2)).toInt(nullptr, 16)  // blue
        );
    return block;
}


std::vector<cellData> fromJsonArray(const QJsonArray& array)//cells
{
    std::vector<cellData> vector;

    for (const auto& value : array) {
        QJsonObject obj = value.toObject();
        vector.push_back(fromJsonBlock(obj));
    }
    return vector;
}

