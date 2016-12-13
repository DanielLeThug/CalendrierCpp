#ifndef SALLE_H
#define SALLE_H

#include <string>

using std::string;

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

#endif
