#ifndef DIALOGINSCRIPTION_H
#define DIALOGINSCRIPTION_H

#include <QDialog>

#include "databasemanager.h"

namespace Ui {
class DialogInscription;
}

/**
 * @brief Dialog pour inscrire un nouveau membre
 */
class DialogInscription : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInscription(QWidget *parent = 0);
    void setDB(DatabaseManager *dbm);
    ~DialogInscription();

private slots:
    void accept();

private:
    Ui::DialogInscription *ui;
    DatabaseManager *db;
};

#endif // DIALOGINSCRIPTION_H
