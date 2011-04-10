#include "wlg.h"

wlg::wlg(QObject *parent) :
    QThread(parent)
{
}

int wlg::setup(QString fn, QString karakters, int mil, int mal)
{
    fileName = fn;
    kars = karakters;
    minLength = mil;
    maxLength = mal;
    wfile.setFileName(fileName);
    if (!wfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing: "
             << qPrintable(wfile.errorString()) << endl;
        return 1;
    }
    wout.setDevice(&wfile);

    c = kars.count();
    qDebug() << "Character count = " << c;
    return 0;
}

void wlg::run()
{

    qDebug() << "Started generating!";
    for(int tl=minLength;tl<=maxLength;tl++)
    {
        iterate(tl, tl, kars, "");
    }
    wout.flush();
    wfile.close();
    exit();
}

bool wlg::iterate(int rl, int tl, QString kars, QString word)
{
    for(int k=0;k<c;k++)
    {
        word[tl - rl] = kars[k];
        if(rl > 1)
        {
            iterate(rl-1, tl,kars, word);
            wout.flush();
        }
        else
        {
            //qDebug() << word;
            wout << word+"\n";
        }
    }
    return true;
}

