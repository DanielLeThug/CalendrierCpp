#include "EmploiDuTemps.h"
#include "iostream"


using std::cout;
using std::cin;
using std::endl;

/**
	@brief Constructeur par d�faut
*/
EmploiDuTemps::EmploiDuTemps() : d_listeSalle{}, d_listeProfs{}, d_listeFiliere{}, d_afficheur{}
{
	
}

/**
	@brief M�thode qui teste une fili�re est dans la liste de fili�res et renvoie sa position
	
	@param filiere Pointeur sur une Filiere
	@param index R�f�rence sur un entier repr�sentant la position de la Filiere dans la liste
*/
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

/**
	@brief M�thode pour ajouter une Filiere � la liste
	
	@param filiere Pointeur sur une Filiere
*/
void EmploiDuTemps::ajouterFiliere(Filiere* filiere)
{	
	int index;
	if(estDansListeFiliere(filiere, index))
	{
		std::cout<<"La filiere existe d�j�"<<std::endl;
	}
	else
	{
		d_listeFiliere.push_back(filiere);
	}
}

/**
	@brief M�thode qui teste un prof est dans la liste de Professeur et renvoie sa position
	
	@param professeur Pointeur sur un Professeur
	@param index R�f�rence sur un entier repr�sentant la position du professeur dans la liste
*/
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

/**
	@brief M�thode pour ajouter un Professeur � la liste
	
	@param professeur Pointeur sur un Professeur
*/
void EmploiDuTemps::ajouterProfesseur(Professeur* professeur)
{
	int index;
	if(estDansListeProfesseur(professeur, index))
	{
		std::cout<<"Ce professeur existe d�j�"<<std::endl;
	}
	else
	{
		d_listeProfs.push_back(professeur);
	}
}

/**
	@brief M�thode qui renvoie la Filiere de la liste � une position pass�e en param�tre
	
	@param index Entier repr�sentant la position de la Filiere
*/
Filiere* EmploiDuTemps::accederAFiliere(int index)
{ 
	return d_listeFiliere[index];
}

/**
	@brief M�thode qui affiche le menu principal dans la console
	
*/
void EmploiDuTemps::fenetrePrincipale()
{
	cout<<"Menu Principal: "<<endl;
	cout<<"1. Afficher cours "<<endl;
	cout<<"2. Ajouter, modifier, d�placer ou supprimer un cours"<<endl;
	cout<<"3. Gestion filiere"<<endl;
	cout<<"4. Ajouter un professeur"<<endl;
	cout<<"5. Quitter"<<endl;
}

/**
	@brief Boucle principale du programme
*/
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

/**
	@brief M�thode qui propose un menu console pour afficher un Cours
*/
void EmploiDuTemps::afficherCours()
{
	cout<<"De quelle fili�re souhaitez vous consulter les cours ?"<<endl;
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
			cout << "Cette semaine n'a pas encore �t� cr��."<<endl;
	}
	else
		cout<<"Cette filiere n'existe pas"<<endl;
}

/**
	@brief M�thode qui propose un menu console pour ajouter un Cours
	
	@param filiereChoisi Entier repr�sentant l'index d'une Filiere
	@param semaineChoisi Entier repr�sentant le num�ro d'une Semaine
	@param jourChoisi Entier repr�sentant le num�ro d'une Journee
*/
void EmploiDuTemps::menuAjoutCours(int filiereChoisi, int semaineChoisi, int jourChoisi)
{	
	afficherJour(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]);
	cout<<"Sur quel cr�nau souhaitez vous ajouter un cours ?"<<endl;
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
		cout<<"Il existe d�j� un cours � ce cr�nau, voulez vous le modifier ou le supprimer ?";
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

/**
	@brief M�thode qui propose un menu console pour modifier un Cours
	
	@param filiereChoisi Entier repr�sentant l'index d'une Filiere
	@param semaineChoisi Entier repr�sentant le num�ro d'une Semaine
	@param jourChoisi Entier repr�sentant le num�ro d'une Journee
*/
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
		cout<<"Ce cours n'existe pas, souhaitez vous en cr�ez un ?";
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

/**
	@brief M�thode qui propose un menu console pour supprimer un Cours
	
	@param filiereChoisi Entier repr�sentant l'index d'une Filiere
	@param semaineChoisi Entier repr�sentant le num�ro d'une Semaine
	@param jourChoisi Entier repr�sentant le num�ro d'une Journee
*/
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
		cout<<"Il n''existe pas de cours � ce cr�nau ?";

	}
	else
	{
		supprimerCours(d_listeFiliere[filiereChoisi]->getAnnee()->getSemainesAnnee()[semaineChoisi]->getJourneesSemaine()[jourChoisi]->getCoursJournee()[choix]);
	}
		
}

