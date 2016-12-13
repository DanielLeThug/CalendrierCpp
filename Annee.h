#ifndef ANNEE_H
#define ANNEE_H

#include "Semaine.h"
#include "vector"

using std::vector;

class Annee
{
	public:
		Annee(const vector<Cours>& coursAnnee);
		
		vector<Cours> getCoursAnnee() const;
		void setCoursAnnee(const vector<Cours>& coursAnnee);
		
	private:
		vector<Cours> d_coursAnnee;
};

#endif
