#include "dialogaffichercours.h"
#include "ui_dialogaffichercours.h"

DialogAfficherCours::DialogAfficherCours(int numeroSem, const Filiere &fil, QWidget *parent) :
    QDialog(parent),
    d_fil(fil),
    d_numeroSem(numeroSem),
    ui(new Ui::DialogAfficherCours)
{
    ui->setupUi(this);
    //ui->lundi8_10->setText(QString::fromStdString(fil.getAnnee()->getSemainesAnnee()[numeroSem]->getJourneesSemaine()[0]->getCoursJournee()[0]->getProfesseur().getNom()));
}

DialogAfficherCours::~DialogAfficherCours()
{
    delete ui;
}
