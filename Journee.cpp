#include "Journee.h"
#include <iostream>

Journee::Journee(const vector<Cours*>& coursJournee) :
	d_coursJournee{coursJournee}
{
}

vector<Cours*> Journee::getCoursJournee() const
{
	return d_coursJournee;
}
		
void Journee::setCoursJournee(const vector<Cours*>& coursJournee)
{
	d_coursJournee = coursJournee;
}

void Journee::ajouterCoursJournee(vector<Cours*>& coursJournee) // menu, rajouter le choix du prof et de la salle
{	
	enum { HUIT = 0, DIX = 1, QUATORZE = 2, SEIZE = 3};
	int indexHoraire;
	
	std::cout<<"### Ajouter un cours ###"<<std::endl<<std::endl;
	
	do
	{
		std::cout<<"Entrez un horaire de debut parmis :"<<std::endl<<"(0) : 8h"<<std::endl<<"(1) : 10h"<<std::endl<<"(2) : 14h"<<std::endl<<"(3) : 16h"<<std::endl;
	
		std::cin>>indexHoraire;
	}
	while(indexHoraire<0 || indexHoraire>3);
	
	if(coursJournee[indexHoraire])
	{
		std::cout<<"Il y a deja un cours a cet horaire";
	}
	
	// choix prof; choix salle;
	
	
	switch (indexHoraire){
		case 0 : coursJournee[indexHoraire]->setHoraire(HUIT);
			break;
		case 1 : coursJournee[indexHoraire]->setHoraire(DIX);
			break;
		case 2 : coursJournee[indexHoraire]->setHoraire(QUATORZE);
			break;
		case 3 : coursJournee[indexHoraire]->setHoraire(SEIZE);
			break;
	}
	
	
}

void ajouterCoursJournee(vector<Cours*>& coursJournee, Cours* ajoutCours, int horaire)
{
	coursJournee[horaire] = ajoutCours;
} 

void Journee::modifierCoursJournee(vector<Cours*>& coursJournee) //menu
{
	int indexHoraire;
	
	do
	{
		std::cout<<"Choisissez un horaire de debut de cours a modifier parmis :"<<std::endl<<"(0) : 8h"<<std::endl<<"(1) : 10h"<<std::endl<<"(2) : 14h"<<std::endl<<"(3) : 16h"<<std::endl;
	
		std::cin>>indexHoraire;
	}
	while(indexHoraire<0 || indexHoraire>3);
	
	if(!coursJournee[indexHoraire])
	{
		std::cout<<"Il n'y a pas de cours a cet horaire";
	}
	
	
}

void Journee::supprimerCoursJournee(vector<Cours*>& coursJournee) //menu
{
	int indexHoraire;
	
	do
	{
		std::cout<<"Choisissez un horaire de debut de cours a supprimer parmis :"<<std::endl<<"(0) : 8h"<<std::endl<<"(1) : 10h"<<std::endl<<"(2) : 14h"<<std::endl<<"(3) : 16h"<<std::endl;
	
		std::cin>>indexHoraire;
	}
	while(indexHoraire<0 || indexHoraire>3);
	
	if(!coursJournee[indexHoraire])
	{
		std::cout<<"Il n'y a pas de cours a cet horaire";
	}
	else
	{
		delete coursJournee[indexHoraire];
	}
	
}

void supprimerCoursHoraire(vector<Cours*>& coursJournee, int horaire) //paramétrée
{
	delete coursJournee[horaire];
}

void Journee::deplacerCoursJournee(vector<Cours*>& coursJournee) //menu
{
	int indexHoraireDepart,indexHoraireArrivee;
	
	do
	{
		std::cout<<"Choisissez un horaire de debut de cours a deplacer parmis :"<<std::endl<<"(0) : 8h"<<std::endl<<"(1) : 10h"<<std::endl<<"(2) : 14h"<<std::endl<<"(3) : 16h"<<std::endl;
	
		std::cin>>indexHoraireDepart;
	}
	while(indexHoraireDepart<0 || indexHoraireDepart>3);
	
	if(!coursJournee[indexHoraireDepart])
	{
		std::cout<<"Il n'y a pas de cours a cet horaire";
	}
	else
	{
		do
		{
			std::cout<<"Choisissez le nouvel horaire du cours a deplacer :"<<std::endl<<"(0) : 8h"<<std::endl<<"(1) : 10h"<<std::endl<<"(2) : 14h"<<std::endl<<"(3) : 16h"<<std::endl;
	
			std::cin>>indexHoraireArrivee;
		}
		while(indexHoraireArrivee<0 || indexHoraireArrivee>3);
		
		if(coursJournee[indexHoraireArrivee])
		{
			int choix;
			do
			{
				std::cout<<"Il y a deja un cours a cet horaire, le supprimer ? "<<std::endl<<"(0) : Non"<<std::endl<<"(1) : Oui"<<std::endl;
				std::cin>>choix;
			}
			while(choix<0 || choix>1);
			
			if(choix)
			{
				supprimerCoursHoraire(coursJournee,indexHoraireArrivee);
				coursJournee[indexHoraireArrivee]=coursJournee[indexHoraireDepart];
				supprimerCoursHoraire(coursJournee,indexHoraireDepart);
			}
			
		}
		else
		{
			coursJournee[indexHoraireArrivee]=coursJournee[indexHoraireDepart];
			supprimerCoursHoraire(coursJournee,indexHoraireDepart);
		}
		
	}
}
