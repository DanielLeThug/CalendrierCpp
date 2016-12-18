#ifndef ANNEE_H
#define ANNEE_H

#include "Semaine.h"
#include "vector"

using std::vector;

class Annee
{
	public:
		Annee(const vector<Semaine*>& semainesAnnee);
		
		vector<Semaine*> getSemainesAnnee() const;
		void setSemainesAnnee(const vector<Semaine*>& semainesAnnee);
		
	private:
		vector<Semaine*> d_semainesAnnee;
};

#endif
