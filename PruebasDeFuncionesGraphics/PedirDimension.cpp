/**************
Prgrama para capturar texto en modo grafico
30 agosto 2018
**************/

//Declaración de bibliotecas
#include "graphics.h"

//Declaración de funciones
void captura();
void intextxy(int x, int y, char text[30]);

int main(){
	initwindow(800, 600, " T E X T ");

	captura();

	closegraph();
	return 0;

}

void captura(){
	char str[20];

	setcolor(WHITE);
	settextstyle(4, 0, 2);
	outtextxy(100, 100, "Dame el texto a capturar: ");
	intextxy(100, 130, str);

	outtextxy(100, 200, "El texto a capturado es: ");
	outtextxy(100, 230, str);
	getch();
}

void intextxy(int x, int y, char text[30]){
	int tecla, i = 0, color;
	char letra[2];//para imprimir la letra que va presionando

	color = getcolor();

	do{
		//imprime el cursor parpadeante
		do{
			setcolor(color);
			outtextxy(x, y, "_");
			delay(200);
			setcolor(BLACK);
			outtextxy(x, y, "_");
			delay(200);
		}while(!kbhit());

		tecla = getch();

		if(tecla != '\n' && tecla != '\b'){//\n es al clave del ENTER y \b es el backspace
			letra[0] = tecla;
			letra[1] = '\0';
			text[i++] = tecla;

			setcolor(color);
			outtextxy(x, y, letra);
			x += textwidth(letra);
		}

		if(tecla == '\b'){
			text[i--] = '\0';
			x-=textwidth(letra);

		}

		if(tecla == 13){
		text[i] = '\0';
		setcolor(color);
		}


	}while(tecla != 13);

}
