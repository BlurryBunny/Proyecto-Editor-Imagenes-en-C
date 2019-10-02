#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm,i;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    //Nombre del Programa

    //Variables para obtener el centro  en x;
        int midx,midy;
       midx = getmaxx() / 2;
        midy=getmaxy()/4;

    //Justificacion del texto alineado al centro.
       settextjustify(CENTER_TEXT, CENTER_TEXT);

    //Tipo de fuente y tamaño para texto
    int font= 4;  //BOLD_FONT 	 ->   10 	Stroked bold font
   int size=5;

    //settextstyle(int font , int direction , int charsize);
    settextstyle(font,HORIZ_DIR,size);
    //Salida del texto ya con fuente modificada, ubicacion en el centro de x.
    outtextxy(midx,midy,"PIXL-ANT");

    //tipos de botones
    char bottom[3][30]={"Nuevo","Abrir","Salir"};
    midy+=50;
    size=1;
    //Ciclo para imprimir botones
    for(i=0;i<3;i++)
    {

           rectangle(midx-60,midy,midx+60,midy+40);
            midy+=30;
            settextstyle(font,HORIZ_DIR,size);
            outtextxy(midx,midy,bottom[i]);
            midy+=30;
    }

    //
    getch();
    closegraph();
    return(0);
}
