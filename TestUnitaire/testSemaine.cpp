#include "catch.hpp"
#include "../Semaine.h"

TEST_CASE("Le constructeur de Semaine marche", "Semaine")
{
	vector<Journee*> journeesSemaine;
	vector<Cours*> coursJournee;
	
	for (int i=0; i<10; i++)
	{
		coursJournee.push_back(new Cours(new Professeur("Bibine","Renée","Quidditch"), new Salle("F402", "6"), 21401196, 21401196));
	}
	for (int i=0; i<10; i++)
	{
		journeesSemaine.push_back(new Journee(coursJournee));
	}
	
	Semaine semaine(journeesSemaine);
	REQUIRE(semaine.getJourneesSemaine()==journeesSemaine);
}

TEST_CASE("Les setter de Semaine marche", "Semaine")
{
	vector<Journee*> journeesSemaine;
	vector<Cours*> coursJournee;
	
	for (int i=0; i<10; i++)
	{
		coursJournee.push_back(new Cours(new Professeur("Bibine","Renée","Quidditch"), new Salle("F402", "6"), 21401196, 21401196));
	}
	for (int i=0; i<10; i++)
	{
		journeesSemaine.push_back(new Journee(coursJournee));
	}
	
	Semaine semaine(journeesSemaine);
	REQUIRE(semaine.getJourneesSemaine()==journeesSemaine);

	SECTION("Changer la semaine marche")
	{
		vector<Journee*> autreJourneesSemaine;
		vector<Cours*> autreCoursJournee;
		
		for (int i=0; i<10; i++)
		{
			autreCoursJournee.push_back(new Cours(new Professeur("McGonagall","Minerva","Métamorphose"), new Salle("B600", "B"), 1111111, 1111111));
		}
		for (int i=0; i<10; i++)
		{
			autreJourneesSemaine.push_back(new Journee(autreCoursJournee));
		}
		semaine.setJourneesSemaine(autreJourneesSemaine);
		REQUIRE(semaine.getJourneesSemaine()==autreJourneesSemaine);
	}
	SECTION("Ajouter une semaine marche")
	{
		Journee* autreJourneeSemaine;
		vector<Cours*> autreCoursJournee;
		
		for (int i=0; i<10; i++)
		{
			autreCoursJournee.push_back(new Cours(new Professeur("McGonagall","Minerva","Métamorphose"), new Salle("B600", "B"), 1111111, 1111111));
		}
		autreJourneeSemaine = new Journee(autreCoursJournee);
		semaine.addJournee(autreJourneeSemaine, 0);
		REQUIRE(semaine.getJourneesSemaine()[0]==autreJourneeSemaine);
	}
}

