#ifndef NEWCOMPUTATIONWINDOW_H
#define NEWCOMPUTATIONWINDOW_H

#include <QWidget>

#include <QMainWindow>

class QLabel;
class QLineEdit;
class QPushButton;


class NewComputationWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit NewComputationWindow(QMainWindow *parent = 0);
    
signals:
    // user chooses params k and l and wants to start computation
    void computationCreated(int k, int l);
public slots:
    void createComputation();

private slots:
    // sets parameters to value in text fields; input is guaranteed to be OK through a validator
    void setK();
    void setL();


private:

    QLabel *labelInfo;
    QLabel *labelK;
    QLineEdit *editK;

    QLabel *labelL;
    QLineEdit *editL;

    QPushButton *ok;
    QPushButton *cancel;

    int k;
    int l;

};

#endif // NEWCOMPUTATION_H
