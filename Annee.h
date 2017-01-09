#ifndef ANNEE_H
#define ANNEE_H

#include "Semaine.h"
#include <vector>

using std::vector;
/**
	@class Annee
	@brief class repr�sentant une ann�e
*/
class Annee
{
	public:
		Annee(const vector<Semaine*>& semainesAnnee);
		Annee();
		vector<Semaine*> getSemainesAnnee() const;
		void setSemainesAnnee(const vector<Semaine*>& semainesAnnee);
		void addSemaine(Semaine* semaine, int numero);
	private:
		vector<Semaine*> d_semainesAnnee;
		
};

bool operator==(const Annee& annee, const Annee& autreAnnee);

#endif
