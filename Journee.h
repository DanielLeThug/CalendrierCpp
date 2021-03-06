#ifndef JOURNEE_H
#define JOURNEE_H

#include "Cours.h"
#include "vector"

using std::vector;

/**
	@class Journee
	@brief Classe Journee contenant un vecteur de pointeurs sur des Cours
*/
class Journee
{
	public:
		Journee(const vector<Cours*>& coursJournee);
		Journee();
		vector<Cours*> getCoursJournee() const;
		void setCoursJournee(const vector<Cours*>& coursJournee);
		void ajouterCours(Cours* cours, int crenau);
	private:
		vector<Cours*> d_coursJournee;
};

bool operator==(Journee journee, Journee autreJournee);

#endif
