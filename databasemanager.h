#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>

#include "panier.h"
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

    /**
     * @brief Ajouts les produits dans le panier a la liste des éléments vendus.
     * @param p le panier
     * @return 0 si pas d'erreur
     */
    int sellPanier(Panier *p);

    /**
     * @brief Ajouts le produit dans la liste des éléments vendus.
     * @param p l'id du produit
     * @param u le nombre d'unité
     * @return 0 si pas d'erreur
     */
    int sell(int p, unsigned int u);

    /**
     * @brief Ajoute un membre à la liste des membres
     * @param Le nom
     * @param Le prenom
     * @param L'email
     * @param Le statut
     * @return 0 si pas d'erreur
     */
    int insertMembre(QString nom, QString prenom, QString email, QString statut);

private:
    /**
     * @brief Interface d'accès QSqlDatabase
     */
    QSqlDatabase dbConnection;

    QList<Produit>* listProduits;
};

#endif // DATABASEMANAGER_H
