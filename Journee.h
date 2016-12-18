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
		
		void ajouterCoursJournee(vector<Cours*>& coursJournee); //menu
		void ajouterCoursJournee(vector<Cours*>& coursJournee, Cours* ajoutCours, int horaire);
		void modifierCoursJournee(vector<Cours*>& coursJournee); //menu
		void supprimerCoursJournee(vector<Cours*>& coursJournee); //menu
		
		void supprimerCoursHoraire(vector<Cours*>& coursJournee, int horaire); 
		
		void deplacerCoursJournee(vector<Cours*>& coursJournee); //menu
		
	private:
		vector<Cours*> d_coursJournee;
};

#endif
