#ifndef AFFICHEURCSV_H
#define AFFICHEURCSV_H
#include "Afficheur.h"


class AfficheurCSV : public Afficheur{
	public:
		~AfficheurCSV();
		virtual void afficheSemaine(const Semaine& semaine) override;
			
};

#endif
