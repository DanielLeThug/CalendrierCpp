#ifndef DIALOGAFFICHERCOURS_H
#define DIALOGAFFICHERCOURS_H

#include <QDialog>
#include "Filiere.h"

namespace Ui {
class DialogAfficherCours;
}

class DialogAfficherCours : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAfficherCours(int numeroSem, const Filiere &fil, QWidget *parent = 0);
    ~DialogAfficherCours();

private:
    Ui::DialogAfficherCours *ui;
    Filiere d_fil;
    int d_numeroSem;
};

#endif // DIALOGAFFICHERCOURS_H
