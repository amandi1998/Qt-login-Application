#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>// For Messageboxes
#include <QPixmap> // To add pictures

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/Programs -Practicals/Pic/loginicon.png.png"); // pix is the object of QPixmap// picture path
    int w = ui->label_3->width();
    int h =ui-> label_3->height();
    ui->label_3 ->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio)); //(method 2)- in here picture is resized according to it's label size
  //  ui->label_3 ->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio)); // call the pix object (method 1)
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "Hi" && password == "123"){
        QMessageBox::information(this,"Login","Login is Successfully");
        hide(); // This hide method hides the first window
        secDialog = new  SecondDialog(this); // To call second window
        secDialog->show();

    }
    else{
        QMessageBox::warning(this,"Login","UserName or Password is not match!! Check again.");
    }
}
