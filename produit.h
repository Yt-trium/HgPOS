#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QIcon>

/**
 * @brief Class représentant un produit
 */
class Produit
{
public:
    Produit(){}

    int idProduit;
    QString nom;
    float prix;
    QString ico;
    QIcon qicon;
    int type;
};

#endif // PRODUIT_H
