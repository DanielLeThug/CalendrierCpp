#ifndef SEMAINE_H
#define SEMAINE_H

#include "Journee.h"
#include "vector"

using std::vector;

class Semaine
{
	public:
		Semaine(const vector<Journee*>& journeesSemaine);
		
		vector<Journee*> getJourneesSemaine() const;
		void setJourneesSemaine(const vector<Journee*>& journeesSemaine);
		
	private:
		vector<Journee*> d_journeesSemaine;
};

#endif
