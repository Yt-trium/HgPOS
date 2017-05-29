#ifndef DIALOGINSCRIPTION_H
#define DIALOGINSCRIPTION_H

#include <QDialog>

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
    ~DialogInscription();

private:
    Ui::DialogInscription *ui;
};

#endif // DIALOGINSCRIPTION_H
