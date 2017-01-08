#ifndef SEMAINE_H
#define SEMAINE_H


#include <vector>
#include "Journee.h"

using std::vector;

class Semaine
{
    public:
        Semaine(const vector< Journee* >& journeesSemaine);

        vector<Journee*> getJourneesSemaine() const;
        void setJourneesSemaine(const vector<Journee*>& journeesSemaine);
        void addJournee(Journee*, int numeroJournee);
    private:
        vector<Journee* > d_journeesSemaine;
};

bool operator==(const Semaine& semaine, const Semaine& autreSemaine);

#endif
