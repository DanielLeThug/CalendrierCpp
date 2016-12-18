#ifndef SEMAINE_H
#define SEMAINE_H

#include "Journee.h"
#include "vector"

using std::vector;

class Journee;

class Semaine
{
	public:
		Semaine(const vector<Journee*>& journeesSemaine);
		
		vector<Journee*> getJourneesSemaine() const;
		void setJourneesSemaine(const vector<Journee*>& journeesSemaine);
		void addJournee(Journee*, int numeroJournee);
	private:
		vector<Journee*> d_journeesSemaine;
};

#endif
