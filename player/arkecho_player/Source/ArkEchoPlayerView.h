#ifndef ARKECHOPLAYERVIEW_H
#define ARKECHOPLAYERVIEW_H

#include <QMainWindow>

#include "ui_ArkEchoPlayerView.h"

class ArkEchoPlayerModel;
struct SongInfoStruct;
class QLabel;
class QMediaPlayer;

class ArkEchoPlayerView : public QMainWindow
{
    Q_OBJECT

    Ui::ArkEchoPlayerViewClass* ui_;
    ArkEchoPlayerModel* model_;
    QLabel* webSocketStatus_;
    QMediaPlayer* player_;

    void initUi();
    void setWebSocketStatusLabel(bool connected);
    void setTWTrackList(QString filterText = "");
    void setLblDuration();

    // SongInfo Anzeige im UI anhand des Struct; setzen von Default Werten falls leer
    void setActualSongInfo(SongInfoStruct& songInfoS);

public:
    ArkEchoPlayerView(QWidget *parent = 0);
    ~ArkEchoPlayerView();

    // Neu Laden der Liste im Model, und aktualisieren der Anzeige mit Status MessageBox
    void loadMusicSongs();

private slots:
    void onUpdateView(const int &uve);
    void onRemoteVolumeValueChanged(const int & value);
    void on_actionManuelle_Verbindung_triggered();
    void on_actionQR_Code_Verbindung_triggered();
    void on_actionEinstellungen_triggered();
    void onPbBackwardClicked();
    void onPbForwardClicked();
    void onPbPlay_PauseClicked();
    void onPbStopClicked();
    void onTwTrackListItemDoubleClicked(QTableWidgetItem* item);
    void onSliderVolumeValueChanged(const int &value);
    void onPlayerPositionChanged(const qint64 &position);
    void onSliderDurationPressed();
    void onSliderDurationReleased();
    void onLeFilterTextChanged(const QString& text);
    void onPbClearFilterClicked();
    void onPbShuffleClicked();
    void onActualSongInfoChanged(const SongInfoStruct& sis);
};

#endif // ARKECHOPLAYERVIEW_H
