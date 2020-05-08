#ifndef NEWEVENTCREATIONFORM_H
#define NEWEVENTCREATIONFORM_H

#include <QDialog>

namespace Ui {
class NewEventCreationForm;
}

class NewEventCreationForm : public QDialog
{
    Q_OBJECT

public:
    explicit NewEventCreationForm(QWidget *parent = 0);
    ~NewEventCreationForm();

private:
    Ui::NewEventCreationForm *ui;
};

#endif // NEWEVENTCREATIONFORM_H
