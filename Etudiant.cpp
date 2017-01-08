#include "Etudiant.h"


/**
	@brief constructeur faisant appel au constructeur de Individu
	
	@param nom Nom de l'�tudiant 
	@param prenom Pr�nom de l'�tudiant
	@param numEtu num�ro �tudiant
*/
Etudiant::Etudiant(const string& nom, const string& prenom, int numEtu) :
	Individu{nom, prenom}, d_numeroEtudiant{numEtu}
{
}

/**
	@brief Getter renvoyant le num�ro �tudiant
	
	
*/
int Etudiant::getNumeroEtudiant() const
{
	return d_numeroEtudiant;
}

/**
	@brief Setter permettant de changer le num�ro �tudiant
	@param numEtu Nouveau num�ro �tudiant
	
*/
void Etudiant::setNumeroEtudiant(const int& numEtu)
{
	d_numeroEtudiant = numEtu;
}
