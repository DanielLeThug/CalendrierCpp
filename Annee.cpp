#include "Annee.h"

const int NOMBRE_SEMAINE=52;
/**
	@brief Constructeur
	
	@param semainesAnnee tableau contenant les semaines de l'année
*/
Annee::Annee(const vector<Semaine*>& semainesAnnee) :
	d_semainesAnnee{semainesAnnee}
{
	
}
/**
	@brief Constructeur par défaut
*/
Annee::Annee() : d_semainesAnnee{}
{
	for(int i=0;i<NOMBRE_SEMAINE;i++)
	{
		d_semainesAnnee.push_back(new Semaine{});
	}
}
/**
	@brief Getter renvoyant le tableau des semaines
	
	
*/
vector<Semaine*> Annee::getSemainesAnnee() const
{
	return d_semainesAnnee;
}

/**
	@brief Setters permettant de remplacer le tableau
	
	@param semainesAnnee tableau contenant les semaines de l'année à mettre à la place du tableau actuel
*/
void Annee::setSemainesAnnee(const vector<Semaine*>& semainesAnnee)
{
	d_semainesAnnee = semainesAnnee;
}

/**
	@brief permet d'ajouter une semaine
	
	@param semaine pointeur sur la semaine à ajouter
	@param numero numero ( de 1 à 52 ) de la semaine à ajouter
*/
void Annee::addSemaine(Semaine* semaine, int numero)
{
	d_semainesAnnee[numero]=semaine;
}

bool operator==(const Annee& annee, const Annee& autreAnnee)
{
	int id;
	if (annee.getSemainesAnnee().size() != autreAnnee.getSemainesAnnee().size())
		return false;
	for (id=0; id<annee.getSemainesAnnee().size() && annee.getSemainesAnnee()[id]==autreAnnee.getSemainesAnnee()[id]; id++);
	if (id != annee.getSemainesAnnee().size())
		return false;
	return true;
}
