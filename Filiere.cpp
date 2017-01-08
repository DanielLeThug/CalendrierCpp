#include "Filiere.h"


/**
	@brief Constructeur
	@param intitule Nom de la filière
	@param listeEtu liste des étudiants
*/
Filiere::Filiere(const string& intitule, const vector<Etudiant*>& listeEtu) :
	d_intitule{intitule}, d_listeEtudiants{listeEtu}
{
}

/**
	@brief Getter renvoyant le nom de la matière
*/
string Filiere::getIntitule() const
{
	return d_intitule;
}

/**
	@brief Setter permettant de changer la matière
	@param intitule nouveau nom
*/
void Filiere::setIntitule(const string& intitule)
{
	d_intitule = intitule;
}

/**
	@brief Getter renvoyant le nom de la matière
*/	
vector<Etudiant*> Filiere::getListeEtudiants() const
{
	return d_listeEtudiants;
}

/**
	@brief Setter permettant de changer la liste des étudiants
	@param listeEtu nouvelle liste
*/	
void Filiere::setListeEtudiants(const vector<Etudiant*>& listeEtu)
{
	d_listeEtudiants = listeEtu;
}

/**
	@brief Getter renvoyant la liste des étudiants
*/
Annee* Filiere::getAnnee()
{
	return d_annee;
}

/**
	@brief Getter renvoyant l'année scolaire de la filière et ne permettant pas de la changer
*/
Annee* Filiere::getAnnee() const
{
	return d_annee;
}
