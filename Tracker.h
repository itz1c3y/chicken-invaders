//
// Created by Sahraee on 08/07/2024.
//

#ifndef TRACKER_H
#define TRACKER_H

#include <QObject>
#include <QList>
#include <QDebug>

class Tracker : public QObject {
Q_OBJECT
public:
    explicit Tracker(QObject* parent = nullptr);

    void addObjectToTrack(QObject* obj);
    bool allObjectsDestroyed() const;

private slots:
    void onObjectDestroyed(QObject* obj);

private:
    QList<QObject*> objects;
};

#endif // TRACKER_H