/**
	@brief M�thode qui affiche une Semaine dans la console
	
	@param semaine Pointeur sur une Semaine
*/
void EmploiDuTemps::afficherSemaine(const Semaine* semaine)
{
	
	d_afficheur.afficheSemaine(*semaine);
}

/**
	@brief M�thode qui enregistre une Semaine dans un fichier .csv
	
	@param semaine Pointeur sur une Semaine
*/
void EmploiDuTemps::afficherSemaineCSV(const Semaine* semaine)
{
	d_afficheur.afficheSemaine(*semaine);
}

/**
	@brief M�thode qui affiche une Journee dans la console
	
	@param jour Pointeur sur une Journee
*/
void EmploiDuTemps::afficherJour(const Journee* jour) const
{
	d_afficheur.afficheJour(jour);
}

/**
	@brief M�thode qui propose un menu console pour g�rer les Cours
*/
void EmploiDuTemps::menuCours()
{
	cout<<"Dans quelle fili�re souhaitez vous modifier les cours ?"<<endl;
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
				cout << "Cette semaine n'a pas encore �t� cr��.";
				
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

/**
	@brief M�thode renvoyant un Etudiant saisi par l'utilisateur
*/
Etudiant*	EmploiDuTemps::menuAjoutEtudiant()
{
	string nom, prenom;
	int numeroEtu;

	cout<<"Veuillez indiquer le nom de l'�tudiant"<<endl;
	cin>>nom;
	cout<<"Veuillez indiquer le pr�nom de l'�tudiant"<<endl;
	cin>>prenom;
	cout<<"Veuillez indiquer le num�ro de l'�tudiant"<<endl;
	cin>>numeroEtu;
	return new Etudiant{nom, prenom, numeroEtu};
}

/**
	@brief M�thode qui permet � l'utilisateur de saisir une Filiere
*/
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
			cout<<"Ajouter un �tudiant ? \n1. Oui\n2. Non"<<endl;
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
		cout<<"Cette filiere existe deja"<<endl;
	}
}

/**
	@brief M�thode qui permet � l'utilisateur de modifier une Filiere
	
	@param filiereChoisie R�f�rence sur un entier repr�sentant l'index d'une Filiere
*/
void EmploiDuTemps::menuModiferFiliere(const int& filiereChoisie)
{
	string intitule;
	int choix;
	vector<Etudiant*> listeEtudiants;
	if (d_listeFiliere.size() < filiereChoisie)
	{
		cout<<"Mauvaise indication";
	}
	else
	{
		cout<<"Nouvel intitule:"; 
		cin>>intitule; d_listeFiliere[filiereChoisie]->setIntitule(intitule);
	}
		
}

/**
	@brief M�thode qui permet de supprimer une Filiere
	
	@param filiereChoisie R�f�rence sur un entier repr�sentant l'index d'une Filiere
*/
void EmploiDuTemps::menuSupprimerFiliere(const int& filiereChoisie)
{
	if(getListeFiliere()[filiereChoisie])
	delete getListeFiliere()[filiereChoisie];
	getListeFiliere().resize(getListeFiliere().size()-1);
}

/**
	@brief M�thode qui propose un menu console pour g�rer les Filiere
*/
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
			cout<<"3. Supprimer une fili�re"<<endl;
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

/**
	@brief M�thode qui permet � l'utilisateur de saisir un Professeur
*/
void EmploiDuTemps::menuAjoutProfesseur()
{
	string nom, prenom, matiereEnseignee;

	cout<<"Veuillez indiquer le nom du professeur"<<endl;
	cin>>nom;
	cout<<"Veuillez indiquer le prenom du professeur"<<endl;
	cin>>prenom;
	cout<<"Veuillez indiquer la matiere enseign�e"<<endl;
	cin>>matiereEnseignee;
	d_listeProfs.push_back(new Professeur{nom, prenom, matiereEnseignee});
	cout<<"le professeur a ete ajoute";
}

