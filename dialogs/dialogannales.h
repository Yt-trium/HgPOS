#ifndef DIALOGANNALES_H
#define DIALOGANNALES_H

#include <QDialog>

#include "databasemanager.h"
#include "produit.h"

namespace Ui {
class DialogAnnales;
}

class DialogAnnales : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAnnales(QWidget *parent = 0, DatabaseManager *dbm = NULL);
    void setDB(DatabaseManager *dbm);
    ~DialogAnnales();

private slots:
    void accept();

private:
    Ui::DialogAnnales *ui;
    DatabaseManager *db;
    QList<Produit> *listProduits;
};

#endif // DIALOGANNALES_H
