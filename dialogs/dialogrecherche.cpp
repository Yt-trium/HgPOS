#include "dialogrecherche.h"
#include "ui_dialogrecherche.h"

DialogRecherche::DialogRecherche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRecherche)
{
    ui->setupUi(this);
}

void DialogRecherche::setDB(DatabaseManager *dbm)
{
    db = dbm;
}

DialogRecherche::~DialogRecherche()
{
    delete ui;
}

void DialogRecherche::on_PBRecherche_clicked()
{
    QList<QString> *r = db->searchMember(ui->LENom->text(),ui->LEPrenom->text());
    int i;

    ui->LWResultats->clear();

    for(i=0;i<r->size();i++)
    {
        ui->LWResultats->addItem(r->at(i));
    }
}

void DialogRecherche::on_LENom_textChanged(const QString &arg1)
{
    on_PBRecherche_clicked();
}

void DialogRecherche::on_LEPrenom_textChanged(const QString &arg1)
{
    on_PBRecherche_clicked();
}
