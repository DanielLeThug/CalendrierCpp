#include "Annee.h"

Annee::Annee(const vector<Semaine*>& semainesAnnee) :
	d_semainesAnnee{semainesAnnee}
{
}

vector<Semaine*> Annee::getSemainesAnnee() const
{
	return d_semainesAnnee;
}
		
void Annee::setSemainesAnnee(const vector<Semaine*>& semainesAnnee)
{
	d_semainesAnnee = semainesAnnee;
}

void Annee::addSemaine(Semaine* semaine, int numero)
{
	d_semainesAnnee[numero]=semaine;
}
