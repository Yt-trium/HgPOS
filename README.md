# HgPOS
Mercure point of sale

# Base de données

### Tables concernant la vente et la gestion des stocks

##### Produits
- **idProduit**
- nom
- prix
- ico (nom du fichier icone du produit)
- type
    * 1 : Snacks
    * 2 : Boissons
    * 10 : Sandwich (unique)
    * 20 : Impressions
    * 30 : Goodies
    * 40 : Adhésion (unique)
    * 50 : Annales (unique)

##### Stocks
- **idStock**
- _idProduit_ (Produits)
- unite (unites actuels en stock)

##### Ventes
- **idVente**
- _idProduit_ (Produits)
- unite (unites vendues)

##### Formules
- **idFormule**
- _idProduitSandwich_ (Produits)
- _idProduitSnack_ (Produits)
- _idProduitBoisson_ (Produits)

### Autres tables

#### Membres
- **idMembre**
- nom
- prenom
- email
- statut
    * L1
    * L2M
    * L3M
    * M1M
    * M2M
    * L2I
    * L3I
    * M1I
    * M2I
    * AUTRE

#### Utilisateurs
- **idUtilisateur**
- nom
- mdp
- droits
