#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <vector>
#include <iostream>
#include "Journee.cpp"

class Journee;

class Afficheur {
	public:
		virtual ~Afficheur();
		
		virtual void afficheSemaine(const std::vector<Journee*>& journeesSemaine, std::ostream& ost) = 0;
	
};

#endif
