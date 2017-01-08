#include "AfficheurCSV.h"
#include <fstream>
#include <string>

using std::endl;
using std::ofstream;

const string SEPARATEUR = "##########,##########,##########,##########,##########";
const string COURSVIDE = "##########";
const int NOMBRECOURSJOURNEE = 4;

void AfficheurCSV::afficheSemaine(const Semaine& semaine, std::ostream& ost)
{
	ofstream fichier("EmploiDuTemps.csv",std::ios::out | std::ios::trunc);
	
	if(fichier)
	{
		fichier<<"Lundi,Mardi,Mercredi,Jeudi,Vendredi"<<endl;
		
		for(int i = 0; i < NOMBRECOURSJOURNEE; i++)
		{
			fichier<<SEPARATEUR<<endl;
			
			
			for(int j = 0; j < semaine.getJourneesSemaine().size(); j++)
			{
				if(semaine.getJourneesSemaine()[j]->getCoursJournee()[i])
				{
					fichier<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getHorraire()<<"h : ";
					fichier<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getProfesseur().getMatiereEnseignee();
				}
				else
				{
					fichier<<COURSVIDE;
				}
				
				if(j != semaine.getJourneesSemaine().size()-1 ) fichier<<",";
			}
			fichier<<endl;
			for(int j = 0; j < semaine.getJourneesSemaine().size(); j++)
			{
				if(semaine.getJourneesSemaine()[j]->getCoursJournee()[i])
				{
					fichier<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getProfesseur().getNom();
				}
				else
				{
					fichier<<COURSVIDE;
				}
				
				if(j != semaine.getJourneesSemaine().size()-1 ) fichier<<",";
			}
			fichier<<endl;
			for(int j = 0; j < semaine.getJourneesSemaine().size(); j++)
			{
				if(semaine.getJourneesSemaine()[j]->getCoursJournee()[i])
				{
					fichier<<"Salle "<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getSalle().getNumeroSalle()<<" ";
				fichier<<semaine.getJourneesSemaine()[j]->getCoursJournee()[i]->getSalle().getBatiment();
				}
				else
				{
					fichier<<COURSVIDE;
				}
				
				if(j != semaine.getJourneesSemaine().size()-1 ) fichier<<",";
			}
			fichier<<endl;
		}
		ost<<"Fichier cree avec succes"<<endl;
	}
	else
	{
		ost<<"Impossible d'enregistrer le fichier"<<endl;
	}
}
