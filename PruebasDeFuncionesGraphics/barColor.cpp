#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm,i,j, color=0,base,altura,longitud=200,x=100,y=100;
    cout<<"Inserte la base: ";
    cin>>base;
    cout<<"\nInserte la altura: ";
    cin>>altura;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    delay(2000);

    for(i=0;i<=(altura*y);i+=(y*i))
    {
        for(j=0;i<(base*x);j+=(x*i))
        {
            setfillstyle(SOLID_FILL,color);
            bar(x,y,x+(base*x),y+(altura*y));
        }
    }
}
