#include "AfficheurConsole.h"

using std::endl;
using std::cout;

/**
	@brief Méthode qui affiche une semaine de cours dans la console
	
	@param semaine Référence sur une Semaine
*/
void AfficheurConsole::afficheSemaine(const Semaine& semaine) const
{
	cout<<"### Emploi du temps de la semaine ###"<<endl;
	
	for(int i=0;i<semaine.getJourneesSemaine().size();i++)
	{
		cout<<"Jour n°"<<i+1<<endl;
		afficheJour(semaine.getJourneesSemaine()[i]);
		
	}
}

/**
	@brief Méthode qui affiche une journée de cours dans la console
	
	@param jour Pointeur sur une Journee
*/
void AfficheurConsole::afficheJour(const Journee* jour) const
{
	for(int j=0;jour->getCoursJournee().size();j++)
		{
			afficheCours(jour->getCoursJournee()[j]);
			
		}
}

/**
	@brief Méthode qui affiche un cours dans la console
	
	@param cours Pointeur sur un Cours
*/
void AfficheurConsole::afficheCours(const Cours* cours) const
{
	if(cours)
	{
		cout<<cours->getHorraire()<<"h : ";
		cout<<cours->getProfesseur().getMatiereEnseignee();
		cout<<" - "<<cours->getProfesseur().getNom()<<endl;
		cout<<"---En salle "<<cours->getSalle().getNumeroSalle();
		cout<<" Batiment "<<cours->getSalle().getBatiment()<<endl;
		cout<<"---Duree : "<<cours->getDuree()<<"h"<<endl<<endl;
	}
	else
	{
		cout<<"---"<<endl;
		cout<<"---Creneau vide"<<endl;
		cout<<"---"<<endl<<endl;
	}	
}

/**
	@brief Destructeur
*/
AfficheurConsole::~AfficheurConsole()
{
}
