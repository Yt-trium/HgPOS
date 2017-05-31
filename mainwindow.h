#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>
#include <QSignalMapper>
#include <QInputDialog>
#include <QShortcut>

#include "dialogs/dialoginscription.h"
#include "dialogs/dialogrecherche.h"
#include "databasemanager.h"
#include "produit.h"
#include "panier.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 * La class pour la fenêtre principale.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    /**
     * @brief loadListPushButton charge les boutons utilisé par updatePB
     * @return 0 if no error
     */
    int loadListPushButton();

    /**
     * @brief updatePB
     * @param Le type des boutons à afficher (référence à la colonne type de la table Produits)
     *        Descriptions des types disponibles dans le README
     */
    void updatePB(int type);

    /**
     * @brief Met à jours la listWidget du panier
     */
    void updatePanier();

    /**
     * @brief retourne la ligne de l'élément actuellement selectionné
     */
    int getPanierCurrentRow();

    /**
     * @brief modifie le nombre d'unité d'un produit
     * @param la ligne du produit
     */
    void updatePanierUnit(int r);

    /**
     * @brief Objet d'accès à la base de données
     */
    DatabaseManager *db;
    /**
     * @brief Liste des produits
     */
    QList<Produit> *listProduits;
    /**
     * @brief Liste contenant les boutons de vente
     */
    QList<QPushButton*> *listPushButton;
    /**
     * @brief mapper pour les signaux de listPushButton
     */
    QSignalMapper mapper;
    /**
     * @brief Les produits actuellements dans le panier
     */
    Panier *panier;

private slots:
    void on_PBViderPanier_clicked();
    void on_PBSupprimerElement_clicked();
    void on_PBModifierQuantite_clicked();
    void on_PBValider_clicked();

    void on_LWPanier_doubleClicked();

    void on_actionSnacks_triggered();
    void on_actionBoissons_triggered();
    void on_actionGoodies_triggered();
    void on_actionImpressions_triggered();

    void venteBtn_clicked(int idProduit);

    void on_actionInscriptions_triggered();
    void on_actionRechercheMembre_triggered();
};

#endif // MAINWINDOW_H
