#include "dialogsandwichs.h"
#include "ui_dialogsandwichs.h"

DialogSandwichs::DialogSandwichs(QWidget *parent, DatabaseManager *dbm) :
    QDialog(parent),
    ui(new Ui::DialogSandwichs)
{
    ui->setupUi(this);
    db = dbm;
}

DialogSandwichs::~DialogSandwichs()
{
    delete ui;
}
