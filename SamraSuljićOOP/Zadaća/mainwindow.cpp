#include "mainwindow.h"
#include "ui_mainwindow.h"
QSqlQueryModel *sqlModel2;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydb=QSqlDatabase ::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/HP Touch screen X360/OneDrive/Radna površina/SamraSuljićOOP/Zadaća/DatabaseClickChargeSS.db");
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(on_tableView_clicked(const QModelIndex&)));


    if(!mydb.open()){

        ui->statusBar->showMessage("Bazu podataka nije moguće otvoriti");
    }
    else
        ui->statusBar->showMessage("Konektovani ste na bazu");


sqlModel2 = new QSqlQueryModel();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);

  QSqlQueryModel * sqlModel = new QSqlQueryModel();
  QSqlQuery qry;
  qry.prepare("select * from Printeri");
  qry.exec();
  sqlModel->setQuery(qry);
  ui->tableView->setModel(sqlModel);


  qDebug()<<(sqlModel->rowCount());


QSqlQueryModel * sqlModel2 = new QSqlQueryModel();
QSqlQuery qry2;
qry2.prepare("select * from Printeri2");
qry2.exec();
sqlModel2->setQuery(qry2);
ui->tableView_2->setModel(sqlModel2);


qDebug()<<(sqlModel2->rowCount());


}




