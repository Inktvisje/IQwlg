#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QDir>
#include <QFileDialog>



namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ssconnect();
    QString kars;   //setkars()
    int minLength; //setMinLength()
    int maxLength; //setMaxLength()
    QDir huis;
    QDir config;



private:
    Ui::MainWindow *ui;
    QFileDialog fileDialog;
    QString fileName;


private slots:
    void setKars(QString k);
    void setMinLength(int l);
    void setMaxLength(int l);
    void startGen();

    void selectFile();
    void setFile(QString f);
};

#endif // MAINWINDOW_H
