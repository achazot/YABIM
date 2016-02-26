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
    else if(cmdContent.first() == "test")
    {
        TestFilter filter;
        m_currentImage.applyFilter(&filter);
        m_pixelMap->setPixmap(QPixmap::fromImage(m_currentImage));
    }

}

void MainWindow::loadImage(const QString &filename)
{
    if(m_currentImage.load(filename))
        ui->tex_prompt->append("File "+filename+" loaded.\n");
    else
    {
        ui->tex_prompt->append("Unable to load " + filename + "...\n");
        return;
    }

    m_pixelMap->setPixmap(QPixmap::fromImage(m_currentImage));

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
        m_pixelMap->setPixmap(QPixmap::fromImage(m_currentImage));

        m_graphicsScene->addItem(m_pixelMap);
        ui->gra_imageDisplay->scene()->update();
        ui->gra_imageDisplay->viewport()->update();
        ui->gra_imageDisplay->repaint();
    }
}

void MainWindow::on_actionLoad_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Select your image",
                                                    QDir::homePath(), "Images (*.png *.xpm *.jpg)");
    if(!filename.isEmpty())
        loadImage(filename);
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Chose a filename",
                                                    QDir::homePath(), "Images (*.png *.xpm *.jpg)");
    if(!filename.isEmpty())
    {
        save(filename);
    }
}

void MainWindow::save(const QString& filename)
{
    m_currentImage.save(filename);
}
