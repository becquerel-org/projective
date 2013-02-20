#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QGraphicsView>
 #include <QCloseEvent>
// #include "computation.h"
 #include <QMessageBox>
#include "newcomputationwindow.h"
#include <QFileDialog>


MainWindow::MainWindow()
{
    MatrixView = new QGraphicsView(this);
    setCentralWidget(MatrixView);
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    newComp = new QAction(tr("&New Computation..."), this);
    newComp->setStatusTip("Starts a new computation");
    QObject::connect(newComp, SIGNAL(triggered()), this, SLOT(newComputation()));

    loadComp = new QAction(tr("&Load Computation..."), this);
    loadComp->setStatusTip("Loads a previously saved computation");

    saveComp = new QAction(tr("&Save Computation..."), this);
    saveComp->setStatusTip("Saves a previously saved computation");

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
    compMenu = menuBar()->addMenu(tr("&Computation"));

    compMenu->addAction(newComp);
    compMenu->addAction(loadComp);
    compMenu->addAction(saveComp);

    compMenu->addSeparator();

    compMenu->addAction(exitAct);


}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton ret = saveChanges();
    switch(ret)
    {
        case QMessageBox::Save:
            saveComputation(); // deliberate fallthrough
        case QMessageBox::Discard:
            event->accept();
            break;
        default:
        event->ignore();
    }
}


void MainWindow::saveComputation()
{
    //todo: tie in to backend
   // ask for file name...
    QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName.isEmpty())
    {
        return;
    }

    // otherwise, pass on file name to actual backend

   return;
}

void MainWindow::newComputation()
{
    NewComputationWindow *newWindow = new NewComputationWindow(this);
    QObject::connect(newWindow, SIGNAL(computationCreated(int,int)), this, SLOT(startComputation(int, int)));

    newWindow->show();
    newWindow->activateWindow();
}

QMessageBox::StandardButton MainWindow::saveChanges()
{
    // todo
    QMessageBox::StandardButton msg;
    msg = QMessageBox::question(this, tr("Application"),
                               tr("What do you want to do with the current computation?"),
                               QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

    return msg;
}

void MainWindow::startComputation(int k, int l)
{
    // starting multiple computations = recipe for disaster...
    newComp->setDisabled(true);
    loadComp->setDisabled(true);
    // todo
    return;
}

void MainWindow::loadComputation()
{
    newComp->setDisabled(true);
    loadComp->setDisabled(true);
    //todo: tie in to backend
   return;
}

void MainWindow::cancelComputation()
{
    QMessageBox::StandardButton ret = saveChanges();

    switch(ret)
    {
        case QMessageBox::Save:
          saveComputation(); //deliberate fallthrough
        case QMessageBox::Discard:
          newComp->setDisabled(false);
          loadComp->setDisabled(true);
          break;
        case QMessageBox::Cancel:
    default:
            break;
    };


}
