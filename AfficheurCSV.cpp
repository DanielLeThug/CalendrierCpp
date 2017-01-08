#include "AfficheurCSV.h"
#include <string>

using std::endl;
using std::ofstream;

const string SEPARATEUR = "##########,##########,##########,##########,##########";
const string COURSVIDE = "##########";
const int NOMBRECOURSJOURNEE = 4;

/**
	@brief Méthode qui enregistre une semaine de cours dans un fichier csv
	
	@param semaine Référence sur une Semaine
*/
void AfficheurCSV::afficheSemaine(const Semaine& semaine) const // Difficile d'utiliser les méthodes ci-dessous pour éviter la duplication, car l'affichage se fait en ligne pour le format csv
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
		std::cout<<"Fichier cree avec succes"<<endl;
		fichier.close();
	}
	else
	{
		std::cout<<"Impossible d'enregistrer le fichier"<<endl;
	}
}

/**
	@brief Méthode qui enregistre une journée de cours dans un fichier csv
	
	@param journee Pointeur sur une Journee
*/
void AfficheurCSV::afficheJour(const Journee* journee) const
{
	ofstream fichier("EmploiDuTemps.csv",std::ios::out | std::ios::trunc);
	
	if(fichier)
	{
		fichier<<"Emploi du temps du jour :"<<endl;
		for(int i=0; i < journee->getCoursJournee().size();i++)
		{
			fichier<<SEPARATEUR<<endl;
			afficheCours(journee->getCoursJournee()[i], fichier);
		}
		fichier.close();
	}
	else
	{
		std::cout<<"Impossible d'enregistrer le fichier"<<endl;
	}
}

/**
	@brief Méthode utilisée par la méthode AfficheurCSV::AfficheJour pour enregistrer un cours dans un fichier csv passé en paramètre
	
	@param cours Pointeur sur un Cours
	@param fichier Fichier passé en paramètre
*/
void AfficheurCSV::afficheCours(const Cours* cours, ofstream& fichier) const
{
	if(fichier)
	{
		if(cours)
		{		
			fichier<<cours->getHorraire()<<"h : ";
			fichier<<cours->getProfesseur().getMatiereEnseignee();
			fichier<<cours->getProfesseur().getNom();
			fichier<<cours->getSalle().getNumeroSalle()<<" ";
			fichier<<cours->getSalle().getBatiment();
		}
		else
		{
			fichier<<COURSVIDE;
		}	
	}
	else
	{
		std::cout<<"Impossible d'enregistrer le fichier"<<endl;
	}
}

/**
	@brief Destructeur
*/
AfficheurCSV::~AfficheurCSV()
{
}