void MainWindow::on_pushButton_add_clicked()
{
    QString redni, serijski, inventurni, model, lokacijaTrgovine, osobaProdaja, prethodnoStanjeBr, trenutnoStanjeBr;

    redni = ui->redniBroj->text();
    serijski = ui->serijskiBroj->text();
    inventurni = ui->inventurniBroj->text();
    model = ui->modelPrintera->text();
    lokacijaTrgovine = ui->lokacija->text();
    osobaProdaja = ui->osoba->text();
    prethodnoStanjeBr = ui->prethodnoStanje->text();
    trenutnoStanjeBr = ui->trenutnoStanje->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO Printeri (redniBroj, serijskiBroj, inventurniBroj, model, lokacija, osoba, prethodnoStanjeBrojaca, trenutnoStanjeBrojaca) VALUES ('"+redni+"','" +serijski+"', '"+inventurni+"','"+model+"', '"+lokacijaTrgovine+"', '"+osobaProdaja+"', '"+prethodnoStanjeBr+"', '"+trenutnoStanjeBr+"')");



    if (qry.exec()) {
        QMessageBox::information(this, tr("Add"), tr("Added"));
    } else {
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
}






void MainWindow::on_pushButton_update_clicked()
{

    QString serijski, inventurni, model, lokacija, osoba;
    int prethodnos, trenutnos;



    serijski = ui->serijskiBroj->text();
    inventurni = ui->inventurniBroj->text();
    model = ui->modelPrintera->text();
    lokacija = ui->lokacija->text();
    osoba = ui->osoba->text();
    prethodnos = ui->prethodnoStanje->text().toInt();
    trenutnos = ui->trenutnoStanje->text().toInt();

    QSqlQuery query;
    QString tabela = serijski;

    query.prepare("SELECT * FROM Printeri WHERE `serijskiBroj` = '" +serijski+"'");
    if (query.exec() && query.next()) {
        int trenutnoStanje = query.value("trenutno").toInt();
        int potrosnja = trenutnos - trenutnoStanje;
        double cijena = potrosnja * 0.019;
        QSqlQuery updateQuery;
        updateQuery.prepare("SELECT * FROM  Printeri2  WHERE godina = " + QString::number(ui->spinBox_godina->value()) + " AND mjesec = " + QString::number(ui->spinBox_mjesec->value()));
        if (updateQuery.exec() && updateQuery.next()) {
            QSqlQuery updateEntryQuery;
            updateEntryQuery.prepare("UPDATE Printeri2 SET prethodno = " + QString::number(prethodnos) + ", trenutno = " + QString::number(trenutnos) + ", potrosnja = " + QString::number(potrosnja) + ", cijena = " + QString::number(cijena) + " WHERE godina = " + QString::number(ui->spinBox_godina->value()) + " AND mjesec = " + QString::number(ui->spinBox_mjesec->value()));
            if (updateEntryQuery.exec()) {
                QMessageBox::information(this, tr("Update"), tr("Record updated"));
            } else {
                QMessageBox::critical(this, tr("Error"), updateEntryQuery.lastError().text());
            }
        } else {
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO Printeri2 (godina, mjesec, prethodno, trenutno, potrosnja, cijena) VALUES ( " + QString::number(ui->spinBox_godina->value()) + ", " + QString::number(ui->spinBox_mjesec->value())+"," + QString::number(prethodnos) + "," + QString::number(trenutnos) + ", " + QString::number(potrosnja) + ", " + QString::number(cijena) + ")");
            if (insertQuery.exec()) {
                QMessageBox::information(this, tr("Save"), tr("Record inserted"));
            } else {
                QMessageBox::critical(this, tr("Error"), insertQuery.lastError().text());
            }
        }
    } else {
        QMessageBox::information(this, tr("Error"), tr("Model does not exist in Printeri table"));
    }

                  clearLineEdits();
                     ui->pushButton_add->setEnabled(true);
                     ui->pushButton_update->setEnabled(false);
                     ui->pushButton_delete->setEnabled(false);
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString serijski=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT *from Printeri WHERE serijskiBroj = '" +serijski+"'");

    if(qry.exec()){

        while(qry.next()){

  ui->redniBroj->setText(qry.value(0).toString());
  ui->serijskiBroj->setText(qry.value(1).toString());
  ui->inventurniBroj->setText(qry.value(2).toString());
   ui->modelPrintera->setText(qry.value(3).toString());
  ui->lokacija->setText(qry.value(4).toString());
   ui->osoba->setText(qry.value(5).toString());
    ui->prethodnoStanje->setText(qry.value(6).toString());
     ui->trenutnoStanje->setText(qry.value(7).toString());
ui->label_serijski->setText(qry.value(1).toString());
ui->pushButton_add->setEnabled(false);

           // Populate TableView for the individual printer table
           QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM Printeri2");

           // Set the model for the TableView_2
           ui->tableView_2->setModel(model);

           // Calculate and display the total consumption for this printer
           QSqlQuery totalQuery("SELECT SUM(cijena) FROM Printeri2" + serijski);
           if (totalQuery.exec() && totalQuery.next()) {
                           QString totalCijena = totalQuery.value(0).toString();
                           ui->label_ukupnaPotrosnja->setText("Ukupna potrošnja: " + totalCijena);
                       }
                   }
               } else {
                   QMessageBox::critical(this, tr("Error"), qry.lastError().text());
               }
           }

void MainWindow::populate_tableView_2(QString selectedSerijski) {


    }

void MainWindow::on_pushButton_sljedeciMjesec_clicked()
{
    int trenutniMjesec=ui->spinBox_mjesec->value();
    int trenutnaGodina=ui->spinBox_godina->value();
    if (trenutniMjesec == 12){
        ui->spinBox_mjesec->setValue(1);
        ui->spinBox_godina->setValue(trenutnaGodina + 1);
    } else {
        ui->spinBox_mjesec->setValue(trenutniMjesec + 1);
    }
}


void MainWindow::on_spinBox_mjesec_valueChanged(int value)
{


}

void MainWindow::on_spinBox_godina_valueChanged(int value)
{


}

void MainWindow::on_pushButton_delete_clicked()
{

    QString serijski;


    serijski = ui->serijskiBroj->text();


    QSqlQuery qry;
    qry.prepare("DELETE FROM Printeri WHERE serijskiBroj='" +serijski+"'");



    if (qry.exec()) {
        QMessageBox::information(this, tr("Delete"), tr("Deleted"));
    } else {
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }

    clearLineEdits();
       ui->pushButton_add->setEnabled(true);
       ui->pushButton_update->setEnabled(false);
       ui->pushButton_delete->setEnabled(false);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{        QString serijski = ui->tableView->model()->data(index.sibling(index.row(), 1)).toString();


    ui->pushButton_update->setEnabled(true);
        ui->pushButton_delete->setEnabled(true);
        ui->pushButton_add->setEnabled(false);
             QSqlQuery qry;

         qry.prepare("SELECT *from Printeri WHERE serijskiBroj = '" +serijski+"'");

        if (qry.exec()) {
                if (qry.next()) {
                    ui->redniBroj->setText(qry.value(0).toString());
                    ui->serijskiBroj->setText(qry.value(1).toString());
                    ui->inventurniBroj->setText(qry.value(2).toString());
                    ui->modelPrintera->setText(qry.value(3).toString());
                    ui->lokacija->setText(qry.value(4).toString());
                    ui->osoba->setText(qry.value(5).toString());
                    ui->prethodnoStanje->setText(qry.value(6).toString());
                    ui->trenutnoStanje->setText(qry.value(7).toString());
                    ui->label_serijski->setText(qry.value(1).toString());
                }
            } else {
                QMessageBox::critical(this, tr("Error"), qry.lastError().text());
            }

}
void MainWindow::clearLineEdits()
{
    ui->redniBroj->clear();
    ui->serijskiBroj->clear();
    ui->inventurniBroj->clear();
    ui->modelPrintera->clear();
    ui->lokacija->clear();
    ui->osoba->clear();
    ui->prethodnoStanje->clear();
    ui->trenutnoStanje->clear();
    ui->label_serijski->clear();
}
