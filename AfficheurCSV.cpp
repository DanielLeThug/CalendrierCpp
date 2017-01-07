#include "AfficheurCSV.h"
#include <fstream>
#include <string>

using std::endl;
using std::ofstream;

const string SEPARATEUR = "##########,##########,##########,##########,##########";

void AfficheurCSV::afficheSemaine(const Semaine& semaine, std::ostream& ost)
{
	ofstream fichier("EmploiDuTemps.csv",std::ios::out | std::ios::trunc);
	
	if(fichier)
	{
		fichier<<"Lundi,Mardi,Mercredi,Jeudi,Vendredi"<<endl;
		
		for(int i = 0; i < NOMBRECOURSJOURNEE; i++)
		{
			fichier<<SEPARATEUR<<endl;
			
			for(int j = 0; j < NOMBREJOURNEESSEMAINE; j++)
			{
				fichier<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getProfesseur().getMatiereEnseignee()<<",";
			}
			fichier<<endl;
			for(int j = 0; j < NOMBREJOURNEESSEMAINE; j++)
			{
				fichier<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getProfesseur().getNom()<<",";
			}
			fichier<<endl;
			for(int j = 0; j < NOMBREJOURNEESSEMAINE; j++)
			{
				fichier<<"Salle "<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getSalle().getNumeroSalle()<<" ";
				fichier<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getSalle().getBatiment()<<",";
			}
		}
		ost<<"Fichier cree avec succes"<<endl;
	}
	else
	{
		ost<<"Impossible d'enregistrer le fichier"<<endl;
	}
}
