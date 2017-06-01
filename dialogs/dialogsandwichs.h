#ifndef DIALOGSANDWICHS_H
#define DIALOGSANDWICHS_H

#include <QDialog>

#include "databasemanager.h"

namespace Ui {
class DialogSandwichs;
}

class DialogSandwichs : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSandwichs(QWidget *parent = 0, DatabaseManager *dbm = NULL);
    ~DialogSandwichs();

private:
    Ui::DialogSandwichs *ui;
    DatabaseManager *db;
};

#endif // DIALOGSANDWICHS_H
