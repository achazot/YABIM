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

    m_pixelMap = new QGraphicsPixmapItem;
    m_graphicsScene = new QGraphicsScene(this);
    ui->gra_imageDisplay->setScene(m_graphicsScene);
    m_graphicsScene->addItem(m_pixelMap);
    m_pixelMap->show();

    currentImage = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_pixelMap;
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

    m_pixelMap->setPixmap(QPixmap::fromImage((QImage)*currentImage));

    if (ui->com_displayParameter->currentText() == "Stretch to fit")
    {
        ui->gra_imageDisplay->fitInView(
                    ui->gra_imageDisplay->scene()->sceneRect(),
                    Qt::KeepAspectRatio);
    }
}


void MainWindow::on_com_displayParameter_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Stretch to fit")
    {
        ui->gra_imageDisplay->fitInView(
                    ui->gra_imageDisplay->scene()->sceneRect(),
                    Qt::KeepAspectRatio);
        ui->gra_imageDisplay->viewport()->update();
    }
    else
    {
        m_pixelMap->setPixmap(QPixmap::fromImage((QImage)*currentImage));

        m_graphicsScene->addItem(m_pixelMap);
        ui->gra_imageDisplay->scene()->update();
        ui->gra_imageDisplay->viewport()->update();
        ui->gra_imageDisplay->repaint();
    }
}
