#ifndef PANIER_H
#define PANIER_H

#include <QList>

#include "produit.h"

class Panier
{
public:
    Panier(){}

    QList<Produit> prod;
    QList<unsigned int> unit;

    void clear(){prod.clear();unit.clear();}
};

#endif // PANIER_H
