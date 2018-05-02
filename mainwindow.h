#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QLabel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
     void open();


protected:
    void paintEvent(QPaintEvent *); // пееопределение виртуальной функции


private:
    Ui::MainWindow *ui;

    void createActions();
    void createMenus();

//    QLabel *imageLabel;
//    QAction *openAct;
//    QMenu *fileMenu;


};

#endif // MAINWINDOW_H
