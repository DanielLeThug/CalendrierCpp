#include "catch.hpp"
#include "Salle.h"

TEST_CASE("Le constructeur de salle marche", "salle")
{
	Salle salle("F402", "6");
	REQUIRE(salle.getNumeroSalle()=="F402");
	REQUIRE(salle.getBatiment()=="6");	
} 

TEST_CASE("Les setters de salle marchent", "salle")
{
	Salle salle("F402", "6");
	REQUIRE(salle.getNumeroSalle()=="F402");
	REQUIRE(salle.getBatiment()=="6");	
	
	SECTION("Changer le numéro de salle marche")
	{
		salle.setNumeroSalle("B600");
		REQUIRE(salle.getNumeroSalle()=="B600");
	}
	
		SECTION("Changer le batiment marche")
	{
		salle.setBatiment("B");
		REQUIRE(salle.getBatiment()=="B");
	}
	
} 
