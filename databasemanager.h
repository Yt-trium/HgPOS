#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>

#include "produit.h"

/**
 * @brief The DatabaseManager class
 * La class est utilisé pour accéder à la base de données sqlite.
 */

class DatabaseManager
{
public:
    /**
     * @brief DatabaseManager::DatabaseManager
     * Crée la connexion avec la base de données
     */
    DatabaseManager();
    /**
     * @brief DatabaseManager::~DatabaseManager
     */
    ~DatabaseManager();

    /**
     * @brief DatabaseManager::getProduitList
     * @return liste des produits (icon chargés)
     */
    QList<Produit>* getProduitList();

private:
    /**
     * @brief Interface d'accès QSqlDatabase
     */
    QSqlDatabase dbConnection;
};

#endif // DATABASEMANAGER_H
