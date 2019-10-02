#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm,i;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    int PIx=50,PIy=50,Pfx=75,Pfy=75;
    int maxx,maxy,minx,miny;
    maxx = getmaxx();
    maxy = getmaxy();
    printf("x: %d",maxx);
    printf(" y:%d",maxy);
    while(1)
    {
      while(Pfx<=maxx && Pfy<=maxy)
    {
        cleardevice();
        bar(PIx,PIy,Pfx,Pfy);
        delay(16.67);
        PIx+=5;
        Pfx+=5;
        PIy+=5;
        Pfy+=5;

    }
    while(PIx>=0 && PIy>=0)
    {
        cleardevice();
        bar(PIx,PIy,Pfx,Pfy);
        delay(16.67);
        PIx-=5;
        Pfx-=5;
        PIy-=5;
        Pfy-=5;

    }

    }

}
