#include "catch.hpp"
#include "Professeur.h"

TEST_CASE( "le constructeur de professeur marche", "Professeur")
{
	Professeur professeur("Bibine","Ren�e","Quidditch"); 
	
	REQUIRE(professeur.getNom() =="Bibine");
	REQUIRE(professeur.getPrenom() =="Ren�e");
	REQUIRE(professeur.getMatiereEnseignee()=="Quidditch");
}

TEST_CASE( "les setters de professeur marchent", "Professeur")
{
	Professeur professeur("Bibine","Ren�e","Quidditch"); 
	
	REQUIRE(professeur.getNom() =="Bibine");
	REQUIRE(professeur.getPrenom() =="Ren�e");
	REQUIRE(professeur.getMatiereEnseignee()=="Quidditch");
	
	
	SECTION("Changer le nom marche")
	{
		professeur.setNom("McGonagall");
		REQUIRE(professeur.getNom()=="McGonagall");
	}
	
	SECTION("Changer le pr�nom marche")
	{
		professeur.setPrenom("Minerva");
		REQUIRE(professeur.getPrenom()=="Minerva");
	}
	SECTION("Changer le num�ro �tudiant marche")
	{
		professeur.setMatiereEnseignee("M�tamorphose");
		REQUIRE(professeur.getMatiereEnseignee()=="M�tamorphose");
	}
}


