#ifndef COURS_H
#define COURS_H

#include "Salle.h"
#include "Filiere.h"
#include "Professeur.h"

class Cours
{
	public:
		Cours(const Filiere& fil, const Professeur& prof, const Salle& sal, int hor);
		
		Filiere getFiliere() const;
		void setFiliere(const Filiere& fil);
		Professeur getProfesseur() const;
		void setProfesseur(const Professeur& prof);
		Salle getSalle() const;
		void setSalle(const Salle& sal);
		int getHorraire() const;
		void setHorraire(const int& hor);
				
	private:
		Filiere d_filiere;
		Professeur d_professeur;
		Salle d_salle;
		int d_horraire;
};

#endif
