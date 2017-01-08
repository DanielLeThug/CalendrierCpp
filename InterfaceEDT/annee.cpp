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

bool operator==(const Annee& annee, const Annee& autreAnnee)
{
    int id;
    if (annee.getSemainesAnnee().size() != autreAnnee.getSemainesAnnee().size())
        return false;
    for (id=0; id<annee.getSemainesAnnee().size() && annee.getSemainesAnnee()[id]==autreAnnee.getSemainesAnnee()[id]; id++);
    if (id != annee.getSemainesAnnee().size())
        return false;
    return true;
}
