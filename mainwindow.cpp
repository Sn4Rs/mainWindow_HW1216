#include "mainwindow.h"
#include <fstream>
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(actionSave,SIGNAL(triggered(bool)),this,SLOT(savefile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::savefile()
{
    ofstream file;
    file.open("textedit.txt");
    file<<textEdit->toPlainText();
    file.close();
}

