#ifndef AFFICHEURCONSOLE_H
#define AFFICHEURCONSOLE_H
#include "Afficheur.h"

class AfficheurConsole : public Afficheur{
	public:
		~AfficheurConsole();
		virtual void afficheSemaine(const std::vector<Journee*>& journeesSemaines, std::ostream& ost) override;
			
};

#endif
