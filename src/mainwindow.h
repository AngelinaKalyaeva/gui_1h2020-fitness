#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QMap>
#include <QList>
#include <QModelIndex>
#include <QTableWidgetItem>
#include "event.h"
#include "neweventcreationform.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>
#include <QUrlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    NewEventCreationForm* eventCreationForm;
    QMap<QString, QList<Event>> eventDiary;
    QStringList eventsList;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void new_event_created();
    void on_listView_clicked(const QModelIndex &index);
    void on_pushButton_3_clicked();
    void onfinish(QNetworkReply *rep);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
