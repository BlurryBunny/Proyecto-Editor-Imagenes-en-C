#include <stdio.h>
#include <graphics.h>
#include <conio.h>


int main()
{

    int gd=DETECT,gm,Px,Py;
    //float cursorPosition;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    delay(1000);
    GetCursorPos(&cursorPosition);

	Px=cursorPosition.x;
	Py=cursorPosition.y;
	if(GetAsyncKeyState(VK_LBUTTON))
	{
		bar(Px,Py,Px+20,Py+20);
		delay(5);
	}

    getch();
    closegraph();
    return(0);
}
