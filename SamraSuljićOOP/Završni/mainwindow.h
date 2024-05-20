#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include <QtSql/QSqlDatabase>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QSqlQueryModel>


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

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    QTableView *tableView;
   QSqlTableModel *model;
protected:
    void showEvent(QShowEvent *event);
private slots:
    void on_comboBox_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H
// PrinterItem.h
#ifndef PRINTERITEM_H
#define PRINTERITEM_H

#include <QGraphicsPixmapItem>

class PrinterItem : public QGraphicsPixmapItem
{
public:
    PrinterItem(const QPixmap &pixmap, qreal x, qreal y, QGraphicsItem *parent = NULL);
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
   QPointF originalPos;
};

#endif // PRINTERITEM_H
