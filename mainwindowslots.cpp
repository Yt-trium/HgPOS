#include "mainwindow.h"

void MainWindow::on_PBViderPanier_clicked()
{
    panier->clear();
    updatePanier();
}

void MainWindow::on_PBValider_clicked()
{

}

void MainWindow::on_actionSnacks_triggered()
{
    updatePB(1);
}

void MainWindow::on_actionBoissons_triggered()
{
    updatePB(2);
}

void MainWindow::on_actionGoodies_triggered()
{
    updatePB(30);
}

void MainWindow::on_actionImpressions_triggered()
{
    updatePB(20);
}

void MainWindow::venteBtn_clicked(int idProduit)
{
    if(listProduits->at(idProduit-1).idProduit == idProduit)
    {
        panier->prod.append(listProduits->at(idProduit-1));
        panier->unit.append(1);
    }
    else
        qDebug() << "MainWindow::on_venteBtn_clicked : idProduit doesn't match";
    updatePanier();
}
