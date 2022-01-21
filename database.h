#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include<fstream>
#include<QFile>

using namespace std;

class Database
{
    string databasename;
public:
    Database();
    Database(string);
    int create_database(string);
    int create_database(string,int);
    int insert_data(string,string);
    int insert_data(string,string,QString);
    QString show_data(string,string);
    void update_line(string,string,string);
    string returnLine(string, int);
};

#endif // DATABASE_H
