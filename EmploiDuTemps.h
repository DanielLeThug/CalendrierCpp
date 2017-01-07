#pragma once


//#include "Menu.h"
#include "Salle.h"
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
	void afficherSemaine();
	void afficherJour();
	void menuCours();
	void menuFiliere();
	void menuProfesseur();
	void afficherListeFiliere();
	void afficherListeSalle() const;
	void afficherListeProfesseur() const;
	int choixFiliere();
	void menuAjout(int filiereChoisi, int semaineChoisi, int jourChoisi);
	void menuModifer(int filiereChoisi, int semaineChoisi, int jourChoisi);
	void menuDeplacer();
	void menuSupprimer(int filiereChoisi, int semaineChoisi, int jourChoisi);
	
	void ajouterCours(Journee* journeeAModifier, int crenau);
	void modifierEmploiDuTempsFiliere(int choix );
	private :
		vector<Salle* > d_listeSalle;
		vector<Professeur*> d_listeProfs;
		vector<Filiere*> d_listeFiliere;
		
		
};
