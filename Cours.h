#ifndef COURS_H
#define COURS_H

class Cours
{
	public:
		Cours();
		Cours(Filiere fil, Professeur prof, Salle sal, int hor);
		
		Filiere getFiliere() const;
		setFiliere(const Filiere& fil);
		Professeur getProfesseur() const;
		setProfesseur(const Professeur& prof);
		Salle getSalle() const;
		setSalle(const Salle& sal);
		int getHorraire() const;
		setHorraire(const int& hor);
		
	private:
		Filiere d_filiere;
		Professeur d_professeur;
		Salle d_salle;
		int d_horraire;
};

#endif
