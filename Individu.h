#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <string>

using std::string;

/**
	@class Individu
	@brief classe virtuelle dont hérite Etudiant et Professeur
*/
class Individu
{
	public:
		Individu(const string& nom, const string& prenom);
		
		string getNom() const;
		void setNom(const string& nom);
		string getPrenom() const;
		void setPrenom(const string& prenom);
		
	private:
		string d_nom;
		string d_prenom;
};

#endif
