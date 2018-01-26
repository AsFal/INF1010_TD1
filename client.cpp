/****************************************************************************
* Fichier: client.cpp
* Auteurs: Alexandre Falardeau et Hugo Leclair
* Date: 26 janvier 2018
* Mise a jour : 11 mai 2011
* Description: Description des m�thodes de la classe client.cpp
****************************************************************************/
#include "client.h"
#include "panier.h"
#include <iostream>

using namespace std;

/****************************************************************************
* Fonction: Client::Client
* Description: Constructeur par d�faut
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
Client::Client() 
{
	nom_ = "";
	prenom_ = "";
	identifiant_ = 0;
	codePostal_ = "";
	dateNaissance_ = 0;
	monPanier_ = nullptr;

}

/****************************************************************************
* Fonction: Client::Client
* Description: Constructeur par param�tres
* Param�tres: -(string) nom : le nom du client
*			  -(string) pr�nom : le pr�nom du client
*			  -(int) identifiant : le num�ro d'indentification du client
*			  -(string) codePostal : le code postal du client
*			  -(long) date: la date de naissance du client
* Retour: aucun
****************************************************************************/
Client::Client(string nom, string prenom, int identifiant, string codePostal, long date): nom_(nom),
prenom_(prenom), codePostal_(codePostal_)
{
	identifiant_ = identifiant;
	dateNaissance_ = date;
	monPanier_ = nullptr;

}

/****************************************************************************
* Fonction: Client::obtenirNom
* Description: Retourne nom_
* Param�tres: aucun
* Retour: (string) la valeur de nom_
****************************************************************************/
string Client::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction: Client::obtenirPrenom
* Description: Retourne prenom_
* Param�tres: aucun
* Retour: (string) la valeur de prenom_
****************************************************************************/
string Client::obtenirPrenom() const
{
	return prenom_;
}

/****************************************************************************
* Fonction: Client::obtenirIdentifiant
* Description: Retourne identifiant_
* Param�tres: aucun
* Retour: (int) la valeur de identifiant_
****************************************************************************/
int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

/****************************************************************************
* Fonction: Client::obtenirCodePostal
* Description: Retourne codePostal_
* Param�tres: aucun
* Retour: (string) la valeur de codePostal_
****************************************************************************/
string Client::obtenirCodePostal() const
{
	return codePostal_;
}

/****************************************************************************
* Fonction: Client::obtenirDateNaissance
* Description: Retourne dateNaissance_
* Param�tres: aucun
* Retour: (long) la valeur de dateNaissance_
****************************************************************************/
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

/****************************************************************************
* Fonction: Client::modifierNom
* Description: Affecte la valeur du param�tre nom � l'attribut nom_
* Param�tres: -(string) nom: le nom du client
* Retour: aucun
****************************************************************************/
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction: Client::modifierPrenom
* Description: Affecte la valeur du param�tre prenom � l'attribut prenom_
* Param�tres: -(string) prenom: le nom du client
* Retour: aucun
****************************************************************************/
void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

/****************************************************************************
* Fonction: Client::modifierIdentifiant
* Description: Affecte la valeur du param�tre identifiant � l'attribut identifiant_
* Param�tres: -(int) identifiant: le identifiant du client
* Retour: aucun
****************************************************************************/
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

/****************************************************************************
* Fonction: Client::modifierCodePostal
* Description: Affecte la valeur du param�tre codePostal � l'attribut codePostal_
* Param�tres: -(string) codePostal: le code postal du client
* Retour: aucun
****************************************************************************/
void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

/****************************************************************************
* Fonction: Client::modifierDateNaissance
* Description: Affecte la valeur du param�tre date � l'attribut dateNaissance_
* Param�tres: -(int) nom: la date naissance du client
* Retour: aucun
****************************************************************************/
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

/****************************************************************************
* Fonction: Client::acheter
* Description: Acheter un produit en l'ajoutant au panier point� par le client
* Param�tres: -(Produit *) prod: Le produit � �tre ajout� au panier
* Retour: aucun
****************************************************************************/
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(4);
	monPanier_->ajouter(prod);
}

/****************************************************************************
* Fonction: Client::afficherPanier
* Description: Affiche le contenu du panier si le panier n'est pas vide
* Param�tres:aucun
* Retour: aucun
****************************************************************************/
void Client::afficherPanier() 
{
	if (monPanier_->obtenirNombreContenu != 0)
		monPanier_->afficher();
	else
		"Le panier est vide";
}

/****************************************************************************
* Fonction: Client::livrePanier
* Description: livre le panier du client puis le d�truit
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}


