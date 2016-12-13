#include "Semaine.h"

Semaine::Semaine(const vector<Cours>& coursSemaine) :
	d_coursSemaine{coursSemaine}
{
}

vector<Cours> Semaine::getCoursSemaine() const
{
	return d_coursSemaine;
}
		
void Semaine::setCoursSemaine(const vector<Cours>& coursSemaine)
{
	d_coursSemaine = coursSemaine;
}
