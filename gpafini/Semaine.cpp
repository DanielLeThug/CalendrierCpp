#include "Semaine.h"

Semaine::Semaine(const vector<Journee*>& journeesSemaine) :
	d_journeesSemaine{journeesSemaine}
{
}

vector<Journee*> Semaine::getJourneesSemaine() const
{
	return d_journeesSemaine;
}
		
void Semaine::setJourneesSemaine(const vector<Journee*>& journeesSemaine)
{
	d_journeesSemaine = journeesSemaine;
}

void Semaine::addJournee(Journee* journee, int numero)
{
	d_journeesSemaine[numero]=journee;
}
