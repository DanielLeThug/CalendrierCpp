#include "catch.hpp"
#include "Filiere.h"
#include "Etudiant.h" 

TEST_CASE("Le constructeur de filiere marche", "filiere")
{	
	
	vector<Etudiant*> listeEtudiants{};
	for(int i=0;i<10;i++)
	{
		listeEtudiants.push_back(new Etudiant{"Jean", "Jean",21401196});
	}
	Filiere filiere("L2 Droit", listeEtudiants);
	REQUIRE(filiere.getIntitule()=="L2 Droit");
	REQUIRE(filiere.getListeEtudiants()==listeEtudiants);
}

TEST_CASE("Les setters de filiere marche", "filiere")
{	
	
	vector<Etudiant*> listeEtudiants{};
	for(int i=0;i<10;i++)
	{
		listeEtudiants.push_back(new Etudiant{"Jean", "Jean",21401196});
	}
	Filiere filiere("L2 Droit", listeEtudiants);
	REQUIRE(filiere.getIntitule()=="L2 Droit");
	REQUIRE(filiere.getListeEtudiants()==listeEtudiants);
	
	SECTION("Changer l'intitulé marche")
	{
		filiere.setIntitule("BTS Hydroponie");
		REQUIRE(filiere.getIntitule()=="BTS Hydroponie");
	}
	
	SECTION("Changer la liste des étudiants marche")
	{	
		
		for(int i=0;i<10;i++)
		{	
			delete listeEtudiants[i];
			listeEtudiants[i]=new Etudiant{"Roger", "Roger",214000};
		}
		filiere.setListeEtudiants(listeEtudiants);
		REQUIRE(filiere.getListeEtudiants()==listeEtudiants);
	}
}
