#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void rellenabarra(struct palettetype *pal,int r,int g,int b, int x1,int y1,int x2,int y2);

int main()
{

    int gd = DETECT, gm,i;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    struct palettetype pal1,pal2,pal3;
    getpalette(&pal1);
    getpalette(&pal2);
    getpalette(&pal3);

    while(1)
    {
            for(i=0;i<255;i++)
            {
                rellenabarra(&pal1,i,0,0,(i*10)+10,10,((i+1)*10)+10,50);
                rellenabarra(&pal2,0,i,0,(i*10)+10,70,((i+1)*10)+10,130);
                rellenabarra(&pal3,0,0,i,(i*10)+10,150,((i+1)*10)+10,200);
            }
            break;
    }
        delay(100);
        getch();
        closegraph();
}

void rellenabarra(struct palettetype *pal,int r,int g,int b, int x1,int y1,int x2,int y2)
{
    setrgbpalette(pal->colors[1],r,g,b);
    setfillstyle(SOLID_FILL,pal->colors[1]);
    bar(x1,y1,x2,y2);
}
