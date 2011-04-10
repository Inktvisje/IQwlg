#ifndef WLG_H
#define WLG_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "qthread.h"

class wlg : public QThread
{
    Q_OBJECT
public:
    explicit wlg(QObject *parent = 0);
    int setup(QString fn, QString karakters, int mil, int mal);


protected:
void run();
QString fileName, kars;
int minLength, maxLength;

private:
int c;  //gwl()
QFile wfile;
QTextStream wout;
bool iterate(int rl, int tl, QString kars, QString word);

signals:

public slots:


};

#endif // WLG_H
