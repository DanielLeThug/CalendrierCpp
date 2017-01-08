#include "catch.hpp"
#include "../Cours.h"


TEST_CASE("Le constructeur de cours marche", "cours")
{
	Professeur professeur("Bibine","Renée","Quidditch"); 
	Salle salle("F402", "6");
	Cours cours(&professeur, &salle, 21401196, 21401196);
	REQUIRE(cours.getProfesseur()==professeur);
	REQUIRE(cours.getSalle()==salle);
	REQUIRE(cours.getHorraire()==21401196);	
	REQUIRE(cours.getDuree()==21401196);	
} 

TEST_CASE("Les setters de cours marchent", "cours")
{
	Professeur professeur("Bibine","Renée","Quidditch"); 
	Salle salle("F402", "6");
	Cours cours(&professeur, &salle, 21401196, 21401196);	REQUIRE(cours.getProfesseur()==professeur);
	REQUIRE(cours.getProfesseur()==professeur);
	REQUIRE(cours.getSalle()==salle);
	REQUIRE(cours.getHorraire()==21401196);	
	REQUIRE(cours.getDuree()==21401196);	
	SECTION("Changer le professeur marche")
	{
		Professeur professeurNouveau("McGonagall","Minerva","Métamorphose");
		cours.setProfesseur(&professeurNouveau);
		REQUIRE(cours.getProfesseur()==professeurNouveau);
	}
	
	SECTION("Changer la salle marche")
	{
		Salle nouvelleSalle("B600", "B");
		cours.setSalle(&nouvelleSalle);
		REQUIRE(cours.getSalle()==nouvelleSalle);	
	}
	SECTION("Changer l'horaire marche")
	{
		cours.setHorraire(11111111);
		REQUIRE(cours.getHorraire()==11111111);
	}
	SECTION("Changer la durée marche")
	{
		cours.setDuree(11111111);
		REQUIRE(cours.getDuree()==11111111);	
	}
} 
