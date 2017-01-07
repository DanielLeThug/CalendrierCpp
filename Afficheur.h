#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <vector>
#include <iostream>
#include "Semaine.h"

const int NOMBREJOURNEESSEMAINE = 5;

const int NOMBRECOURSJOURNEE = 5;

class Journee;

class Afficheur {
	public:
		virtual ~Afficheur();
		
		virtual void afficheSemaine(const Semaine& semaine, std::ostream& ost) = 0;
	
};

#endif
