#include "Cours.h"

/**
	@brief Constructeur
	
	@param prof pointeur sur le professeur donnant ce cours
	@param sal pointeur sur la salle ou a lieu le cours
	@param hor horaire de début
	@param duree durée du cours
*/
Cours::Cours(Professeur* prof,Salle* sal, int horaire, int duree) :
	d_professeur{prof}, d_salle{sal}, d_horraireDebut{horaire}, d_duree{duree}
{
}

/**
	@brief Getter renvoyant le professeur
	

*/
Professeur Cours::getProfesseur() const
{
	return *d_professeur;
}

/**
	@brief Setters permettant de changer le professeur du cours
	
	@param prof pointeur sur le nouveau prof
*/
void Cours::setProfesseur(Professeur* prof)
{
	d_professeur = prof;
}


/**
	@brief Getter renvoyant la salle
	
*/
Salle Cours::getSalle() const
{
	return *d_salle;
}

/**
	@brief Setters permettant de changer la salle
	
	@param sal pointeur sur la nouvelle salle
*/
void Cours::setSalle(Salle* sal)
{
	d_salle = sal;
}

/**
	@brief Getters renvoyant l'horaire de début
	
	
*/
int Cours::getHorraire() const
{
	return d_horraireDebut;
}

/**
	@brief Setters permettant de changer l'horaire de début
	
	@param hor nouvelle horaire de début
*/
void Cours::setHorraire(const int& horaire)
{
	d_horraireDebut = horaire;
}

/**
	@brief Getters renvoyant la durée
	
	
*/
int Cours::getDuree() const
{
	return d_duree;
}

/**
	@brief Setters permettant de changer la durée
	
	@param duree nouvelle duree
*/
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
