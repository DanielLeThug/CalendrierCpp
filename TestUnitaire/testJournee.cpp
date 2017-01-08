#include "catch.hpp"
#include "../Journee.h"

TEST_CASE("Le constructeur de journee marche", "Journee")
{
	vector<Cours*> coursJournee;
	
	for (int i=0; i<10; i++)
	{
		coursJournee.push_back(new Cours(new Professeur("Bibine","Renée","Quidditch"), new Salle("F402", "6"), 21401196, 21401196));
	}
	
	Journee journee(coursJournee);
	REQUIRE(journee.getCoursJournee()==journee);
}


TEST_CASE("Les setter de journee marche", "Journee")
{
	vector<Cours*> coursJournee;
	
	for (int i=0; i<10; i++)
	{
		coursJournee.push_back(new Cours(new Professeur("Bibine","Renée","Quidditch"), new Salle("F402", "6"), 21401196, 21401196));
	}
	
	Journee journee(coursJournee);
	REQUIRE(journee.getCoursJournee()==journee);

	SECTION("Changer la journee marche")
	{
		vector<Cours*> autreCoursJournee;
		
		for (int i=0; i<10; i++)
		{
			autreCoursJournee.push_back(new Cours(new Professeur("McGonagall","Minerva","Métamorphose"), new Salle("B600", "B"), 21401196, 21401196));
		}
		journee.setCoursJournee(autreCoursJournee);
		REQUIRE(journee.getCoursJournee()==autreCoursJournee);
	}
	SECTION("Changer la journee marche")
	{
		Cours* autreCours = new Cours(new Professeur("McGonagall","Minerva","Métamorphose"), new Salle("B600", "B"), 21401196, 21401196);
		journee.ajouterCours(autreCours, 0);
		REQUIRE(journee.getCoursJournee()[0]==autreCours);
	}
}
