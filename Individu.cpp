#include "Individu.h"

/**
	@brief Constructeur
	@param nom Nom de l'individu
	@param prenom de l'individu
*/
Individu::Individu(const string& nom, const string& prenom) :
	d_nom{nom}, d_prenom{prenom}
{
}

/**
	@brief Getter renvoyant le nom de l'individu
*/
string Individu::getNom() const
{
	return d_nom;
}

/**
	@brief Setter permettant de changer le nom de l'individu
	@param nom nouveau nom
*/	
void Individu::setNom(const string& nom)
{
	d_nom = nom;
}

/**
	@brief Getter renvoyant le prenom de l'individu
*/		
string Individu::getPrenom() const
{
	return d_prenom;
}

/**
	@brief Setter permettant de changer le prenom de l'individu
	@param prenom nouveau prenom
*/			
void Individu::setPrenom(const string& prenom)
{
	d_prenom = prenom;
}
