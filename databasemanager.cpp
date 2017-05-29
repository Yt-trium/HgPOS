#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    dbConnection = QSqlDatabase::addDatabase("QSQLITE");
    dbConnection.setDatabaseName("data/hgpos.db");

    if (!dbConnection.open())
        qDebug() << "Error: connection with database";
}

DatabaseManager::~DatabaseManager()
{
    dbConnection.close();
}

QList<Produit> *DatabaseManager::getProduitList()
{
    QList<Produit>* listProduits = new QList<Produit>;

    if(!dbConnection.open())
    {
        qDebug()<<"DataBase::getProduitList : database not open";
        return listProduits;
    }

    Produit p;
    QString q = "SELECT * FROM Produits";

    QSqlQuery query(q);

    while (query.next())
    {
        p.idProduit = query.value(0).toInt();
        p.nom       = query.value(1).toString();
        p.prix      = query.value(2).toFloat();
        p.ico       = query.value(3).toString();
        p.type      = query.value(4).toInt();
        p.qicon = QIcon("./data/produits_ico/" + p.ico);

        listProduits->append(p);
    }

    return listProduits;
}
