#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Individu.h"

class Etudiant : public Individu
{
	public:
		Etudiant(const string& nom, const string& prenom, int numEtu);
		
		int getNumeroEtudiant() const;
		void setNumeroEtudiant(const int& numEtu);
		
	private:
		int d_numeroEtudiant;
};

#endif