/**
	@brief M�thode qui permet � l'utilisateur de modifier un Professeur
	
	@param choixProfesseur R�f�rence sur un entier repr�sentant l'index d'un Professeur
*/
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
		cout<<"Modifier\n1. Nom\n2. Pr�nom\n3. Mati�re enseign�e\n4. Quitter";
		cin>>choix;
		switch(choix) 
		{
			case 1 : {cout<<"nouveau nom:"; cin>>motEnregistre; d_listeProfs[choixProfesseur]->setNom(motEnregistre); break;}
			case 2 : {cout<<"nouveau pr�nom:"; cin>>motEnregistre; d_listeProfs[choixProfesseur]->setPrenom(motEnregistre); break;}
			case 3 : {cout<<"nouvelle mati�re:"; cin>>motEnregistre; d_listeProfs[choixProfesseur]->setMatiereEnseignee(motEnregistre); break;}
		}while(choix == 1);	
	}
}

/**
	@brief M�thode qui permet de supprimer un Professeur
	
	@param choixProfesseur R�f�rence sur un entier repr�sentant l'index d'un Professeur
*/
void EmploiDuTemps::menuSupprimerProfesseur(const int& choixProfesseur)
{
	delete d_listeProfs[choixProfesseur];
}

/**
	@brief M�thode qui renvoie un entier repr�sentant l'index du Professeur choisi par l'utilisateur
*/
int EmploiDuTemps::choixProfesseur()
{
	int choixProfesseur;
	cout<<"Choisir Professeur : " <<endl;
	afficherListeProfesseur();
	cin>>choixProfesseur;
	return choixProfesseur;
}

/**
	@brief M�thode qui propose un menu console pour g�rer les Professeur
*/
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

/**
	@brief M�thode qui affiche la liste des Salle dans la console
*/
void EmploiDuTemps::afficherListeSalle() const
{
	cout<<"Liste des salles : "<<endl;
	for(int i = 0; i < getListeSalle().size(); i++)
	{
		cout<<"Salle n�"<<getListeSalle()[i]->getNumeroSalle()<<", Batiment "<<getListeSalle()[i]->getBatiment()<<endl;
	}
}

/**
	@brief M�thode qui affiche la liste des Professeur dans la console
*/	
void EmploiDuTemps::afficherListeProfesseur() const
{
	cout<<"Liste des professeurs : "<<endl;
	for(int i = 0; i < getListeProfesseur().size(); i++)
	{
		cout<<i+1<<" "<<getListeProfesseur()[i]->getNom()<<" "<<getListeProfesseur()[i]->getPrenom()<<" enseigne "<<getListeProfesseur()[i]->getMatiereEnseignee()<<endl;
	}
}

/**
	@brief M�thode qui affiche la liste des Filiere dans la console
*/
void EmploiDuTemps::afficherListeFiliere()
{
	cout<<"Liste des filieres : "<<endl;
	for(int i=0;i<getListeFiliere().size();i++)
	{
		cout<<i+1<<" "<<getListeFiliere()[i]->getIntitule()<<endl;
	}
}

/**
	@M�thode qui renvoie un entier repr�sentant la Filiere choisie par l'utilisateur
*/
int EmploiDuTemps::choixFiliere()
{	
	afficherListeFiliere();
	cout<<"Rentrez choix : ";
	int choix;
	cin>>choix;
	return choix-1;
}

/**
	@brief M�thode qui propose un menu console � l'utilisateur pour ajouter un Cours
	
	@param journeeAModifier Pointeur sur une Journee
	@param creneau Entier repr�sentant un cr�neau de la Journee
*/
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

/**
	@brief Getter renvoyant un vecteur de pointeurs sur des Salle
*/
vector<Salle*> EmploiDuTemps::getListeSalle() const
{
	return d_listeSalle;
}

/**
	@brief Getter renvoyant un vecteur de pointeurs sur des Professeur
*/
vector<Professeur*> EmploiDuTemps::getListeProfesseur() const
{
	return d_listeProfs;
}

/**
	@brief Getter renvoyant un vecteur de pointeurs sur des Filiere
*/
vector<Filiere*> EmploiDuTemps::getListeFiliere() const
{
	return d_listeFiliere;
}

/**
	@brief M�thode proposant un menu console � l'utilisateur pour modifier un Cours
	
	@param coursAModifier Pointeur sur le Cours � modifier
*/
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

/**
	@brief M�thode qui supprime le Cours pass� en param�tre
	
	@param coursASupprimer Pointeur sur un Cours
*/
void EmploiDuTemps::supprimerCours(Cours* coursASupprimer)
{
	delete coursASupprimer;
}

/**
	@brief M�thode qui teste si une Filiere est d�j� pr�sente dans la liste des Filiere
	
	@param intitule R�f�rence sur un string repr�sentant l'intitul� de la Filiere
*/
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
