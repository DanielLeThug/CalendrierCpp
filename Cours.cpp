#include "Cours.h"

Cours::Cours(const Filiere& fil, const Professeur& prof, const Salle& sal, int hor) :
	d_filiere{fil}, d_professeur{prof}, d_salle{sal}, d_horraire{hor}
{
}

Filiere Cours::getFiliere() const
{
	return d_filiere;
}

void Cours::setFiliere(const Filiere& fil)
{
	d_filiere = fil;
}

Professeur Cours::getProfesseur() const
{
	return d_professeur;
}

void Cours::setProfesseur(const Professeur& prof)
{
	d_professeur = prof;
}

Salle Cours::getSalle() const
{
	return d_salle;
}

void Cours::setSalle(const Salle& sal)
{
	d_salle = sal;
}

int Cours::getHorraire() const
{
	return d_horraire;
}

void Cours::setHorraire(const int& hor)
{
	d_horraire = hor;
}
