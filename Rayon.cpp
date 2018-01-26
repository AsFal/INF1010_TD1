/****************************************************************************
* Fichier: Rayon.cpp
* Auteurs: Alexandre Falardeau et Hugo Leclair
* Date: 26 janvier 2018
* Mise a jour : 11 mai 2011
* Description: Description des méthodes de la classe Rayon.cpp
****************************************************************************/

#include "Rayon.h"
#include "Produit.h"
#include <iostream>
using namespace std;

/****************************************************************************
* Fonction: Rayon::Rayon
* Description: Constructeur par défaut
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Rayon::doublerTailleTableau(Produit**& produitsPtr)
{
	capaciteProduits_ *= 2;
	if (capaciteProduits_ == 0) {
		capaciteProduits_ = 5;
	}
	Produit** tampon = produitsPtr;
	produitsPtr = new Produit*[capaciteProduits_];
	for (int i = 0; i < nombreProduits_; i++)
		produitsPtr[i] = tampon[i];
	delete[] tampon;
	tampon = nullptr;
}

Rayon::Rayon() 
{
	categorie_ = "";
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}

Rayon::Rayon(string cat) : categorie_(cat)
{}

string Rayon:: obtenirCategorie()
{
	return categorie_;
}

Produit** Rayon::obtenirTousProduits() 
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits()
{
	return capaciteProduits_;
}

int Rayon::obtenirNombreProduits() 
{
	return nombreProduits_;
}

void Rayon::modifierCategorie(string cat) 
{
	categorie_ = cat;
}

void Rayon::ajouterProduit(Produit* produit) {
	if (capaciteProduits_ == nombreProduits_)
		doublerTailleTableau(tousProduits_);
	else
		tousProduits_[nombreProduits_++] = produit;
}

void Rayon::afficher()
{
	cout << "categorie: " << categorie_ << endl
		<< "capacite de produits:" << capaciteProduits_ << endl
		<< "nombre de produits:" << nombreProduits_ << endl
		<<"Liste ds produits contenu dans le rayon";
	for (int i = 0; i < nombreProduits_; i++)
		tousProduits_[i]->afficher();
}





