#include "Filiere.h"

Filiere::Filiere(const string& intitule, const vector<Etudiant*>& listeEtu) :
	d_intitule{intitule}, d_listeEtudiants{listeEtu}
{
}

string Filiere::getIntitule() const
{
	return d_intitule;
}
		
void Filiere::setIntitule(const string& intitule)
{
	d_intitule = intitule;
}
		
vector<Etudiant*> Filiere::getListeEtudiants() const
{
	return d_listeEtudiants;
}
		
void Filiere::setListeEtudiants(const vector<Etudiant*>& listeEtu)
{
	d_listeEtudiants = listeEtu;
}

Annee* Filiere::getAnnee()
{
	return d_annee;
}

Annee* Filiere::getAnnee() const
{
	return d_annee;
}
