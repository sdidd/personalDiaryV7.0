#include<iostream>
#include<string.h>

using namespace std;

//DIDNT NEEDED
//CLEAR SPACES IN DATES
string clearSpace(string dandt)
{
    for(int i=0;dandt[i]!='\0';i++)
    {
        string temp;
        temp.push_back(dandt[i]);
        if(temp == " " )
        {
            dandt[i] = '_';
        }
    }
    return dandt;
}
