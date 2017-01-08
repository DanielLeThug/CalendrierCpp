#include "catch.hpp"
#include "../Etudiant.h"

TEST_CASE( "le constructeur de étudiant marche", "Etudiant")
{
	Etudiant etudiant{"Belmondo","Paul",21401196}; 
	
	REQUIRE(etudiant.getNom() =="Belmondo");
	REQUIRE(etudiant.getPrenom() =="Paul");
	REQUIRE(etudiant.getNumeroEtudiant()==21401196 );
}

TEST_CASE( "les setters d'etudiant marchent", "Etudiant")
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
}


