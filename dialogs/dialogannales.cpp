#include "dialogannales.h"
#include "ui_dialogannales.h"

DialogAnnales::DialogAnnales(QWidget *parent, DatabaseManager *dbm) :
    QDialog(parent),
    ui(new Ui::DialogAnnales)
{
    ui->setupUi(this);

    db = dbm;

    int i;

    listProduits = db->getProduitList();

    for(i=0;i<listProduits->size();i++)
    {
        if(listProduits->at(i).prix == 0.3f)
        {
            ui->comboBox->addItem(listProduits->at(i).nom);
        }
    }
}

DialogAnnales::~DialogAnnales()
{
    delete ui;
}

void DialogAnnales::accept()
{
    this->hide();

    int i,j=0;
    QString x = ui->comboBox->currentText();

    for(i=0;i<listProduits->size();i++)
    {
        if(listProduits->at(i).nom == x)
            j = i+1;
    }

    if(j!=0)
    {
        db->sell(j,1);
        db->sell(39,1);
    }

    QDialog::accept();
}
