#ifndef JOURNEE_H
#define JOURNEE_H

#include "Cours.h"
#include "vector"

using std::vector;

class Journee
{
	public:
		Journee(const vector<Cours*>& coursJournee);
		
		vector<Cours*> getCoursJournee() const;
		void setCoursJournee(const vector<Cours*>& coursJournee);
		void ajouterCours(Cours* cours, int crenau);
	private:
		vector<Cours*> d_coursJournee;
};

bool operator==(Journee journee, Journee autreJournee);

#endif
