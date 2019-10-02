#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#define pi 3.14159265358979323846264338

int main()
{
    int gd=DETECT,gm;
	int Px,Py;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    delay(1000);
	POINT cursorPosition;
   while(1)
	{
	GetCursorPos(&cursorPosition);
	circle(cursorPosition.x,cursorPosition.y,100);
	delay(5);
	
    getch();
    closegraph();
    return(0);
}
