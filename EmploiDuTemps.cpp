#include "EmploiDuTemps.h"
#include "iostream"


using std::cout;
using std::cin;
using std::endl;

EmploiDuTemps::EmploiDuTemps() : d_listeSalle{}, d_listeProfs{}, d_listeFiliere{}, d_afficheur{}
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
	cout<<"3. Gestion filiere"<<endl;
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
	cout<<"De quelle filière souhaitez vous consulter les cours ?"<<endl;
	int filiereChoisi = choixFiliere();
	int semaineChoisi;
	if(filiereChoisi<getListeFiliere().size())
	{
		cout<<"Quelle semaine souhaitez vous consulter ? : "<<endl;
		cin >> semaineChoisi;
		//si la semaine existe on l'affiche
		if(getListeFiliere()[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi])
			afficherSemaine(getListeFiliere()[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]);
		else
			cout << "Cette semaine n'a pas encore été créé."<<endl;
	}
	else
		cout<<"Cette filiere n'existe pas"<<endl;
}

void EmploiDuTemps::menuAjoutCours(int filiereChoisi, int semaineChoisi, int jourChoisi)
{	
	afficherJour(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]);
	cout<<"Sur quel crénau souhaitez vous ajouter un cours ?"<<endl;
	int choix=0;
	cout<<"1. 8h-10h"<<endl;
	cout<<"2. 10h-12h"<<endl;
	cout<<"3. 14h-16h"<<endl;
	cout<<"4. 16h-18h"<<endl;
	do
	{
		cout<<"Rentrez votre choix";
		cin>>choix;
	}while(choix<=0 || choix >=5);
	if(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]->getCoursJournee()[choix])
	{
		cout<<"Il existe déjà un cours à ce crénau, voulez vous le modifier ou le supprimer ?";
		cout<<"1. Ne rien faire "<<endl;
		cout<<"2. Modifier"<<endl;
		cout<<"3. Supprimer"<<endl;
		int choixAction=0;
		do
		{
		cout<<"Rentrez votre choix";
		cin>>choix;
		}while(choix<=0 || choix >=4);
		if(choixAction==2)
		{
			modifierCours(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]->getCoursJournee()[choix]);
		}
		else if(choixAction==3)
		{
			supprimerCours(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]->getCoursJournee()[choix]);
		}
	}
	else
	{
		ajouterCours(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi],choix);
	}
	
}

void EmploiDuTemps::menuModiferCours(int filiereChoisi, int semaineChoisi, int jourChoisi)
{
	afficherJour(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]);
	cout<<"Quel cours souhaitez vous modifier?"<<endl;
	int choix=0;
	cout<<"1. 8h-10h"<<endl;
	cout<<"2. 10h-12h"<<endl;
	cout<<"3. 14h-16h"<<endl;
	cout<<"4. 16h-18h"<<endl;
	do
	{
		cout<<"Rentrez votre choix";
		cin>>choix;
	}while(choix<=0 || choix >=5);	
	if(!d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]->getCoursJournee()[choix])
	{
		cout<<"Ce cours n'existe pas, souhaitez vous en créez un ?";
		cout<<"1. Ne rien faire "<<endl;
		cout<<"2. Ajouter un cours"<<endl;
		int choixAction=0;
		do
		{
		cout<<"Rentrez votre choix";
		cin>>choix;
		}while(choix<=0 || choix >=3);
		if(choixAction==2)
		{
			ajouterCours(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi], choix);
			
		}		
	}
	else
	{
		modifierCours(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]->getCoursJournee()[choix]);
	}
}



void EmploiDuTemps::menuSupprimerCours(int filiereChoisi, int semaineChoisi, int jourChoisi)
{
	afficherJour(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]);
	cout<<"Quels cours souhaitez vous supprimer ?"<<endl;
	int choix=0;
	cout<<"1. 8h-10h"<<endl;
	cout<<"2. 10h-12h"<<endl;
	cout<<"3. 14h-16h"<<endl;
	cout<<"4. 16h-18h"<<endl;
	do
	{
		cout<<"Rentrez votre choix";
		cin>>choix;
	}while(choix<=0 || choix >=5);
	if(!d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]->getCoursJournee()[choix])
	{
		cout<<"Il n''existe pas de cours à ce crénau ?";

	}
	else
	{
		supprimerCours(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]->getCoursJournee()[choix]);
	}
		
}

