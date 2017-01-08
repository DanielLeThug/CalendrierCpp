#ifndef AFFICHEURCONSOLE_H
#define AFFICHEURCONSOLE_H
#include "Afficheur.h"

/**
	@class AfficheurConsole
	@brief Classe héritée de la classe Afficheur pour l'affichage dans la console
*/
class AfficheurConsole : public Afficheur{
	public:
		~AfficheurConsole();
		virtual void afficheSemaine(const Semaine& semaine) const override;
		void afficheJour(const Journee* jour) const;
		void afficheCours(const Cours* cours) const;
			
};

#endif
