#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QFileInfo>
#include<QDialog>
#include <QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QSqlError>
#include <QString>
using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void showEvent(QShowEvent *event);
private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_add_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_sljedeciMjesec_clicked();

    void on_spinBox_mjesec_valueChanged(int arg1);

    void on_spinBox_godina_valueChanged(int arg1);

    void on_pushButton_delete_clicked();

    void populate_tableView_2(QString selectedSerijski);

    void onSerijskiBrojClicked();

    void clearLineEdits();
private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
};

#endif // MAINWINDOW_H
