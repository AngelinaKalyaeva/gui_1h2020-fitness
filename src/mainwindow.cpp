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
    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
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
                        eventCreationForm->getPlan(),
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
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Описание"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Количество"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Выполнено"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Прогресс"));

    QString itemText = index.data(Qt::DisplayRole).toString();
    for (int i = 0; i < eventDiary[itemText].size(); ++i) {
        ui->tableWidget->setRowCount(i+1);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(eventDiary[index.data(Qt::DisplayRole).toString()][i].getDescription()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(eventDiary[index.data(Qt::DisplayRole).toString()][i].getPlan())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(eventDiary[index.data(Qt::DisplayRole).toString()][i].getDone())));
        float done = (float) eventDiary[index.data(Qt::DisplayRole).toString()][i].getDone();
        float plan = (float)  eventDiary[index.data(Qt::DisplayRole).toString()][i].getPlan();
        int res = plan != 0 ? int(100*done/plan) : 0;
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(res).append("%")));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));


    QString itemText = "";
    QModelIndex index = ui->listView->currentIndex();
    for (int i = 0; i < eventDiary[index.data(Qt::DisplayRole).toString()].size(); ++i) {
        itemText.append("_______________________").append("\n");
        itemText.append("Описание: ").append(eventDiary[index.data(Qt::DisplayRole).toString()][i].getDescription()).append("\n");
        itemText.append("Запланировано: ").append(QString::number(eventDiary[index.data(Qt::DisplayRole).toString()][i].getPlan())).append("\n");
        itemText.append("Сделано: ").append(QString::number(eventDiary[index.data(Qt::DisplayRole).toString()][i].getDone())).append("\n");

        float done = (float) eventDiary[index.data(Qt::DisplayRole).toString()][i].getDone();
        float plan = (float)  eventDiary[index.data(Qt::DisplayRole).toString()][i].getPlan();
        int res = plan != 0 ? int(100*done/plan) : 0;

        itemText.append("Процент выполнения: ").append(QString::number(res).append("%")).append("\n");
        itemText.append("_______________________").append("\n");
    }


    QUrlQuery postData;
    postData.addQueryItem("subject", "Статистика по выбранному дню");
    postData.addQueryItem("text", itemText);
    postData.addQueryItem("access_token", "953kwv5c2bxy4bk1umvd7fts");

    QNetworkRequest request(QUrl("https://postmail.invotes.com/send"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,
        "application/x-www-form-urlencoded");
    mgr->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
}

void MainWindow::onfinish(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QString str(bts);

}

void MainWindow::on_pushButton_2_clicked()
{
    eventDiary = QMap<QString, QList<Event>>();
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        eventDiary[eventCreationForm->getCalendarWidgetDate()].append(
                    Event(
                        ui->tableWidget->item(i, 1)->text().toInt(),
                        ui->tableWidget->item(i, 0)->text(),
                        ui->tableWidget->item(i, 2)->text().toInt()
                        )
                    );
    }

    on_listView_clicked(ui->listView->currentIndex());
}
