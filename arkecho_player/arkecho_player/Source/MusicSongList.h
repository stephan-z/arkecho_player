#ifndef MUSICSONGLIST_H
#define MUSICSONGLIST_H

#include "MusicSong.h"

#include <QObject>
#include <QList>

class MusicSongList : public QObject
{
    Q_OBJECT

public:
    MusicSongList(QObject *parent = 0);
    ~MusicSongList();

    bool allSongsLoaded();
    void loadSongs(QStringList directories);
    QList<MusicSong*> getSongList();

private:
    QList<MusicSong*> songList_;
};

#endif // MUSICSONGLIST_H