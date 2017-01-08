#include "mainwindow.h"
#include <QApplication>
#include "Filiere.h"
#include "professeur.h"

int main(int argc, char *argv[])
{
    vector<Etudiant*> vEtu;
    vEtu.push_back(new Etudiant("Wettel", "Daniel", 31));
    Filiere fil("L3 Info", vEtu);
    vector<Cours*> vCour;
    vCour.push_back(new Cours(new Professeur("Dupont", "Jean", "Math"), new Salle("01", "B"), 8));
    fil.getAnnee()->getSemainesAnnee()[1]->getJourneesSemaine()[0] = new Journee(vCour);
    QApplication a(argc, argv);
    MainWindow w(fil);
    w.show();

    return a.exec();
}
