#include "database.h"
#include<iostream>
#include<fstream>
#include <filesystem>
#include<string.h>
#include <unistd.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

string encryptDecrypt(string toEncrypt) {
    char key = 'H'; //Any char will work
    string output = toEncrypt;

    for (int i = 0; i < toEncrypt.length(); i++)
    {
        output[i] = toEncrypt[i] ^ key;
    }

    return output;
}
