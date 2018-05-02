#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    imageLabel = new QLabel;
    ui->imageLabel->setBackgroundRole(QPalette::Base);
    ui->imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->imageLabel->setScaledContents(true);

    createActions();
    createMenus();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                         tr("Open File"), QDir::currentPath(),tr("Files (*.*)") ); //jpg, *.png, *.bmp
         if (!fileName.isEmpty())
         {
             QImage image(fileName);
             if (image.isNull())
             {
                 QMessageBox::information(this, tr("Ошибка открытия файла"),
                                          tr("Не удается загрузить файл %1. \nВыберите картинку").arg(fileName));
                 return;
             }
          ui->imageLabel->setPixmap(QPixmap::fromImage(image));
          ui->imageLabel->adjustSize();
          }
//          printAct->setEnabled(true);
//          fitToWindowAct->setEnabled(true);
//          updateActions();

//          if (!fitToWindowAct->isChecked())
//              imageLabel->adjustSize();
//         }
}


void MainWindow::paintEvent(QPaintEvent *)

{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
//    QString fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.jpg");
//    QPixmap pic;
//    pic.load(fileName);



//    QImage img("C:/Qt/_qt/RecognizingFormulas/Image/phone.jpg"); // загружаем картинку
//    QPainter painter(this); // определяем объект painter, который обеспечивает рисование
//    painter.drawImage(0,0, img.scaled(this->size())); // рисуем наше изображение от 0,0 и растягиваем по всему виджету


}

void MainWindow::createActions()
{
//    ui->openAct = new QAction(tr("&Открыть"), this);
    ui->openAct->setShortcut(tr("Ctrl+O"));
    connect(ui->openAct, SIGNAL(triggered()), this, SLOT(open()));
}

void MainWindow::createMenus()
{
//    ui->fileMenu = new QMenu(tr("&Файл"), this);
    ui->fileMenu->addAction(ui->openAct);
    ui->fileMenu->addSeparator();

    menuBar()->addMenu(ui->fileMenu);

}
