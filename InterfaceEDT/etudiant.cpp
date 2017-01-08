#include "Etudiant.h"

Etudiant::Etudiant(const string& nom, const string& prenom, int numEtu) :
    Individu{nom, prenom}, d_numeroEtudiant{numEtu}
{
}

int Etudiant::getNumeroEtudiant() const
{
    return d_numeroEtudiant;
}

void Etudiant::setNumeroEtudiant(const int& numEtu)
{
    d_numeroEtudiant = numEtu;
}
