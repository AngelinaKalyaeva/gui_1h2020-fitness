#ifndef NEWEVENTCREATIONFORM_H
#define NEWEVENTCREATIONFORM_H

#include <QDialog>
#include <QString>
#include <QStringListModel>

namespace Ui {
class NewEventCreationForm;
}

class NewEventCreationForm : public QDialog
{
    Q_OBJECT

public:
    QString getCalendarWidgetDate();
    QString getName();
    QString getDescription();
    void clearName();
    void clearDescription();
    explicit NewEventCreationForm(QWidget *parent = 0);
    ~NewEventCreationForm();

signals:
    void newEventCreated();
private slots:
    void on_pushButton_clicked();

    void on_calendarWidget_selectionChanged();

private:
    Ui::NewEventCreationForm *ui;
};

#endif // NEWEVENTCREATIONFORM_H
