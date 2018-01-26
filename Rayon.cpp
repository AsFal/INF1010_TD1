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
* Fonction: Rayon::doublerTailleTableau
* Description: Double la grandeur d'un tableau dynamique de pointeurs de produits
* Paramètres: (Produit**&) produitsPtr: la référence du pointeur au tableau à doubler
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

/****************************************************************************
* Fonction: Rayon::Rayon
* Description: Constructeur par défaut
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
Rayon::Rayon() 
{
	categorie_ = "";
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}

/****************************************************************************
* Fonction: Rayon::Rayon
* Description: Constructeur par paramètres
* Paramètres: - string cat: la gatégorie du rayon lors de l'initialisation
* Retour: aucun
****************************************************************************/
Rayon::Rayon(string cat) : categorie_(cat)
{}

/****************************************************************************
* Fonction: Rayon::ObtenirCategorie
* Description: Retourne categorie_
* Paramètres: aucun
* Retour: (string) la valeur de categorie_
****************************************************************************/
string Rayon:: obtenirCategorie() const
{
	return categorie_;
}

/****************************************************************************
* Fonction: Rayon::ObtenirTousProduits
* Description: Retourne tousProduits_
* Paramètres: aucun
* Retour: (Produit**) le pointeur vers le tableau de pointeurs Produit
****************************************************************************/
Produit** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

/****************************************************************************
* Fonction: Rayon::ObtenirCapaciteProduits
* Description: Retourne capaciteProduit_
* Paramètres: aucun
* Retour: (int) la valeur de capaciteProduits_
****************************************************************************/
int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

/****************************************************************************
* Fonction: Rayon::ObtenirNombreProduits
* Description: Retourne nombreProduits_
* Paramètres: aucun
* Retour: (int) retourne la valeur de nombreProduits
****************************************************************************/
int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}

/****************************************************************************
* Fonction: Rayon::modifierCategorie
* Description: Affecte la valeur du parametre cat à l'attribut categorie_
* Paramètres: -(string) cat : Le nouveau de la categorie du rayon
* Retour: aucun
****************************************************************************/
void Rayon::modifierCategorie(string cat) 
{
	categorie_ = cat;
}

/****************************************************************************
* Fonction: Rayon::ajouterProduit
* Description: Ajoute un pointeur à un produit au tableau tousProduits_
	Alloue l'espace pour le tableau si le tableau est à capacité maximale
* Paramètres: - (*Produit) produit: pointeur vers le Produit à ajouter au rayon
* Retour: aucun
****************************************************************************/
void Rayon::ajouterProduit(Produit* produit) {
	if (capaciteProduits_ == nombreProduits_)
		doublerTailleTableau(tousProduits_);
	else
		tousProduits_[nombreProduits_++] = produit;
}

/****************************************************************************
* Fonction: Rayon::afficher
* Description: Affiche l'information générale du rayon ainsi qu'une liste
des articles selon la méthode defini Produit::afficher
* Paramètres: aucun
* Retour: (string) la valeur de categorie_
****************************************************************************/
void Rayon::afficher()
{
	cout << "categorie: " << categorie_ << endl
		<< "capacite de produits:" << capaciteProduits_ << endl
		<< "nombre de produits:" << nombreProduits_ << endl
		<<"Liste ds produits contenu dans le rayon";
	for (int i = 0; i < nombreProduits_; i++)
		tousProduits_[i]->afficher();
}





