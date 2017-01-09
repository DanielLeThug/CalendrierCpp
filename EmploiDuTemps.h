#pragma once


//#include "Menu.h"
#include "Salle.h"
#include "Filiere.h"
#include "Professeur.h"
#include <fstream>
#include <string>
#include "AfficheurConsole.h"
#include "AfficheurCSV.h"

using std::string;

class EmploiDuTemps
{
	public:
	EmploiDuTemps();
	//void importerFichier(const string& fichier);
	//void exporterFichier(const string& fichier);
	
	bool estDansListeFiliere(Filiere* filiere, int& index) const;
	void ajouterFiliere(Filiere* filiere);
	bool estDansListeProfesseur(Professeur* professeur, int& index) const;
	void ajouterProfesseur(Professeur* professeur);
	Filiere* accederAFiliere(int index);
	bool filiereExisteDeja(const string& intitule);
	
	void fenetrePrincipale();
	void loopFenetrePrincipale();
	
	void afficherCours();
	void afficherSemaine(const Semaine* semaine);
	void afficherSemaineCSV(const Semaine* semaine);
	void afficherJour(const Journee* jour) const;
	void afficherListeFiliere();
	void afficherListeSalle() const;
	void afficherListeProfesseur() const;
	
	void menuCours();
	void menuFiliere();
	void menuProfesseur();
	
	void menuAjoutCours(int filiereChoisi, int semaineChoisi, int jourChoisi);
	void menuModiferCours(int filiereChoisi, int semaineChoisi, int jourChoisi);
	void menuSupprimerCours(int filiereChoisi, int semaineChoisi, int jourChoisi);

	Etudiant* menuAjoutEtudiant();
	void menuAjoutFiliere();
	void menuModiferFiliere(const int& filiereChoisie);
	void menuSupprimerFiliere(const int& filiereChoisie);

	void menuAjoutProfesseur();
	void menuModiferProfesseur(const int& choixProfesseur);
	void menuSupprimerProfesseur(const int& choixProfesseur);
	
	int choixFiliere();
	int choixProfesseur();
	
	vector<Salle*> getListeSalle() const;
	vector<Professeur*> getListeProfesseur() const;
	vector<Filiere*> getListeFiliere() const;
	
	void ajouterCours(Journee* journeeAModifier, int crenau);
	void modifierCours(Cours* coursAModifier);
	void supprimerCours(Cours* coursASupprimer);
	void modifierEmploiDuTempsFiliere(int choix );
	private :
		vector<Salle* > d_listeSalle;
		vector<Professeur*> d_listeProfs;
		vector<Filiere*> d_listeFiliere;
		AfficheurConsole d_afficheur;

};
