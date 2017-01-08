#include "Journee.h"

/**
	@brief Constructeur
*/
Journee::Journee(const vector<Cours*>& coursJournee) :
	d_coursJournee{coursJournee}
{
}

/**
	@brief Getter renvoyant un vecteur de pointeurs sur les Cours de la Journee
*/
vector<Cours*> Journee::getCoursJournee() const
{
	return d_coursJournee;
}

/**
	@brief Setter permettant de changer les Cours de la Journee
	@param coursJournee Vecteur de pointeurs sur les Cours de la Journee
*/
void Journee::setCoursJournee(const vector<Cours*>& coursJournee)
{
	d_coursJournee = coursJournee;
}

/**
	@brief Méthode pour ajouter un Cours à la Journee
	
	@param cours Pointeur sur un Cours
	@param creneau Entier du Creneau du cours
*/
void Journee::ajouterCours(Cours* cours, int creneau)
{
	d_coursJournee[creneau]=cours;
}

bool operator==(Journee journee, Journee autreJournee)
{
	int id;
	if (journee.getCoursJournee().size() != autreJournee.getCoursJournee().size())
		return false;
	for (id=0; id<journee.getCoursJournee().size() && journee.getCoursJournee()[id]==autreJournee.getCoursJournee()[id]; id++);
	if (id != journee.getCoursJournee().size())
		return false;
	return true;
}
