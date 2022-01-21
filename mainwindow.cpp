#include "mainwindow.h"
#include "loginwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<fstream>
#include "database.h"
#include <QMessageBox>
#include "login.h"
#include<QMenuBar>
#include<QMenu>
#include "encryptDecrypt.h"
#include<QDate>
#include "clearSpace.h"
#include "qfilesystemmodeldialog.h"
#include<filesystem>
#include <unistd.h>
#include "spass.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::current_path;


using std::cout; using std::endl;
using std::system; using std::string;
namespace fs = std::filesystem;

bool LOGIN = false;
bool HIDDEN = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->setDisabled(true);
    ui->widget->setVisible(false);   
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    Database registerUser;
            QMessageBox msgBox;
    //movie.insert_data("Movie name");
    QString temp;
    temp = ui->lineEdit_3->text();
    QString temp2 = ui->lineEdit_4->text();
    QString temp3 = ui->lineEdit_5->text();
    QString temp4 = ui->lineEdit_6->text();
    if(temp == "" || temp2 == "" || temp3 == "" || temp4 == "")
    {
        QMessageBox warning;
        warning.setText("Please enter a username and password!!");
        warning.exec();
    }
    else
    {
        if(ui->lineEdit_5->text() == ui->lineEdit_4->text() && strongPassword(ui->lineEdit_4->text().toStdString()))
        {
            temp = temp + "+" + ui->lineEdit_5->text();
            temp = temp + "+" + ui->lineEdit_6->text();
            string encryptedData = encryptDecrypt(temp.toStdString());
            registerUser.insert_data("users",encryptedData);
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            msgBox.setText("Succesfully Saved User!!");
            msgBox.exec();
        }
        else
        {
            if(!strongPassword(ui->lineEdit_4->text().toStdString()))
            {
                msgBox.setText("Not strong password");
                msgBox.exec();
            }
            msgBox.setText("Password and Confirm Password Not same try again!!");
            msgBox.exec();
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    login user;
    QString username,password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    int flag = user.loginUser(username.toStdString(),password.toStdString());
    if(flag == 1)
    {
        //login
        ui->tabWidget->close();
        ui->frame->setDisabled(false);
        ui->label_7->setText(username);
        LOGIN = true;
    }
    else
    {
        QMessageBox wrongunorpass;
        wrongunorpass.setText("Wrong Username or Password");
        wrongunorpass.exec();
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_commandLinkButton_released()
{
    ui->label_7->clear();
    ui->frame->show();
    ui->frame->setDisabled(true);
    ui->tabWidget->show();
    ui->textEdit->clear();
}



void MainWindow::on_pushButton_3_released()
{
    QString temp = ui->textEdit->toPlainText();
    ui->progressBar->setValue(10);
    if(temp == "")
    {
        QMessageBox empty;
        empty.setText("File will be Empty not saving!");
        empty.exec();
        ui->progressBar->reset();
        return;
    }
    QString uname = ui->label_7->text();
    Database userData(uname.toStdString());
    ui->progressBar->setValue(50);
    sleep(2);
    QString day = ui->dateEdit->date().toString("yyyy.MM.dd");
    ui->progressBar->setValue(75);
    //dandt.toStdString() = clearSpace(dandt.toStdString());
    //cout<<day;
    int flag = userData.insert_data(uname.toStdString(),day.toStdString(),temp);
    if(flag == 1)
    {
        cout<<"success";
    }
    ui->textEdit->clear();
    ui->progressBar->setValue(100);
    //userData.create_database(uname.toStdString(),2);
}



void MainWindow::on_pushButton_4_released()
{
    if(HIDDEN)
    {
    ui->frame->show();
    HIDDEN = false;
    }
    else
    {
        ui->frame->setVisible(false);
        HIDDEN = true;
    }
}




void MainWindow::on_pushButton_6_released()
{
    ui->textEdit->clear();
    ui->progressBar->reset();
    string uname  = ui->label_7->text().toStdString();
    string day = to_string(ui->dateEdit->date().day());
    string month = to_string(ui->dateEdit->date().month());
    string year = to_string(ui->dateEdit->date().year());
    QString fulldate = ui->dateEdit->date().toString("yyyy.MM.dd");
    string date = day + "_" + month + "_" + year;
    Database userData(uname);
    QString datedata = userData.show_data(uname,fulldate.toStdString());
    if(datedata == "")
    {
        QMessageBox notFound;
        notFound.setText("Couldn't Find required file!!");
        notFound.exec();
        return;
    }
    datedata.toStdString() = encryptDecrypt(datedata.toStdString());
    cout<<datedata.toStdString();
    for(auto i=0;i<101;i++)
    {
        ui->progressBar->setValue(i);
    }
    ui->textEdit->insertPlainText(datedata);

}


void MainWindow::on_actionExit_triggered()
{
    QMessageBox box;
          box.setWindowTitle(tr("Warning"));
          box.setIcon(QMessageBox::Warning);
          box.setText("Unsaved files will be lost!Continue?");

          QPushButton *yesBtn = box.addButton(tr("Yes"),
                                              QMessageBox::YesRole);
          box.addButton(tr("No"), QMessageBox::NoRole);
          QPushButton *cancelBut = box.addButton(tr("Cancel"),
                                             QMessageBox::RejectRole);

          box.exec();
          if (box.clickedButton() == yesBtn)
              QApplication::quit();
          if (box.clickedButton() == cancelBut)
               cout<<"No";
}




