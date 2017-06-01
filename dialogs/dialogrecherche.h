#ifndef DIALOGRECHERCHE_H
#define DIALOGRECHERCHE_H

#include <QDialog>

#include "databasemanager.h"

namespace Ui {
class DialogRecherche;
}

class DialogRecherche : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRecherche(QWidget *parent = 0);
    void setDB(DatabaseManager *dbm);
    ~DialogRecherche();

private slots:
    void on_PBRecherche_clicked();
    void on_LENom_textChanged(const QString &arg1);
    void on_LEPrenom_textChanged(const QString &arg1);

private:
    Ui::DialogRecherche *ui;
    DatabaseManager *db;
};

#endif // DIALOGRECHERCHE_H
