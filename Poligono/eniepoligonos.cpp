#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846264338
int main()
{
   int gd = DETECT, gm, color,x,y,i,n,r,cont;
   float x1,y1,x2,y2;
   double angl;

    printf("Ingresa el numero de lados que deseas que tenga tu figura: ");
    scanf("%d",&n);
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    if(n==1)
    {
        circle(200,200,150);
    }
    else{
    x=200;
    y=200;
    r=150;
    cont=0;
    //setcolor(WHITE);
    //circle(200,200,150);
    setcolor(GREEN);
    for(angl=0;angl<=2*pi+0.1;angl+=(2*pi/n))
    {

        x1=cos((double)angl)*(r)+x;
        y1=sin((double)angl)*(r)+y;
        if(cont!=0){
        line(x1,y1,x2,y2);
        }
        x2=x1;
        y2=y1;
        cont++;
    }

    }

    //setfillstyle(SOLID_FILL, RED);
    //setcolor(RED);
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=50&&x<=350&&y>=50&&y<=350)
            {
              floodfill(x,y,GREEN);
               break;
            }
            //bar(100,100,100,100);
        }
        delay(100);
    }
    getch();
   closegraph();
}
