#ifndef FILIERE_H
#define FILIERE_H

#include <vector>
#include "Etudiant.h"

using std::vector;

class Filiere
{
	public:
		Filiere(const string& intitule, const vector<Etudiant*>& listeEtu);
		
		string getIntitule() const;
		void setIntitule(const string& intitule);
		vector<Etudiant*> getListeEtudiants() const;
		void setListeEtudiants(const vector<Etudiant*>& listeEtu);
		
	private:
		string d_intitule;
		vector<Etudiant*> d_listeEtudiants;
};

#endif
