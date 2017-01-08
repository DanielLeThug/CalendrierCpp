#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <vector>
#include <iostream>
#include "Semaine.h"

class Journee;

/**
	@class Afficheur
	@brief Classe abstraite des différents afficheurs
*/
class Afficheur {
	public:
		virtual ~Afficheur();
		
		virtual void afficheSemaine(const Semaine& semaine) const = 0;
	
};

#endif
