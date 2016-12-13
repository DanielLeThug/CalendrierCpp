#ifndef SEMAINE_H
#define SEMAINE_H

#include "Journee.h"
#include "vector"

using std::vector;

class Semaine
{
	public:
		Semaine(const vector<Cours>& coursSemaine);
		
		vector<Cours> getCoursSemaine() const;
		void setCoursSemaine(const vector<Cours>& coursSemaine);
		
	private:
		vector<Cours> d_coursSemaine;
};

#endif
