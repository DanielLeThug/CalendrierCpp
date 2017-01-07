#include "Journee.h"

Journee::Journee(const vector<Cours*>& coursJournee) :
	d_coursJournee{coursJournee}
{
}

vector<Cours*> Journee::getCoursJournee() const
{
	return d_coursJournee;
}
		
void Journee::setCoursJournee(const vector<Cours*>& coursJournee)
{
	d_coursJournee = coursJournee;
}

void Journee::ajouterCours(Cours* cours, int crenau)
{
	d_coursJournee[crenau]=cours;
}
