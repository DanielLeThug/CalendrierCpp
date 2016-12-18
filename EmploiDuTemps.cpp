#include "EmploiDuTemps.h"
#include "iostream"


using std::cout;
using std::cin;
using std::endl;

EmploiDuTemps::EmploiDuTemps()
{
	
}

bool EmploiDuTemps::estDansListeFiliere(Filiere* filiere, int& index) const
{
	for(int i=0;i<d_listeFiliere.size();i++)
	{
		if(d_listeFiliere[i]==filiere)
		{
			index=i;
			return true;
		}
	}
	return false;
}


void EmploiDuTemps::ajouterFiliere(Filiere* filiere)
{	
	int index;
	if(estDansListeFiliere(filiere, index))
	{
		std::cout<<"La filiere existe déjà"<<std::endl;
	}
	else
	{
		d_listeFiliere.push_back(filiere);
	}
}

bool EmploiDuTemps::estDansListeProfesseur(Professeur* professeur, int& index) const
{
	for(int i=0;i<d_listeProfs.size();i++)
	{
		if(d_listeProfs[i]==professeur)
		{
			index=i;
			return true;
		}
	}
	return false;
}

void EmploiDuTemps::ajouterProfesseur(Professeur* professeur)
{
	int index;
	if(estDansListeProfesseur(professeur, index))
	{
		std::cout<<"Ce professeur existe déjà"<<std::endl;
	}
	else
	{
		d_listeProfs.push_back(professeur);
	}
}

Filiere* EmploiDuTemps::accederAFiliere(int index)
{ 
	return d_listeFiliere[index];
}


void EmploiDuTemps::fenetrePrincipale()
{
	cout<<"Menu Principal: "<<endl;
	cout<<"1. Afficher cours "<<endl;
	cout<<"2. Ajouter, modifier, déplacer ou supprimer un cours"<<endl;
	cout<<"3. Ajouter une filière"<<endl;
	cout<<"4. Ajouter un professeur"<<endl;
	cout<<"5. Quitter"<<endl;
}

void EmploiDuTemps::loopFenetrePrincipale()
{
	int choix;
	do
	{
		fenetrePrincipale();
		cin>>choix;
		switch(choix) 
		{
			case 1 : afficherCours(); break;
			case 2 : menuCours(); break;
			case 3 : menuFiliere(); break;
			case 4 : menuProfesseur();	break;
		}
	}while(choix>=1 && choix<=4);
}

void EmploiDuTemps::afficherCours()
{
	
}

void EmploiDuTemps::menuAjout(int filiereChoisi, int semaineChoisi, int jourChoisi)
{
	
}

void EmploiDuTemps::menuModifer()
{
	
}

void EmploiDuTemps::menuDeplacer()
{
	
}

void EmploiDuTemps::menuSupprimer()
{
	
}

void EmploiDuTemps::afficherSemaine()
{
	
}

void EmploiDuTemps::menuCours()
{
	cout<<"Dans quelle filière souhaitez vous modifier les cours ?"<<endl;
	int filiereChoisi = choixFiliere();
	int choix, semaineChoisi, jourChoisi;
	do
	{	
		cout<<"Quelle semaine souhaitez vous modifier ? : "<<endl;
		cin >> semaineChoisi;
		//si la semaine existe on l'affiche
		if(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi])
			afficherSemaine();
		else
			cout << "Cette semaine n'a pas encore été créé.";
			
		cout<<"Quelle jour souhaitez vous modifier ? : "<<endl;
		cin >> jourChoisi;
		// ensuite :
		cout<<"1. Ajouter un cours "<<endl;
		cout<<"2. Modifier un cours "<<endl;
		cout<<"3. Déplacer un cours "<<endl;
		cout<<"4. Supprimer un cours"<<endl;
		cout<<"5. Quitter"<<endl;	
		cin>>choix;
		switch(choix) 
		{
			case 1 : menuAjout(filiereChoisi, semaineChoisi, jourChoisi); break;
			case 2 : menuModifer(); break;
			case 3 : menuDeplacer(); break;
			case 4 : menuSupprimer();	break;
		}
	}while(choix>=1 && choix<=4);
}

void EmploiDuTemps::menuFiliere()
{
	
}

void EmploiDuTemps::menuProfesseur()
{
	
}

void EmploiDuTemps::afficherListeFiliere()
{
	for(int i=0;i<d_listeFiliere.size();i++)
	{
		cout<<i+1<<" "<<d_listeFiliere[i]->getIntitule()<<endl;
	}
}

int EmploiDuTemps::choixFiliere()
{	
	cout<<"Liste des filieres :"<<endl;
	afficherListeFiliere();
	cout<<"Rentrez choix : ";
	int choix;
	cin>>choix;
	return choix-1;
}
