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

bool operator==(Journee journee, Journee autreJournee)
{
    int id;
    if (journee.getCoursJournee().size() != autreJournee.getCoursJournee().size())
        return false;
    for (id=0; id<journee.getCoursJournee().size() && journee.getCoursJournee()[id]==autreJournee.getCoursJournee()[id]; id++);
    if (id != journee.getCoursJournee().size())
        return false;
    return true;
}
