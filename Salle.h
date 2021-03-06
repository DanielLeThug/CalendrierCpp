#ifndef SALLE_H
#define SALLE_H

#include <string>

using std::string;

/**
	@class Salle
	@brief Classe Salle contenant des string de num�ro de salle et de batiment
*/
class Salle
{
	public:
		Salle(const string& numSal, const string& bat);
		
		string getNumeroSalle() const;
		void setNumeroSalle(const string& numSal);
		string getBatiment() const;
		void setBatiment(const string& bat);
		
	private:
		string d_numeroSalle;
		string d_batiment;
};

bool operator==(Salle salle, Salle secondeSalle);

#endif
