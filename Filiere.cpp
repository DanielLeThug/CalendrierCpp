#include "Filiere.h"


/**
	@brief Constructeur
	@param intitule Nom de la fili�re
	@param listeEtu liste des �tudiants
*/
Filiere::Filiere(const string& intitule, const vector<Etudiant*>& listeEtu) :
	d_intitule{intitule}, d_listeEtudiants{listeEtu}
{
}

/**
	@brief Getter renvoyant le nom de la mati�re
*/
string Filiere::getIntitule() const
{
	return d_intitule;
}

/**
	@brief Setter permettant de changer la mati�re
	@param intitule nouveau nom
*/
void Filiere::setIntitule(const string& intitule)
{
	d_intitule = intitule;
}

/**
	@brief Getter renvoyant le nom de la mati�re
*/	
vector<Etudiant*> Filiere::getListeEtudiants() const
{
	return d_listeEtudiants;
}

/**
	@brief Setter permettant de changer la liste des �tudiants
	@param listeEtu nouvelle liste
*/	
void Filiere::setListeEtudiants(const vector<Etudiant*>& listeEtu)
{
	d_listeEtudiants = listeEtu;
}

/**
	@brief Getter renvoyant la liste des �tudiants
*/
Annee* Filiere::getAnnee()
{
	return d_annee;
}

/**
	@brief Getter renvoyant l'ann�e scolaire de la fili�re et ne permettant pas de la changer
*/
Annee* Filiere::getAnnee() const
{
	return d_annee;
}
