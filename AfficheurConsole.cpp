#include "AfficheurConsole.h"

using std::endl;
using std::ostream;

void AfficheurConsole::afficheSemaine(const Semaine& semaine, ostream& ost)
{
	ost<<"### Emploi du temps de la semaine ###"<<endl;
	
	for(int i=0;i<semaine.getJourneesSemaine().size();i++)
	{
		ost<<"Jour n°"<<i<<endl;
		
		for(int j=0;j<semaine.getJourneesSemaine()[i]->getCoursJournee().size();j++)
		{
			if(semaine.getJourneesSemaine()[i]->getCoursJournee()[j])
			{
				ost<<semaine.getJourneesSemaine()[i]->getCoursJournee()[j]->getHorraire()<<"h : ";
				ost<<semaine.getJourneesSemaine()[i]->getCoursJournee()[j]->getProfesseur().getMatiereEnseignee();
				ost<<" - "<<semaine.getJourneesSemaine()[i]->getCoursJournee()[j]->getProfesseur().getNom()<<endl;
				ost<<"---En salle "<<semaine.getJourneesSemaine()[i]->getCoursJournee()[j]->getSalle().getNumeroSalle();
				ost<<" Batiment "<<semaine.getJourneesSemaine()[i]->getCoursJournee()[j]->getSalle().getBatiment()<<endl;
				ost<<"---Duree : "<<semaine.getJourneesSemaine()[i]->getCoursJournee()[j]->getDuree()<<"h"<<endl<<endl;
			}
			else
			{
				ost<<"---"<<endl;
				ost<<"---Creneau vide"<<endl;
				ost<<"---"<<endl<<endl;
			}
			
		}
	}
}

AfficheurConsole::~AfficheurConsole()
{
}
