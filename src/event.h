#ifndef EVENT_H
#define EVENT_H

#include <QString>

class Event {
public:
    Event(int plan, QString description, int done);

    int getPlan();
    QString getDescription();
    int getDone();

    void setPlan(int plan);
    void setDescription(QString description);
    void setDone(int done);
private:
    int plan;
    QString description;
    int done;
};

#endif // EVENT_H
