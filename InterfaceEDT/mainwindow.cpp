#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogaffichercours.h"
#include "filiere.h"

MainWindow::MainWindow(const Filiere &fil, QWidget *parent) :
    QMainWindow(parent),
    d_fil(fil),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_afficherCours_clicked()
{
    DialogAfficherCours acDialog(ui->numeroSemaine->value(), d_fil);
    acDialog.setModal(true);
    acDialog.exec();
}
