#include "Cours.h"

Cours::Cours(Professeur* prof,Salle* sal, int hor, int duree) :
	d_professeur{prof}, d_salle{sal}, d_horraireDebut{hor}, d_duree{duree}
{
}

Professeur Cours::getProfesseur() const
{
	return *d_professeur;
}

void Cours::setProfesseur(Professeur* prof)
{
	d_professeur = prof;
}

Salle Cours::getSalle() const
{
	return *d_salle;
}

void Cours::setSalle(Salle* sal)
{
	d_salle = sal;
}

int Cours::getHorraire() const
{
	return d_horraireDebut;
}

void Cours::setHorraire(const int& hor)
{
	d_horraireDebut = hor;
}

int Cours::getDuree() const
{
	return d_duree;
}

void Cours::setDuree(const int& duree) 
{
	d_duree=duree;
}

bool operator==(const Cours& cours, const Cours& autreCours)
{
	if (cours.getDuree() == autreCours.getDuree() && cours.getHorraire() == autreCours.getHorraire()
		&& cours.getProfesseur() == autreCours.getProfesseur() && cours.getSalle() == autreCours.getSalle())
		return true;
	return false;
}
