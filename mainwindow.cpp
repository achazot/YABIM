/*
 * YABIM
 * Version: 0.1
 *
 * Yet Another Basic Image Manipulator
 *
 * Authors :
 *  A.Chazot <alban.chazot@insa-cvl.fr>
 *  A.Gourd <auxidevelopper@auxisuite.fr>
 *
 * 2016
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lin_prompt_returnPressed()
{
    ui->tex_prompt->append(ui->lin_prompt->text());
    parseCommand(ui->lin_prompt->text());
    ui->lin_prompt->setText("");
}

void MainWindow::parseCommand(QString command)
{
    if (command=="quit" || command=="exit")
        close();

}