void EmploiDuTemps::afficherSemaine(const Semaine* semaine)
{
	
	d_afficheur.afficheSemaine(*semaine);
}

void EmploiDuTemps::afficherSemaineCSV(const Semaine* semaine)
{
	d_afficheur.afficheSemaine(*semaine);
}

void EmploiDuTemps::afficherJour(const Journee* jour) const
{
	d_afficheur.afficheJour(jour);
}
void EmploiDuTemps::menuCours()
{
	cout<<"Dans quelle filière souhaitez vous modifier les cours ?"<<endl;
	int filiereChoisi = choixFiliere();
	if(filiereChoisi<getListeFiliere().size())
	{
		int choix, semaineChoisi, jourChoisi;
		do
		{	
			cout<<"Quelle semaine souhaitez vous modifier ? : "<<endl;
			cin >> semaineChoisi;
			//si la semaine existe on l'affiche
			if(getListeFiliere()[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi])
				afficherSemaine(getListeFiliere()[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]);
			else
				cout << "Cette semaine n'a pas encore été créé.";
				
			cout<<"Quelle jour souhaitez vous modifier ? : "<<endl;
			cin >> jourChoisi;
			// ensuite :
			cout<<"1. Ajouter un cours "<<endl;
			cout<<"2. Modifier un cours "<<endl;
			cout<<"3. Supprimer un cours"<<endl;
			cout<<"4. Quitter"<<endl;	
			cin>>choix;
			switch(choix) 
			{
				case 1 : menuAjoutCours(filiereChoisi, semaineChoisi, jourChoisi); break;
				case 2 : menuModiferCours(filiereChoisi, semaineChoisi, jourChoisi); break;
				case 3 : menuSupprimerCours(filiereChoisi, semaineChoisi, jourChoisi);	break;
			}
		}while(choix>=1 && choix<=3);
	}
	else
	{
		cout<<"La filiere n'existe pas"<<endl;
	}
}

Etudiant*	EmploiDuTemps::menuAjoutEtudiant()
{
	string nom, prenom;
	int numeroEtu;

	cout<<"Veuillez indiquer le nom de l'étudiant"<<endl;
	cin>>nom;
	cout<<"Veuillez indiquer le prénom de l'étudiant"<<endl;
	cin>>prenom;
	cout<<"Veuillez indiquer le numéro de l'étudiant"<<endl;
	cin>>numeroEtu;
	return new Etudiant{nom, prenom, numeroEtu};
}

void EmploiDuTemps::menuAjoutFiliere()
{
	string intitule;
	int idFiliere, choix;
	vector<Etudiant*> listeEtudiants;
	
	cout<<"Intitule de la filiere ?";
	cin>>intitule;
	if (!filiereExisteDeja(intitule))
	{	
		do
		{
			cout<<"Ajoutez un étudiant ? \n1. Oui\n2. Non"<<endl;
			cin>>choix;
			switch(choix) 
			{
				case 1 : listeEtudiants.push_back(menuAjoutEtudiant()); break;
			}
		}while(choix == 1);	
		d_listeFiliere.push_back(new Filiere(intitule, listeEtudiants));
	}
	else
	{
		cout<"cette filière existe déjà";
	}
}

void EmploiDuTemps::menuModiferFiliere(const int& filiereChoisie)
{
	string intitule;
	int choix;
	vector<Etudiant*> listeEtudiants;
	if (d_listeFiliere.size() < filiereChoisie)
	{
		cout<<"mauvaise indication";
	}
	else
	{
		
		cout<<"Nouvel intitule:"; cin>>intitule; d_listeFiliere[filiereChoisie]->setIntitule(intitule);
	}
		
}

