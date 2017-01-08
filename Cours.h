#ifndef COURS_H
#define COURS_H

#include "Salle.h"
#include "Professeur.h"


/**
	@class Cours
	
	@brief classe représentant un cours
*/
class Cours
{
	public:
		Cours(Professeur* prof,Salle* sal, int horaire, int duree=2);
		
		Professeur getProfesseur() const;
		void setProfesseur(Professeur* prof);
		Salle getSalle() const;
		void setSalle(Salle* sal);
		int getHorraire() const;
		void setHorraire(const int& horaire);
		int getDuree() const;
		void setDuree(const int& duree);		
	private:
		Professeur* d_professeur;
		Salle* d_salle;
		int d_horraireDebut;
		int d_duree;
};

bool operator==(const Cours& cours, const Cours& autreCours);

#endif
