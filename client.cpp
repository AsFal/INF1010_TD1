/****************************************************************************
* Fichier: client.cpp
* Auteurs: Alexandre Falardeau et Hugo Leclair
* Date: 26 janvier 2018
* Mise a jour : 11 mai 2011
* Description: Description des méthodes de la classe client.cpp
****************************************************************************/
#include "client.h"
#include "panier.h"
#include <iostream>

using namespace std;

/****************************************************************************
* Fonction: Client::Client
* Description: Constructeur par défaut
* Paramètres: aucun
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
* Description: Constructeur par paramètres
* Paramètres: -(string) nom : le nom du client
*			  -(string) prénom : le prénom du client
*			  -(int) identifiant : le numéro d'indentification du client
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
* Paramètres: aucun
* Retour: (string) la valeur de nom_
****************************************************************************/
string Client::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction: Client::obtenirPrenom
* Description: Retourne prenom_
* Paramètres: aucun
* Retour: (string) la valeur de prenom_
****************************************************************************/
string Client::obtenirPrenom() const
{
	return prenom_;
}

/****************************************************************************
* Fonction: Client::obtenirIdentifiant
* Description: Retourne identifiant_
* Paramètres: aucun
* Retour: (int) la valeur de identifiant_
****************************************************************************/
int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

/****************************************************************************
* Fonction: Client::obtenirCodePostal
* Description: Retourne codePostal_
* Paramètres: aucun
* Retour: (string) la valeur de codePostal_
****************************************************************************/
string Client::obtenirCodePostal() const
{
	return codePostal_;
}

/****************************************************************************
* Fonction: Client::obtenirDateNaissance
* Description: Retourne dateNaissance_
* Paramètres: aucun
* Retour: (long) la valeur de dateNaissance_
****************************************************************************/
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

/****************************************************************************
* Fonction: Client::modifierNom
* Description: Affecte la valeur du paramètre nom à l'attribut nom_
* Paramètres: -(string) nom: le nom du client
* Retour: aucun
****************************************************************************/
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction: Client::modifierPrenom
* Description: Affecte la valeur du paramètre prenom à l'attribut prenom_
* Paramètres: -(string) prenom: le nom du client
* Retour: aucun
****************************************************************************/
void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

/****************************************************************************
* Fonction: Client::modifierIdentifiant
* Description: Affecte la valeur du paramètre identifiant à l'attribut identifiant_
* Paramètres: -(int) identifiant: le identifiant du client
* Retour: aucun
****************************************************************************/
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

/****************************************************************************
* Fonction: Client::modifierCodePostal
* Description: Affecte la valeur du paramètre codePostal à l'attribut codePostal_
* Paramètres: -(string) codePostal: le code postal du client
* Retour: aucun
****************************************************************************/
void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

/****************************************************************************
* Fonction: Client::modifierDateNaissance
* Description: Affecte la valeur du paramètre date à l'attribut dateNaissance_
* Paramètres: -(int) nom: la date naissance du client
* Retour: aucun
****************************************************************************/
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

/****************************************************************************
* Fonction: Client::acheter
* Description: Acheter un produit en l'ajoutant au panier pointé par le client
* Paramètres: -(Produit *) prod: Le produit à être ajouté au panier
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
* Paramètres:aucun
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
* Description: livre le panier du client puis le détruit
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}


