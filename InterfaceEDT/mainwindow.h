#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Filiere.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const Filiere &fil, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_afficherCours_clicked();

private:
    Ui::MainWindow *ui;
    Filiere d_fil;
};

#endif // MAINWINDOW_H
