#include "Etudiant.h"


/**
	@brief constructeur faisant appel au constructeur de Individu
	
	@param nom Nom de l'étudiant 
	@param prenom Prénom de l'étudiant
	@param numEtu numéro étudiant
*/
Etudiant::Etudiant(const string& nom, const string& prenom, int numEtu) :
	Individu{nom, prenom}, d_numeroEtudiant{numEtu}
{
}

/**
	@brief Getter renvoyant le numéro étudiant
	
	
*/
int Etudiant::getNumeroEtudiant() const
{
	return d_numeroEtudiant;
}

/**
	@brief Setter permettant de changer le numéro étudiant
	@param numEtu Nouveau numéro étudiant
	
*/
void Etudiant::setNumeroEtudiant(const int& numEtu)
{
	d_numeroEtudiant = numEtu;
}
