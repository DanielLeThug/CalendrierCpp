#include "Semaine.h"
#include "Journee.h"

const int NOMBRE_JOUR=7;
/**
	@brief Constructeur
*/
Semaine::Semaine(const vector<Journee*>& journeesSemaine) :
	d_journeesSemaine{journeesSemaine}
{
}

/**
	@brief Constructeur par défaut
*/
Semaine::Semaine() : d_journeesSemaine{}
{
	for(int i=0;i<NOMBRE_JOUR;i++)
	{
		d_journeesSemaine.push_back(new Journee{});	
	}	
}

/**
	@brief Getter renvoyant un vecteur de pointeurs sur les Journee de la Semaine
*/
vector<Journee*> Semaine::getJourneesSemaine() const
{
	return d_journeesSemaine;
}

/**
	@brief Setter permettant de changer les Journee de la Semaine
	
	@param journeesSemaine Vecteur de pointeurs sur les Journee de la Semaine
*/
void Semaine::setJourneesSemaine(const vector<Journee*>& journeesSemaine)
{
	d_journeesSemaine = journeesSemaine;
}

/**
	@brief Méthode permettant d'ajouter une Journee à la Semaine
	
	@param journee Pointeur sur une Journee
	@param numero Entier du numero de la Journee dans la Semaine
*/
void Semaine::addJournee(Journee* journee, int numero)
{
	d_journeesSemaine[numero]=journee;
}

bool operator==(const Semaine& semaine, const Semaine& autreSemaine)
{
	int id;
	if (semaine.getJourneesSemaine().size() != autreSemaine.getJourneesSemaine().size())
		return false;
	for (id=0; id<semaine.getJourneesSemaine().size() && semaine.getJourneesSemaine()[id] == autreSemaine.getJourneesSemaine()[id]; id++);
	if (id != semaine.getJourneesSemaine().size())
		return false;
	return true;
}
