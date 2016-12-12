#include "Cours.h"

Cours::Cours()
{
}

Cours::Cours(Filiere fil, Professeur prof, Salle sal, int hor)
{
}

Filiere Cours::getFiliere() const
{
	return d_filiere;
}

Cours::setFiliere(const Filiere& fil)
{
	d_filiere = fil;
}

Professeur Cours::getProfesseur() const
{
	return d_professeur;
}

Cours::setProfesseur(const Professeur& prof)
{
	d_professeur = prof;
}

Salle Cours::getSalle() const
{
	return d_salle;
}

Cours::setSalle(const Salle& sal)
{
	d_salle = sal;
}

Horraire Cours::getHorraire() const
{
	return d_horraire;
}

Cours::setHorraire(const int& hor)
{
	d_horraire = hor;
}
