#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class QGraphicsView;
class QAction;
class QMenu;
class MainWindow : public QMainWindow
{


    Q_OBJECT


public:
    MainWindow();
    ~MainWindow();

signals:

public slots:
    void newComputation();
    void loadComputation();
    void saveComputation();


    void cancelComputation();

private slots:

    void paint(int x, int y, bool marked);

    // starts a matrix computation after parameters have been chosen
    void startComputation(int k, int l);

private:

    QMenu *compMenu;
    QAction *newComp;
    QAction *loadComp;
    QAction *saveComp;
    QAction *exitAct;

    QGraphicsView *MatrixView;

    void createActions();
    void createMenus();

    void closeEvent(QCloseEvent *event);

    // this doesn't look right, but I'll think of a better way to do it.
    // nevermind, it's an enum, I'm not passing an object. Reading the docs gives you an advantage...
    QMessageBox::StandardButton saveChanges();
};

#endif // MAINWINDOW_H
