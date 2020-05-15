#include "event.h"

Event::Event(int plan, QString description, int done)
{
    this->plan = plan;
    this->description = description;
    this->done = done;
}

int Event::getPlan() {
    return this->plan;
}

QString Event::getDescription() {
    return this->description;
}

int Event::getDone() {
    return this->done;
}

void Event::setPlan(int plan) {
    this->plan = plan;
}


void Event::setDescription(QString description) {
    this->description = description;
}

void Event::setDone(int done) {
    this->done = done;
}
