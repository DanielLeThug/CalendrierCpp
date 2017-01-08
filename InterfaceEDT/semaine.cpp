#include "Semaine.h"
#include "Journee.h"

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

bool operator==(const Semaine& semaine, const Semaine& autreSemaine)
{
    int id;
    if (semaine.getJourneesSemaine().size() != autreSemaine.getJourneesSemaine().size())
        return false;
    for (id=0; id<semaine.getJourneesSemaine().size() && semaine.getJourneesSemaine()[id] == autreSemaine.getJourneesSemaine()[id]; id++);
    if (id != semaine.getJourneesSemaine().size())
        return false;
    return true;
}
