#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm, color,x,y,i,n,r,cont;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    int bol;
    while(bol==1)
    {
        delay(1);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            bar(100,100,100,100);
            bol=2;
        }
    }
    getch();
    closegraph();
    return(0);
}
