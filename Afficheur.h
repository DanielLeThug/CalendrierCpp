#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <vector>
#include <iostream>
#include "Semaine.h"

class Journee;

class Afficheur {
	public:
		virtual ~Afficheur();
		
		virtual void afficheSemaine(const Semaine& semaine) = 0;
	
};

#endif
