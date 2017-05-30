#include "dialoginscription.h"
#include "ui_dialoginscription.h"

DialogInscription::DialogInscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInscription)
{
    ui->setupUi(this);
}

void DialogInscription::setDB(DatabaseManager *dbm)
{
    db = dbm;
}

DialogInscription::~DialogInscription()
{
    delete ui;
}

void DialogInscription::accept()
{
    db->insertMembre(ui->LEPrenom->text(),ui->LENom->text(),ui->LEEmail->text(),ui->CBStatu->currentText());
    db->sell(38,1);
    this->hide();
}
