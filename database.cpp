#include "database.h"
#include<iostream>
//#include<fstream>
#include <filesystem>
#include<string.h>
#include <unistd.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encryptDecrypt.h"
#include<QFile>
#include<simplebuffer.h>
#include "login.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::current_path;


using std::cout; using std::endl;
using std::system; using std::string;
namespace fs = std::filesystem;

using namespace std;


Database::Database()
{
    string directory_name("Database");

        fs::create_directory(directory_name)?
        cout << "created directory - " << directory_name << endl :
        cout << "create_directory() failed" << endl;
}

Database::Database(string username)
{
    string path = current_path();
    string temp = path + "/Database/" + username;
    string directory_name(temp);
    fs::create_directory(directory_name)?
    cout << "created directory - " << directory_name << endl :
    cout << "create_directory() failed" << endl;
}

int Database::create_database(string dbname)
{
    fstream file;
    string path = current_path();
    path = path + "/Database/" + dbname + ".db";
    Database::databasename = path;
    file.open(path,ios::app);
    return 1;
}

/*int Database::create_database(string dbname, int flag)
{
    fstream file;
    string path = current_path();
    path = path + "/Database/" + dbname + ".db";
    Database::databasename = path;
    file.open(path,ios::app);
    return 1;
}*/

int Database::insert_data(string dbname,string data)
{
    fstream file;
    string path = current_path();
    path = path + "/Database/" + dbname + ".db";
    file.open(path,ios::app);
    file<<data<<"\n";
    file.close();
    return 1;
}

int Database::insert_data(string username,string dateandtime,QString data)
{
    fstream file;
    string path = current_path();
    path = path + "/Database/" + username + "/" + dateandtime + ".txt";
    //file.open(path, ios::out);
    //data.toStdString() = encryptDecrypt(data.toStdString());
    //file.close();
    QFile outfile;
    outfile.setFileName(QString::fromStdString(path));
    outfile.open(QIODevice::WriteOnly |QIODevice::Text);
    QTextStream out(&outfile);
    out<<data;
    outfile.close();
    return 1;
}

QString Database::show_data(string username,string dateandtime)
{
    fstream file;
    QString temp;
    string path = current_path();
    path = path + "/Database/" + username + "/" + dateandtime + ".txt";
    /*file.open(path, ios::in);
    file>>temp;
    temp = encryptDecrypt(temp);
    cout<<temp;
    file.close();*/
    QFile outfile;
    outfile.setFileName(QString::fromStdString(path));
    outfile.open(QIODevice::ReadOnly |QIODevice::Text);
    QTextStream in(&outfile);
    temp = in.readAll();
    outfile.close();
    QString decryptToString(temp);
    return temp;
}
