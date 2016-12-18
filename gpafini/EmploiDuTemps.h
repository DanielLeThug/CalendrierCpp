#pragma once


#include "Menu.h"
#include "Filiere.h"
#include "Professeur.h"
#include <fstream>
#include <string>

using std::string;
class EmploiDuTemps
{
	EmploiDuTemps();
	//void importerFichier(const string& fichier);
	//void exporterFichier(const string& fichier);
	
	bool estDansListeFiliere(Filiere* filiere, int& index) const;
	void ajouterFiliere(Filiere* filiere);
	bool estDansListeProfesseur(Professeur* professeur, int& index) const;
	void ajouterProfesseur(Professeur* professeur);
	Filiere* accederAFiliere(int index);
	
	
	void fenetrePrincipale();
	void loopFenetrePrincipale();
	
	void afficherCours();
	void menuCours();
	void menuFiliere();
	void menuProfesseur();
	void afficherListeFiliere();
	
	void modifierEmploiDuTempsFiliere(int choix );
	private :
	
		vector<Professeur*> d_listeProfs;
		vector<Filiere*> d_listeFiliere;
		
		
};
