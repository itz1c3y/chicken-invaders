
#include "tracker.h"

Tracker::Tracker(QObject* parent) : QObject(parent) {}

void Tracker::addObjectToTrack(QObject* obj) {
    if (obj) {
        objects.append(obj);
        connect(obj, &QObject::destroyed, this, &Tracker::onObjectDestroyed);
    }
}

bool Tracker::allObjectsDestroyed() const {
    return objects.isEmpty();
}

void Tracker::onObjectDestroyed(QObject* obj) {
    qDebug() << "Object destroyed:" << obj;
    objects.removeOne(obj);
}
