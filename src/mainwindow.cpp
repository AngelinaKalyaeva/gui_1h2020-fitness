#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    eventCreationForm = new NewEventCreationForm(parent);
    eventsList = QStringList();
    eventDiary = QMap<QString, QList<Event>>();

    ui->setupUi(this);

    connect(eventCreationForm, SIGNAL(newEventCreated()), this, SLOT(new_event_created()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->eventCreationForm->show();
}

void MainWindow::new_event_created()
{
        QStringListModel* model = new  QStringListModel(this->ui->listView->model());
        if (model == NULL){
            model = new QStringListModel(this);
        }

        if (!eventsList.contains(eventCreationForm->getCalendarWidgetDate())) {
            eventsList.append(eventCreationForm->getCalendarWidgetDate());

            if (!eventDiary.contains(eventCreationForm->getCalendarWidgetDate())){
                eventDiary.insert(eventCreationForm->getCalendarWidgetDate(), QList<Event>());
            }
        }

        eventDiary[eventCreationForm->getCalendarWidgetDate()].append(
                    Event(
                        eventCreationForm->getName(),
                        eventCreationForm->getDescription(),
                        (int) 0
                        )
                    );

        model->setStringList(eventsList);
        this->ui->listView->setModel(model);

        eventCreationForm->clearName();
        eventCreationForm->clearDescription();
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Описание"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выполнено"));

    QString itemText = index.data(Qt::DisplayRole).toString();
    for (int i = 0; i < eventDiary[itemText].size(); ++i) {
        ui->tableWidget->setRowCount(i+1);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(eventDiary[index.data(Qt::DisplayRole).toString()][i].getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(eventDiary[index.data(Qt::DisplayRole).toString()][i].getDescription()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(eventDiary[index.data(Qt::DisplayRole).toString()][i].getDone()).append('%')));
    }
}
