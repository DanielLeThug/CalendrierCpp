#ifndef COURS_H
#define COURS_H

#include "Salle.h"
#include "Filiere.h"
#include "Professeur.h"

class Cours
{
	public:
		Cours(Filiere* fil,Professeur* prof,Salle* sal, int hor, int duree=2);
		
		Filiere getFiliere() const;
		void setFiliere(Filiere* fil);
		Professeur getProfesseur() const;
		void setProfesseur(Professeur* prof);
		Salle getSalle() const;
		void setSalle(Salle* sal);
		int getHorraire() const;
		void setHorraire(const int& hor);
		int getDuree() const;
		void setDuree(const int& duree);		
	private:
		Filiere* d_filiere;
		Professeur* d_professeur;
		Salle* d_salle;
		int d_horraireDebut;
		int d_duree;
};

#endif
