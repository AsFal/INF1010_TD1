#include "client.h"
#include "panier.h"
#include <iostream>

using namespace std;

Client::Client() 
{
	nom_ = "";
	prenom_ = "";
	identifiant_ = 0;
	codePostal_ = "";
	dateNaissance_ = 0;
	monPanier_ = nullptr;

}

Client::Client(string nom, string prenom, int identifiant, string codePostal, long date): nom_(nom),
prenom_(prenom), codePostal_(codePostal_)
{
	identifiant_ = identifiant;
	dateNaissance_ = date;
	monPanier_ = nullptr;

}

string Client::obtenirNom()
{
	return nom_;
}

string Client::obtenirPrenom()
{
	return prenom_;
}

int Client::obtenirIdentifiant()
{
	return identifiant_;
}

string Client::obtenirCodePostal()
{
	return codePostal_;
}

long Client::obtenirDateNaissance()
{
	return dateNaissance_;
}

void Client::modifierNom(string nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(4);
	monPanier_->ajouter(prod);
}

void Client::afficherPanier() 
{
	if (monPanier_->obtenirNombreContenu != 0)
		monPanier_->afficher();
	else
		"Le panier est vide";
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}

