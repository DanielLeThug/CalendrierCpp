#ifndef AFFICHEURCONSOLE_H
#define AFFICHEURCONSOLE_H
#include "Afficheur.h"

class AfficheurConsole : public Afficheur{
	public:
		~AfficheurConsole();
		virtual void afficheSemaine(const Semaine& semaine) override;
		void afficheJour(const Journee* jour);
		void afficheCours(const Cours* cours);
			
};

#endif
