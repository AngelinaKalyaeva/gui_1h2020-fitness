#ifndef EVENT_H
#define EVENT_H

#include <QString>

class Event {
public:
    Event(QString name, QString description, int done);

    QString getName();
    QString getDescription();
    int getDone();

    void setName(QString name);
    void setDescription(QString description);
    void setDone(int done);
private:
    QString name;
    QString description;
    int done;
};

#endif // EVENT_H
