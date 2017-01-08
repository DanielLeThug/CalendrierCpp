#include "Salle.h"

/**
	@brief Constructeur
*/
Salle::Salle(const string& numSal, const string& bat) :
	d_numeroSalle{numSal}, d_batiment{bat}
{
}

/**
	@brief Getter renvoyant un string du numero de la salle
*/
string Salle::getNumeroSalle() const
{
	return d_numeroSalle;
}

/**
	@brief Setter permettant de changer le numero de la salle
	@param numSal String contenant le numero de la salle
*/
void Salle::setNumeroSalle(const string& numSal)
{
	d_numeroSalle = numSal;
}

/**
	@brief Getter renvoyant un string du batiment
*/
string Salle::getBatiment() const
{
	return d_batiment;
}

/**
	@brief Setter permettant de changer le batiment
	@param numSal String contenant le batiment
*/
void Salle::setBatiment(const string& bat)
{
	d_batiment = bat;
}

bool operator==(Salle salle, Salle secondeSalle)
{
	return (salle.getNumeroSalle() == secondeSalle.getNumeroSalle() && salle.getBatiment() ==  secondeSalle.getBatiment() ? true : false);
}
