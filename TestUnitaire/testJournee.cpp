#include "catch.hpp"
#include "../Journee.h"

TEST_CASE("Le constructeur de journee marche", "Journee")
{
	Journee journee();
	vector<Cours*> coursJournee;
	
	for (int i=0; i<10; i++)
	{
		coursJournee.push_back(new Cours(new Professeur("Bibine","Renée","Quidditch"), new Salle("F402", "6"), 21401196, 21401196));
	}
	
	journee.Journee(coursJournee);
	REQUIRE(journee.getCoursJournee()==journee);
}
 
