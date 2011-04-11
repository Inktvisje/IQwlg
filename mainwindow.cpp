#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wlg.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    huis.setPath(QDir::homePath());
    if(!huis.exists(".IQwlg"))
    {
        qDebug() << "Creating config dir...";
        if(!huis.mkdir(".IQwlg"))
        {
            qDebug() << "Failed to create config dir";
        }
    }
    config.setPath(huis.path()+"/.IQwlg");
    setMinLength(8);
    setMaxLength(8);
    setKars("abc123@#$");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ssconnect()
{
connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
connect(ui->karakters, SIGNAL(textEdited(QString)), this, SLOT(setKars(QString)));
connect(ui->knop, SIGNAL(clicked()), this, SLOT(startGen()));
connect(ui->minSpin, SIGNAL(valueChanged(int)), this, SLOT(setMinLength(int)));
connect(ui->maxSpin, SIGNAL(valueChanged(int)), this, SLOT(setMaxLength(int)));
connect(ui->openKnop, SIGNAL(clicked()), this, SLOT(selectFile()));
connect(ui->fileNameBox, SIGNAL(textEdited(QString)), this, SLOT(setFile(QString)));
}

void MainWindow::setKars(QString k)
{
    kars = k;
    if(ui->karakters->text() != kars) { ui->karakters->setText(kars);}
    qDebug() << "kars = " << kars;
}

void MainWindow::setMinLength(int l)
{
    if(l <= maxLength) {minLength = l;}
    if(ui->minSpin->value() != minLength) {ui->minSpin->setValue(minLength);}
    qDebug() << "minLength = " << minLength;
}

void MainWindow::setMaxLength(int l)
{
    if(l >= minLength) {maxLength = l;}
    if(ui->maxSpin->value() != maxLength) {ui->maxSpin->setValue(maxLength);}
    qDebug() << "maxLength = " << maxLength;
}

void MainWindow::selectFile()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), huis.absolutePath(), tr("Files (*.*)"));
    qDebug() << "fileName=" << fileName;
    ui->fileNameBox->setText(fileName);
}

void MainWindow::setFile(QString f)
{
    fileName = f;
    qDebug() << "fileName=" << fileName;
}

void MainWindow::startGen()
{
    wlg *lijst= new wlg;
    if(!lijst->setup(ui->fileNameBox->text().toAscii(), kars, minLength, maxLength))
    {
        lijst->start();
    }
}
