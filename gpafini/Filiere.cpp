#include "Filiere.h"

Filiere::Filiere(const string& intitule, const vector<Etudiant*>& listeEtu,Annee* annee) :
	d_intitule{intitule}, d_listeEtudiants{listeEtu}, d_annee{annee}
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
