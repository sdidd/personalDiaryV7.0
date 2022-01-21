#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include<iostream>
#include<string.h>

using namespace std;

class login
{
public:
    login();
    login(const login &);
    int loginUser(string,string);
    ~login();

};

#endif // LOGIN_H
