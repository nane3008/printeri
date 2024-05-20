#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QStandardItemModel>

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

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT (on_comboBox_currentIndexChanged(int)));
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    QSqlQuery query("SELECT * FROM Printeri");
    while (query.next()) {
        QString serijskiBroj = query.value("serijskiBroj").toString();
        QString inventurniBroj = query.value("inventurniBroj").toString();
        QString model = query.value("model").toString();
        QString zaduzenaOsoba = query.value("zaduzenaOsoba").toString();

        // Load the printer image and create a QGraphicsPixmapItem
        QPixmap printerImage("C:/Users/HP Touch screen X360/Pictures/printer1.jpeg"); // Replace with the actual path to your printer image
        QGraphicsPixmapItem *printerItem = new QGraphicsPixmapItem(printerImage);

        // Create QGraphicsTextItems for printer details
        QGraphicsTextItem *serijskiText = new QGraphicsTextItem("Serijski broj: " + serijskiBroj);
        QGraphicsTextItem *inventurniText = new QGraphicsTextItem("Inventurni broj: " + inventurniBroj);
        QGraphicsTextItem *modelText = new QGraphicsTextItem("Model: " + model);
        QGraphicsTextItem *zaduzenaOsobaText = new QGraphicsTextItem("Zaduzena osoba: " + zaduzenaOsoba);

        // Position and add items to the scene
        qreal x = 100; // Adjust the X position as needed
        qreal y = 100; // Adjust the Y position as needed
        qreal spacing = 20; // Adjust the spacing between items as needed

        printerItem->setPos(x, y);
        y += spacing;
        serijskiText->setPos(x, y);
        y += spacing;
        inventurniText->setPos(x, y);
        y += spacing;
        modelText->setPos(x, y);
        y += spacing;
        zaduzenaOsobaText->setPos(x, y);

        scene->addItem(printerItem);
        scene->addItem(serijskiText);
        scene->addItem(inventurniText);
        scene->addItem(modelText);
        scene->addItem(zaduzenaOsobaText);

}}

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

  QSqlQuery uniqueLocationsQuery("SELECT DISTINCT Lokacija FROM Printeri");
  while (uniqueLocationsQuery.next()) {
      QString location = uniqueLocationsQuery.value(0).toString();
      ui->comboBox->addItem(location);
      connect(ui->comboBox, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(on_comboBox_currentIndexChanged(const QString&)));

  }
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
   /* QString trenutnaLokacija=ui->comboBox->itemText(index);
    model->setFilter("lokacija= '"+trenutnaLokacija+"'");
    model->select();

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    for (int row=0; row < ui->tableView->model()->rowCount(); ++row) {


        QModelIndex indexSerijskiBroj = ui->tableView->model()->index(row, 1);
        QModelIndex indexInventurniBroj = ui->tableView->model()->index(row, 2);
        QModelIndex indexModel = ui->tableView->model()->index(row, 3);
        QModelIndex indexZaduzenaOsoba = ui->tableView->model()->index(row, 5);

        QString serijskiBroj = ui->tableView->model()->data(indexSerijskiBroj).toString();
        QString inventurniBroj = ui->tableView->model()->data(indexInventurniBroj).toString();
        QString modell = ui->tableView->model()->data(indexModel).toString();
        QString zaduzenaOsoba = ui->tableView->model()->data(indexZaduzenaOsoba).toString();
        QString imePrintera;

        if (modell == "Kyocera P6021CDN") {

                imePrintera = "printer1.jpg";

        } else if (modell == "ECOSYS M3550idn") {

                imePrintera = "printer3.jpg";

        } else if (modell == "Kyocera M3550idn") {

                imePrintera = "printer4.jpg";

        } else if (modell == "HP LJ P3015") {

                imePrintera = "printer2.jpg";

        } else if (modell == "Kyocera FS-4200DN") {

                imePrintera = "printer5.jpg";
        }

        QPixmap printerImage("C:/Users/HP Touch screen X360/Pictures"); // Local image path like "C:/Users/User/Desktop/Proj/"
        QSize printerSize(100,100);
        QPixmap scaledPrinterImage = printerImage.scaled(printerSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QGraphicsPixmapItem *printerItem = scene->addPixmap(scaledPrinterImage);
        printerItem->setFlag(QGraphicsItem::ItemIsMovable);

        QGraphicsTextItem *textItem = scene->addText(QString("Serijski broj: %1\nInventurni broj: %2\nModel: %3\nZadužena osoba: %4")
                                                     .arg(serijskiBroj)
                                                     .arg(inventurniBroj)
                                                     .arg(modell)
                                                     .arg(zaduzenaOsoba));


        textItem->setFlag(QGraphicsItem::ItemIsMovable);
        QPointF textItemPosition(printerItem->boundingRect().width()+30,printerItem->pos().y());
        textItem->setPos(textItemPosition);
        QGraphicsItemGroup *group = new QGraphicsItemGroup();
        group->addToGroup(printerItem);
        group->addToGroup(textItem);


        group->setFlag(QGraphicsItem::ItemIsMovable);
        qreal x = model->data(model->index(row, 8)).toReal();
        qreal y = model->data(model->index(row, 9)).toReal();
        printerItem->setPos(x,y);
        scene->addItem(group);
}*/}
