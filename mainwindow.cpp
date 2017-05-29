#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new DatabaseManager();
    listProduits = db->getProduitList();
    loadListPushButton();
    panier = new Panier();

    updatePB(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::loadListPushButton()
{
    int i;
    Produit p;

    listPushButton = new QList<QPushButton*>();

    for(i=0;i<listProduits->size();i++)
    {
        p = listProduits->at(i);

        QPushButton* btn = new QPushButton(this);
        btn->setVisible(false);
        btn->setText(p.nom);
        btn->setIcon(p.qicon);
        btn->setIconSize(QSize(50,50));

        listPushButton->append(btn);

        connect(btn, SIGNAL(clicked()), &mapper, SLOT(map()));
        mapper.setMapping(btn, listProduits->at(i).idProduit);
    }
    connect(&mapper, SIGNAL(mapped(int)), this, SLOT(venteBtn_clicked(int)));
}

void MainWindow::updatePB(int type)
{
    int i=0,j=0;
    Produit p;

    for(i=0;i<listProduits->size();i++)
    {
        p = listProduits->at(i);
        QPushButton* btn = listPushButton->at(i);

        if(p.type == type)
        {
            btn->setVisible(true);

            ui->GLProduits->addWidget(btn,j/5,j%5);
            j++;
        }
        else
            btn->setVisible(false);
    }
}

void MainWindow::updatePanier()
{
    float t = 0;
    int i;

    ui->LWPanier->clear();

    for(i=0;i<panier->prod.size();i++)
    {
        QListWidgetItem* itm = new QListWidgetItem(QString::number(panier->unit.at(i)) + " " +
                                                   panier->prod.at(i).nom + " (" +
                                                   QString::number(panier->prod.at(i).prix*panier->unit.at(i)) +
                                                   QChar(8364) + ")");
        switch(panier->prod.at(i).type)
        {
            case 1:
                itm->setBackgroundColor(QColor(255,255,200));
            break;
            case 2:
                itm->setBackgroundColor(QColor(200,255,255));
            break;
        }

        t += panier->prod.at(i).prix*panier->unit.at(i);

        ui->LWPanier->addItem(itm);
    }

    ui->statusBar->showMessage("Total : " + QString::number(t) + QChar(8364));
}