void EmploiDuTemps::menuSupprimerFiliere(const int& filiereChoisie)
{
	if(getListeFiliere()[filiereChoisie])
	delete getListeFiliere()[filiereChoisie];
	getListeFiliere().resize(getListeFiliere().size()-1);
}
		
void EmploiDuTemps::menuFiliere()
{
	int choix;
	do
	{	
		if(d_listeFiliere.size()!=0)
		{
		
			cout<<"Quelle filiere voulez-vous modifier ?"<<endl;
			int filiereChoisie = choixFiliere();
			
			if(filiereChoisie <= getListeFiliere().size())
				cout<<getListeFiliere()[filiereChoisie]->getIntitule()<<" nombre d'etudiants:"<<getListeFiliere()[filiereChoisie]->getListeEtudiants().size()<<endl;
			else
				cout << "Cette filiere n'a pas encore ete cree."<<endl;
		
			cout<<"1. Ajouter une filiere"<<endl;
			cout<<"2. Modifier une filiexre"<<endl;
			cout<<"3. Supprimer une filière"<<endl;
			cout<<"4. Quitter"<<endl;	
			cin>>choix;
			switch(choix) 
			{
				case 1 : menuAjoutFiliere(); break;
				case 2 : menuModiferFiliere(filiereChoisie); break;
				case 3 : menuSupprimerFiliere(filiereChoisie);	break;
			}
		}
		else
		{
			menuAjoutFiliere();
			choix=1;
		}
	}while(choix>=1 && choix<=3);
}

void EmploiDuTemps::menuAjoutProfesseur()
{
	string nom, prenom, matiereEnseignee;

	cout<<"Veuillez indiquer le nom du professeur"<<endl;
	cin>>nom;
	cout<<"Veuillez indiquer le prenom du professeur"<<endl;
	cin>>prenom;
	cout<<"Veuillez indiquer la matiere enseignée"<<endl;
	cin>>matiereEnseignee;
	d_listeProfs.push_back(new Professeur{nom, prenom, matiereEnseignee});
	cout<<"le professeur a ete ajoute";
}

void EmploiDuTemps::menuModiferProfesseur(const int& choixProfesseur)
{
	string motEnregistre;
	int choix;

	if (d_listeProfs.size() >= choixProfesseur)
	{
		cout<<"mauvaise indication";
	}
	else
	{
		cout<<"Modifier\n1. Nom\n2. Prénom\n3. Matière enseignée\n4. Quitter";
		cin>>choix;
		switch(choix) 
		{
			case 1 : {cout<<"nouveau nom:"; cin>>motEnregistre; d_listeProfs[choixProfesseur]->setNom(motEnregistre); break;}
			case 2 : {cout<<"nouveau prénom:"; cin>>motEnregistre; d_listeProfs[choixProfesseur]->setPrenom(motEnregistre); break;}
			case 3 : {cout<<"nouvelle matière:"; cin>>motEnregistre; d_listeProfs[choixProfesseur]->setMatiereEnseignee(motEnregistre); break;}
		}while(choix == 1);	
	}
}

void EmploiDuTemps::menuSupprimerProfesseur(const int& choixProfesseur)
{
	delete d_listeProfs[choixProfesseur];
}

			
int EmploiDuTemps::choixProfesseur()
{
	int choixProfesseur;
	cout<<"Choisir Professeur : " <<endl;
	afficherListeProfesseur();
	cin>>choixProfesseur;
	return choixProfesseur;
}

