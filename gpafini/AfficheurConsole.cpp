#include "AfficheurConsole.h"
#include "Cours.cpp"
#include "Individu.cpp"
#include "Professeur.cpp"
#include "Salle.cpp"
#include "Afficheur.cpp"

using std::endl;
using std::ostream;

void AfficheurConsole::afficheSemaine(const vector<Journee*>& journeesSemaine, ostream& ost)
{
	ost<<"### Emploi du temps de la semaine ###"<<endl;
	
	for(int i=0;i<=5;i++)
	{
		ost<<"Jour n°"<<i<<endl;
		
		for(int j=0;j<=4;j++)
		{
			if(journeesSemaine[i]->getCoursJournee()[j])
			{
				ost<<journeesSemaine[i]->getCoursJournee()[j]->getHorraire()<<"h : ";
				ost<<journeesSemaine[i]->getCoursJournee()[j]->getProfesseur().getMatiereEnseignee();
				ost<<" - "<<journeesSemaine[i]->getCoursJournee()[j]->getProfesseur().getNom()<<endl;
				ost<<"---En salle "<<journeesSemaine[i]->getCoursJournee()[j]->getSalle().getNumeroSalle();
				ost<<" Batiment "<<journeesSemaine[i]->getCoursJournee()[j]->getSalle().getBatiment()<<endl;
				ost<<"---Duree : "<<journeesSemaine[i]->getCoursJournee()[j]->getDuree()<<"h"<<endl<<endl;
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

