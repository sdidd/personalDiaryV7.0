#include "spass.h"
#include<iostream>
#include<string.h>

using namespace std;

bool strongPassword(string pass)
{
    int flagD =0,flagS = 0,flagL=0,flagA=0;
    for(auto i=0;i<pass.length();i++)
    {
        if(pass.length()>=6)
        {
            flagL++;
        }
        if(isdigit(pass[i]))
        {
            flagD++;
        }
        if(!isdigit(pass[i]) && !isalpha(pass[i]))
        {
            flagS++;
        }
        if(isalpha(pass[i]))
        {
            flagA++;
        }
    }
    if(flagD>=1 && flagS>=1 && flagL >=1 && flagA>=1)
    {
        return true;
    }
    return false;
}
