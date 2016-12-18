#ifndef ANNEE_H
#define ANNEE_H

#include "Semaine.h"
#include <vector>

using std::vector;
class Semaine;
class Annee
{
	public:
		Annee(const vector<Semaine*>& semainesAnnee);
		
		vector<Semaine*> getSemainesAnnee() const;
		void setSemainesAnnee(const vector<Semaine*>& semainesAnnee);
		void addSemaine(Semaine* semaine, int numero);
	private:
		vector<Semaine*> d_semainesAnnee;
};

#endif
