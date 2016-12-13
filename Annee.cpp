#include "Annee.h"

Annee::Annee(const vector<Cours>& coursAnnee) :
	d_coursAnnee{coursAnnee}
{
}

vector<Cours> Annee::getCoursAnnee() const
{
	return d_coursAnnee;
}
		
void Annee::setCoursAnnee(const vector<Cours>& coursAnnee)
{
	d_coursAnnee = coursAnnee;
}
