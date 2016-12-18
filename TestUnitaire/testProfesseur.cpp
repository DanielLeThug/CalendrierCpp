#include "catch.hpp"
#include "Professeur.h"

TEST_CASE( "le constructeur de professeur marche", "Professeur")
{
	Professeur professeur("Bibine","Renée","Quidditch"); 
	
	REQUIRE(professeur.getNom() =="Bibine");
	REQUIRE(professeur.getPrenom() =="Renée");
	REQUIRE(professeur.getMatiereEnseignee()=="Quidditch");
}

TEST_CASE( "les setters de professeur marchent", "Professeur")
{
	Professeur professeur("Bibine","Renée","Quidditch"); 
	
	REQUIRE(professeur.getNom() =="Bibine");
	REQUIRE(professeur.getPrenom() =="Renée");
	REQUIRE(professeur.getMatiereEnseignee()=="Quidditch");
	
	
	SECTION("Changer le nom marche")
	{
		professeur.setNom("McGonagall");
		REQUIRE(professeur.getNom()=="McGonagall");
	}
	
	SECTION("Changer le prénom marche")
	{
		professeur.setPrenom("Minerva");
		REQUIRE(professeur.getPrenom()=="Minerva");
	}
	SECTION("Changer le numéro étudiant marche")
	{
		professeur.setMatiereEnseignee("Métamorphose");
		REQUIRE(professeur.getMatiereEnseignee()=="Métamorphose");
	}
}


