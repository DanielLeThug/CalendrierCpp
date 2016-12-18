#include "Salle.h"

Salle::Salle(const string& numSal, const string& bat) :
	d_numeroSalle{numSal}, d_batiment{bat}
{
}

string Salle::getNumeroSalle() const
{
	return d_numeroSalle;
}

void Salle::setNumeroSalle(const string& numSal)
{
	d_numeroSalle = numSal;
}

string Salle::getBatiment() const
{
	return d_batiment;
}

void Salle::setBatiment(const string& bat)
{
	d_batiment = bat;
}
