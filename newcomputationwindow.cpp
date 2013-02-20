#include "newcomputationwindow.h"
 #include <QLabel>
 #include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>

#include <QHBoxLayout>
#include <QVBoxLayout>

NewComputationWindow::NewComputationWindow(QMainWindow *parent) :
    QMainWindow(parent), k(0), l(0)
{

    this->setWindowTitle(tr("New computation"));

    labelInfo = new QLabel(this);
    labelInfo->setText(tr("Choose parameters for your computation:"));

    labelK = new QLabel(this);
    labelK->setText(tr("k"));

    labelL = new QLabel(this);
    labelL->setText(tr("l"));

    editK = new QLineEdit(this);
    editK->setText("0");


    editL = new QLineEdit(this);
    editL->setText("0");


    QIntValidator* v = new QIntValidator(editK);
    v->setBottom(0);

    editK->setValidator(v);
    editL->setValidator(v);
    QObject::connect(editL, SIGNAL(textChanged(QString)), this, SLOT(setL()));
    QObject::connect(editK, SIGNAL(textChanged(QString)), this, SLOT(setK()));

    ok = new QPushButton(tr("&OK"), this);
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(createComputation()));

    cancel = new QPushButton(tr("&Cancel"), this);
    QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *layoutInfo = new QHBoxLayout();
    layoutInfo->addWidget(labelInfo);


    QHBoxLayout *layoutK = new QHBoxLayout();
    layoutK->addWidget(labelK);
    layoutK->addWidget(editK);

    QHBoxLayout *layoutL = new QHBoxLayout();
    layoutL->addWidget(labelL);
    layoutL->addWidget(editL);

    QHBoxLayout *layoutButtons = new QHBoxLayout();
    layoutButtons->addWidget(ok);
    layoutButtons->addWidget(cancel);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout (layoutInfo);
    layout->addLayout (layoutK);
    layout->addLayout (layoutL);
    layout->addLayout(layoutButtons);

    QWidget *q = new QWidget();
    setCentralWidget(q);
    q->setLayout(layout);

}

void NewComputationWindow::createComputation()
{
    if(k > 0 && l > 0) {
        emit computationCreated(k, l);
    }
    close();
}

void NewComputationWindow::setK()
{
    k = editK->text().toInt();
}


void NewComputationWindow::setL()
{
    l = editL->text().toInt();
}
