#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(savefile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::savefile()
{
    QString filename;
    filename=".\\test.txt";
    QFile file(filename);
    QTextStream out(&file);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        qDebug()<<"File not open";
        return;
    }
    out<<ui->plainTextEdit->toPlainText();
    file.flush();
    file.close();
}


