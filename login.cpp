#include "login.h"
#include<iostream>
#include<string.h>
#include "database.h"
#include<fstream>
#include<filesystem>
#include <unistd.h>
#include <bits/stdc++.h>
#include <QMessageBox>
#include "encryptDecrypt.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::current_path;

using std::cout; using std::endl;
using std::system; using std::string;
namespace fs = std::filesystem;

string getUsername(string temp)
{
    string s = temp;
    string delimiter = "+";

    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        return token;
        s.erase(0, pos + delimiter.length());
    }
}
string getPassword(string temp)
{
    string s = temp;
    string delimiter = "+";
    int flag = 1;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
        if(flag == 2)
        {
            break;
        }
        flag++;
    }
    return token;
}

int login::loginUser(string username, string password)
{
    Database login;
    fstream file;
    string temp, un, pass;
    string path = current_path();
    path = path + "/Database/" + "users" + ".db";
    file.open(path,ios::in);
    while(getline(file, temp))
    {
        cout<<temp<<endl;
        temp = encryptDecrypt(temp);
        un = getUsername(temp);
        pass = getPassword(temp);
        cout<<un<<pass<<endl;
        if(un == username && pass == password)
        {
            return 1;
        }
    }
    return 0;
}

login::login()
{

}

login::~login()
{

}
