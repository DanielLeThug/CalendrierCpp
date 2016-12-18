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
