#include "event.h"

Event::Event(QString name, QString description, int done)
{
    this->name = name;
    this->description = description;
    this->done = done;
}

QString Event::getName() {
    return this->name;
}

QString Event::getDescription() {
    return this->description;
}

int Event::getDone() {
    return this->done;
}

void Event::setName(QString name) {
    this->name = name;
}


void Event::setDescription(QString description) {
    this->description = description;
}

void Event::setDone(int done) {
    this->done = done;
}
