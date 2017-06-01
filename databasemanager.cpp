#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    dbConnection = QSqlDatabase::addDatabase("QSQLITE");
    dbConnection.setDatabaseName("data/hgpos.db");

    if (!dbConnection.open())
        qDebug() << "Error: connection with database";

    listProduits = NULL;
}

DatabaseManager::~DatabaseManager()
{
    dbConnection.close();
}

QList<Produit> *DatabaseManager::getProduitList()
{
    if(listProduits != NULL)
        listProduits->clear();
    else
        listProduits = new QList<Produit>;

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

QList<QString> *DatabaseManager::searchMember(QString nom, QString prenom)
{
    QList<QString>* r = new QList<QString>;

    if(!dbConnection.open())
    {
        qDebug()<<"DataBase::searchMember : database not open";
        return r;
    }

    QString q;

    if(nom.isEmpty() && prenom.isEmpty())
        return r;
    else if(nom.isEmpty())
        q = "SELECT * FROM Membres WHERE UPPER(prenom) = UPPER('" + prenom + "')";
    else if(prenom.isEmpty())
        q = "SELECT * FROM Membres WHERE UPPER(nom) = UPPER('" + nom + "')";
    else
        q = "SELECT * FROM Membres WHERE UPPER(nom) = UPPER('" + nom + "') AND UPPER(prenom) = UPPER('" + prenom +"')";

    QSqlQuery query(q);

    while (query.next())
    {
        qDebug() << query.value(0);
        r->append(QString("(" + query.value(0).toString() + ") " + query.value(1).toString()) + " "
                  + query.value(2).toString() + " " + query.value(3).toString() + " "
                  + query.value(4).toString());
    }

    return r;
}

int DatabaseManager::sellPanier(Panier *p)
{
    int i;

    if(!dbConnection.open())
    {
        qDebug()<<"DataBase::getProduitList : database not open";
        return 1;
    }

    for(i=0;i<p->prod.size();i++)
    {
        QString q = "INSERT INTO `Ventes` VALUES (NULL,'" +
                    QString::number(p->prod.at(i).idProduit) + "','" +
                    QString::number(p->unit.at(i)) + "',CURRENT_TIMESTAMP)";
        QSqlQuery query(q);
    }

    return 0;
}

int DatabaseManager::sell(int p, unsigned int u)
{
    QString q = "INSERT INTO `Ventes` VALUES (NULL,'" +
                QString::number(listProduits->at(p-1).idProduit) + "','" +
                QString::number(u) + "',CURRENT_TIMESTAMP)";
    QSqlQuery query(q);
}

int DatabaseManager::insertMembre(QString nom, QString prenom, QString email, QString statut)
{
    if(!dbConnection.open())
    {
        qDebug()<<"DataBase::getProduitList : database not open";
        return 1;
    }

    QString q = "INSERT INTO `Membres` VALUES (NULL,'" + nom +
                "','" + prenom + "','" + email + "','" + statut + "')";
    QSqlQuery query(q);

    return 0;
}
