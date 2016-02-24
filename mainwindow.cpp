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
    currentImage = NULL;
    pixelMap = NULL;
    graphicsScene = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lin_prompt_returnPressed()
{
    ui->tex_prompt->append(" > " + ui->lin_prompt->text());
    parseCommand(ui->lin_prompt->text());
    ui->lin_prompt->setText("");
}

void MainWindow::parseCommand(QString command)
{
    if (command=="quit" || command=="exit")
        close();

    QList<QString> cmdContent = command.split(" ");

    if ( cmdContent.first() == "load")
    {
        cmdContent.pop_front();
        if (cmdContent.empty())
        {
            ui->tex_prompt->append("Usage: load <file path>\n");
            return;
        }
        loadImage(cmdContent.first());
    }

}

void MainWindow::loadImage(QString file)
{
    if (currentImage) delete currentImage;
    currentImage = new Image(file);
    if (currentImage) ui->tex_prompt->append("File "+file+" loaded.\n");
    if (pixelMap) delete pixelMap;
    pixelMap = new QGraphicsPixmapItem(QPixmap::fromImage((QImage)*currentImage));
    if (graphicsScene) delete graphicsScene;
    graphicsScene = new QGraphicsScene(this);
    graphicsScene->addItem(pixelMap);
    //graphicsScene->setSceneRect(currentImage->);
    ui->gra_imageDisplay->setScene(graphicsScene);
    ui->gra_imageDisplay->scene()->update();
    if (ui->com_displayParameter->currentText()=="Stretch to fit")
    {
        ui->gra_imageDisplay->fitInView(
                    ui->gra_imageDisplay->scene()->sceneRect(),
                    Qt::KeepAspectRatio);
    }
    ui->gra_imageDisplay->viewport()->update();
    ui->gra_imageDisplay->show();
}


void MainWindow::on_com_displayParameter_currentTextChanged(const QString &arg1)
{
    if (ui->com_displayParameter->currentText()=="Stretch to fit")
    {
        ui->gra_imageDisplay->fitInView(
                    ui->gra_imageDisplay->scene()->sceneRect(),
                    Qt::KeepAspectRatio);
        ui->gra_imageDisplay->viewport()->update();
        ui->gra_imageDisplay->show();
    }
    else
    {
        if (pixelMap) delete pixelMap;
        pixelMap = new QGraphicsPixmapItem(QPixmap::fromImage((QImage)*currentImage));
        if (graphicsScene) delete graphicsScene;
        graphicsScene = new QGraphicsScene(this);
        graphicsScene->addItem(pixelMap);
        ui->gra_imageDisplay->setScene(graphicsScene);
        ui->gra_imageDisplay->scene()->update();
        ui->gra_imageDisplay->viewport()->update();
        ui->gra_imageDisplay->show();
        ui->gra_imageDisplay->repaint();
    }
}
