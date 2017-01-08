#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "Individu.h"

class Professeur : public Individu
{
	public:
		Professeur(const string& nom, const string& prenom, const string& matEns);
		
		string getMatiereEnseignee() const;
		void setMatiereEnseignee(const string& matEns);
		
	private:
		string d_matiereEnseignee;
};

bool operator==(Professeur professeur, Professeur secondProfesseur);

#endif
