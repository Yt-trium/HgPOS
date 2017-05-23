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

#### Utilisateurs
- **idUtilisateur**
- nom
- mdp
- droits
