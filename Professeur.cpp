#include "Professeur.h"

Professeur::Professeur(const string& nom, const string& prenom, const string& matEns) :
	Individu{nom, prenom}, d_matiereEnseignee{matEns}
{
}

string Professeur::getMatiereEnseignee() const
{
	return d_matiereEnseignee;
}

void Professeur::setMatiereEnseignee(const string& matEns)
{
	d_matiereEnseignee = matEns;
}

bool operator==(Professeur professeur, Professeur secondProfesseur) 
{
	return (professeur.getMatiereEnseignee() == secondProfesseur.getMatiereEnseignee() ? true : false);
}
