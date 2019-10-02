#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm, color,x,y,i,n,r,cont;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            bar(100,100,100,100);
        }
    }
    getch();
    closegraph();
    return(0);
}
