#ifndef ARKECHOSETTINGSMODEL_H
#define ARKECHOSETTINGSMODEL_H

#include <QObject>

class ArkEchoSettingsModel : public QObject
{
    Q_OBJECT

    // Tempor�re Kopie der Music Directories List
    QStringList directoriesList_;

public:
    ArkEchoSettingsModel(QObject *parent = 0);
    ~ArkEchoSettingsModel();

    QStringList& getDirectoriesList();
    void newDirectory();
    void editDirectory(int index);
    void deleteDirectory(int index);
};

#endif // ARKECHOSETTINGSMODEL_H
