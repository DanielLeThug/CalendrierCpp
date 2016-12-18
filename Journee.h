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
		
	private:
		vector<Cours*> d_coursJournee;
};

#endif
