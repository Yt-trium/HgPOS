#ifndef PANIER_H
#define PANIER_H

#include <QList>

#include "produit.h"

class Panier
{
public:
    Panier(){}

    /**
     * @brief prod, la liste des produits dans le panier
     */
    QList<Produit> prod;
    /**
     * @brief unit, la liste du nombre d'unité de produits dans le panier
     */
    QList<unsigned int> unit;

    /**
     * @brief clear efface le panier actuel.
     */
    void clear(){prod.clear();unit.clear();}
};

#endif // PANIER_H
