#include "neweventcreationform.h"
#include "ui_neweventcreationform.h"

NewEventCreationForm::NewEventCreationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEventCreationForm)
{
    ui->setupUi(this);
}

NewEventCreationForm::~NewEventCreationForm()
{
    delete ui;
}
