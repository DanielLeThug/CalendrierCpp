#include "catch.hpp"
#include "../Annee.h"

TEST_CASE( "le constructeur de annee marche", "Annee")
{
	vector<Semaine*> semainesAnnee;
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
	for (int i=0; i<10; i++)
	{
		semainesAnnee.push_back(new Semaine(journeesSemaine));
	}
	Annee annee(semainesAnnee);	
	REQUIRE(annee.getSemainesAnnee()==semainesAnnee);
}


TEST_CASE( "les setters d'annee marchent", "Annee")
{
	vector<Semaine*> semainesAnnee;
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
	for (int i=0; i<10; i++)
	{
		semainesAnnee.push_back(new Semaine(journeesSemaine));
	}
	Annee annee(semainesAnnee);
	REQUIRE(annee.getSemainesAnnee()==semainesAnnee);
	
	SECTION("Changer la semaine marche")
	{
		vector<Semaine*> autreSemainesAnnee;
		vector<Journee*> autreJourneesSemaine;
		vector<Cours*> autreCoursJournee;
		
		for (int i=0; i<10; i++)
		{
			autreCoursJournee.push_back(new Cours(new Professeur("McGonagall","Minerva","Métamorphose"), new Salle("B600", "B"), 21401196, 21401196));
		}
		for (int i=0; i<10; i++)
		{
			autreJourneesSemaine.push_back(new Journee(autreCoursJournee));
		}
		for (int i=0; i<10; i++)
		{
			autreSemainesAnnee.push_back(new Semaine(autreJourneesSemaine));
		}
		annee.setSemainesAnnee(autreSemainesAnnee);
		REQUIRE(annee.getSemainesAnnee()==autreSemainesAnnee);
	}
	
	SECTION("Ajouter une semaine marche")
	{
		Semaine *ajoutSemaine;
		vector<Journee*> autreJourneesSemaine;
		vector<Cours*> autreCoursJournee;
		
		for (int i=0; i<10; i++)
		{
			autreCoursJournee.push_back(new Cours(new Professeur("McGonagall","Minerva","Métamorphose"), new Salle("B600", "B"), 21401196, 21401196));
		}
		for (int i=0; i<10; i++)
		{
			autreJourneesSemaine.push_back(new Journee(autreCoursJournee));
		}
		ajoutSemaine = new Semaine (autreJourneesSemaine);
		annee.addSemaine(ajoutSemaine, 0);
		REQUIRE(annee.getSemainesAnnee()[0]==ajoutSemaine);
	}

}
