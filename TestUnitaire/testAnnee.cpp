#include "catch.hpp"
#include "../Annee.h"

TEST_CASE( "le constructeur de annee marche", "Annee")
{
	
	Annee annee();
	vector<Semaine*> semainesAnnee;
	vector<Journee*> journeesSemaine;
	vector<Cours*> coursJournee;
	
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			for (int k=0; k<10; k++)
			{
				coursJournee.push_back(new Cours(new Professeur("Bibine","Renée","Quidditch"), new Salle("F402", "6"), 21401196, 21401196));
			}
			//journeesSemaine.push_back(coursJournee);
			//coursJournee.erase();
		}
		semainesAnnee.push_back(journeeSemaine);
		journeesSemaine.erase();
	}

	annee.Annee(semainesAnnee);	
	REQUIRE(annee.getSemainesAnnee()==semainesAnnee);

}
/*
TEST_CASE( "les setters d'annee marchent", "Annee")
{
	Etudiant etudiant{"Belmondo","Paul",21401196}; 
	
	REQUIRE(etudiant.getNom() =="Belmondo");
	REQUIRE(etudiant.getPrenom() =="Paul");
	REQUIRE(etudiant.getNumeroEtudiant()==21401196 );
	
	SECTION("Changer le nom marche")
	{
		etudiant.setNom("Ventura");
		REQUIRE(etudiant.getNom()=="Ventura");
	}
	
	SECTION("Changer le prénom marche")
	{
		etudiant.setPrenom("Lino");
		REQUIRE(etudiant.getPrenom()=="Lino");
	}
	SECTION("Changer le numéro étudiant marche")
	{
		etudiant.setNumeroEtudiant(11111111);
		REQUIRE(etudiant.getNumeroEtudiant()==11111111);
	}
}*/
