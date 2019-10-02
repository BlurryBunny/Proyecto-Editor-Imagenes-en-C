#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main()
{
    int gd = DETECT, gm, x=50, y=50,PIx,PIy, PFx, PFy,altura,color=0,base,i,j;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    delay(2000);
    ismouseclick(WM_LBUTTONDOWN);
    while(true)
    {
    }
    floodfill();
}
