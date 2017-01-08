#include "Filiere.h"

Filiere::Filiere(const string& intitule, const vector<Etudiant*>& listeEtu) :
    d_intitule{intitule}, d_listeEtudiants{listeEtu}
{
    vector<Semaine*> semainesAnnee;
    vector<Journee*> journeesSemaine;
    for (int j=0; j < 7; j++) {
        journeesSemaine.push_back(nullptr);
    }
    for (int i=1; i <= 52; i++) {
        semainesAnnee.push_back(new Semaine(journeesSemaine));
    }
    d_annee = new Annee(semainesAnnee);
}

string Filiere::getIntitule() const
{
    return d_intitule;
}

void Filiere::setIntitule(const string& intitule)
{
    d_intitule = intitule;
}

vector<Etudiant*> Filiere::getListeEtudiants() const
{
    return d_listeEtudiants;
}

void Filiere::setListeEtudiants(const vector<Etudiant*>& listeEtu)
{
    d_listeEtudiants = listeEtu;
}

Annee* Filiere::getAnnee()
{
    return d_annee;
}

Annee* Filiere::getAnnee() const
{
    return d_annee;
}