void EmploiDuTemps::menuProfesseur()
{
	int choix, profChoisi;

	do
	{	
		if(d_listeProfs.size()!=0)
		{
			afficherListeProfesseur();
			cout<<"Quel professeur souhaitez vous modifier ? : "<<endl;
			cin >> profChoisi;
			cout<<"1. Ajouter un professeur"<<endl;
			cout<<"2. Modifier un professeur"<<endl;
			cout<<"3. Supprimer un professeur"<<endl;
			cout<<"4. Quitter"<<endl;	
			cin>>choix;
			switch(choix) 
			{
				case 1 : menuAjoutProfesseur(); break;
				case 2 : menuModiferProfesseur(choixProfesseur()); break;
				case 3 : menuSupprimerProfesseur(choixProfesseur()); break;
			}
		}
		else
		{
			menuAjoutProfesseur();
			choix=1;
		}
	}while(choix>=1 && choix<=3);
}

void EmploiDuTemps::afficherListeSalle() const
{
	cout<<"Liste des salles : "<<endl;
	for(int i = 0; i < getListeSalle().size(); i++)
	{
		cout<<"Salle n°"<<getListeSalle()[i]->getNumeroSalle()<<", Batiment "<<getListeSalle()[i]->getBatiment()<<endl;
	}
}
	
void EmploiDuTemps::afficherListeProfesseur() const
{
	cout<<"Liste des professeurs : "<<endl;
	for(int i = 0; i < getListeProfesseur().size(); i++)
	{
		cout<<i+1<<" "<<getListeProfesseur()[i]->getNom()<<" "<<getListeProfesseur()[i]->getPrenom()<<" enseigne "<<getListeProfesseur()[i]->getMatiereEnseignee()<<endl;
	}
}

void EmploiDuTemps::afficherListeFiliere()
{
	cout<<"Liste des filieres : "<<endl;
	for(int i=0;i<getListeFiliere().size();i++)
	{
		cout<<i+1<<" "<<getListeFiliere()[i]->getIntitule()<<endl;
	}
}

int EmploiDuTemps::choixFiliere()
{	
	afficherListeFiliere();
	cout<<"Rentrez choix : ";
	int choix;
	cin>>choix;
	return choix-1;
}
void EmploiDuTemps::ajouterCours(Journee* journeeAModifier, int crenau)
{	
	cout<<"Choisir Professeur : " <<endl;
	afficherListeProfesseur();
	int choixProfesseur;
	cin>>choixProfesseur;
	cout<<"Choisir Salle ; "<<endl;
	afficherListeSalle();
	int choixSalle;
	cin>>choixSalle;
	int horaire;
	switch(crenau)
	{
		case 1: 
			 horaire=8;
			break;
		case 2: 
			horaire=10;
			break;
		case 3: 
			horaire=14;
			break;
		case 4: 
			horaire=16;
			break;
	};
	Cours* cours= new Cours{d_listeProfs[choixProfesseur], d_listeSalle[choixSalle], horaire};
	journeeAModifier->ajouterCours(cours, crenau);
}

vector<Salle*> EmploiDuTemps::getListeSalle() const
{
	return d_listeSalle;
}

vector<Professeur*> EmploiDuTemps::getListeProfesseur() const
{
	return d_listeProfs;
}

vector<Filiere*> EmploiDuTemps::getListeFiliere() const
{
	return d_listeFiliere;
}

void EmploiDuTemps::modifierCours(Cours* coursAModifier) 
{
	cout<<"Choisir Professeur : " <<endl;
	afficherListeProfesseur();
	int choixProfesseur;
	cin>>choixProfesseur;
	coursAModifier->setProfesseur(d_listeProfs[choixProfesseur]);
	cout<<"Choisir Salle ; "<<endl;
	afficherListeSalle();
	int choixSalle;
	cin>>choixSalle;
	coursAModifier->setSalle(d_listeSalle[choixSalle]);
}

void EmploiDuTemps::supprimerCours(Cours* coursASupprimer)
{
	delete coursASupprimer;
}

bool EmploiDuTemps::filiereExisteDeja(const string& intitule)
{	
	if(getListeFiliere().size()==0)
	{
		return false;
	}
	int index=0;
	while(index<getListeFiliere().size() && getListeFiliere()[index]->getIntitule()!=intitule)
	{
		index++;
	}
	return index==getListeFiliere().size();
}
