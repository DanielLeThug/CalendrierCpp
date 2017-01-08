#ifndef AFFICHEURCSV_H
#define AFFICHEURCSV_H
#include "Afficheur.h"
#include <fstream>

class AfficheurCSV : public Afficheur{
	public:
		~AfficheurCSV();
		virtual void afficheSemaine(const Semaine& semaine) const override;
		void afficheJour(const Journee* jour) const;
		void afficheCours(const Cours* cours, std::ofstream& fichier) const;	
};

#endif
