#include "neweventcreationform.h"
#include "ui_neweventcreationform.h"

NewEventCreationForm::NewEventCreationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEventCreationForm)
{
    ui->setupUi(this);


    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(reject()));
}

NewEventCreationForm::~NewEventCreationForm()
{
    delete ui;
}

void NewEventCreationForm::on_pushButton_clicked()
{
    emit newEventCreated();
}

QString NewEventCreationForm::getCalendarWidgetDate() {
    return this->ui->calendarWidget->selectedDate().toString();
}

int NewEventCreationForm::getPlan() {
    return this->ui->lineEdit_2->text().toInt();
}

QString NewEventCreationForm::getDescription() {
    return this->ui->textEdit->toPlainText();
}

void NewEventCreationForm::clearName() {
    this->ui->lineEdit_2->setText("[Количество]");
}

void NewEventCreationForm::clearDescription() {
    this->ui->textEdit->setText("[Описание события]");
}

void NewEventCreationForm::on_calendarWidget_selectionChanged()
{
    this->ui->lineEdit->setText(this->ui->calendarWidget->selectedDate().toString());
}
