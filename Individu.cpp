#include "Individu.h"

Individu::Individu(const string& nom, const string& prenom) :
	d_nom{nom}, d_prenom{prenom}
{
}

string Individu::getNom() const
{
	return d_nom;
}
		
void Individu::setNom(const string& nom)
{
	d_nom = nom;
}
		
string Individu::getPrenom() const
{
	return d_prenom;
}
		
void Individu::setPrenom(const string& prenom)
{
	d_prenom = prenom;
}
