#include "catch.hpp"
#include "Individu.h"

TEST_CASE ("Le constructeur de Individu marche", "Individu")
{
	Individu individu {"Jaures", "Jean"};
	
	REQUIRE(individu.getNom() =="Jaures");
	REQUIRE(individu.getPrenom() =="Jean");
}

TEST_CASE("Les setters d'individu marchent", "Individu")
{
	Individu individu{"Jaures", "Jean"};
	
	REQUIRE(individu.getNom() =="Jaures");
	REQUIRE(individu.getPrenom() =="Jean");
	
	SECTION(" Changer le nom marche ")
	{
		individu.setNom("Francois");
		REQUIRE(individu.getNom() =="Francois");
	}
	SECTION("Changer le prénom marche ")
	{
		individu.setPrenom("Claude");
		REQUIRE(individu.getPrenom()=="Claude");
	}
}
