#ifndef FILIERE_H
#define FILIERE_H

#include <vector>
#include "Etudiant.h"
#include "Annee.h"

using std::vector;

class Filiere
{
    public:
        Filiere(const string& intitule, const vector<Etudiant*>& listeEtu);

        string getIntitule() const;
        void setIntitule(const string& intitule);
        vector<Etudiant*> getListeEtudiants() const;
        void setListeEtudiants(const vector<Etudiant*>& listeEtu);
        Annee* getAnnee();
        Annee* getAnnee() const;
    private:
        string d_intitule;
        vector<Etudiant*> d_listeEtudiants;
        Annee* d_annee;
};

#endif
