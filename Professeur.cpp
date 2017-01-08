#include "Professeur.h"
/**
	@brief Constructeur
*/
Professeur::Professeur(const string& nom, const string& prenom, const string& matEns) :
	Individu{nom, prenom}, d_matiereEnseignee{matEns}
{
}

/**
	@brief Getter renvoyant un string de la mati�re enseign�e
*/
string Professeur::getMatiereEnseignee() const
{
	return d_matiereEnseignee;
}

/**
	@brief Setter permettant de changer la mati�re enseign�e
	@param matEns R�f�rence sur un string contenant la mati�re enseign�e
*/
void Professeur::setMatiereEnseignee(const string& matEns)
{
	d_matiereEnseignee = matEns;
}

bool operator==(Professeur professeur, Professeur secondProfesseur) 
{
	return (professeur.getMatiereEnseignee() == secondProfesseur.getMatiereEnseignee() ? true : false);
}
