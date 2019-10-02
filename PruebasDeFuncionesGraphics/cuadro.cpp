#include <graphics.h>
#include <conio.h>

int main(){
        int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    bar(0,0,20,20);
    getch();
    closegraph();
    return 0;
}

void Menu()
{
    //Nombre del Programa

    //Variables para obtener el centro  en x;
        int midx;
       midx = getmaxx() / 2;

    //Justificacion del texto alineado al centro.
       settextjustify(CENTER_TEXT, CENTER_TEXT);

    //Tipo de fuente y tamaño para texto
    int font= 4;  //BOLD_FONT 	 ->   10 	Stroked bold font
    size=4;

    //settextstyle(int font , int direction , int charsize);
    settextstyle(font,HORIZ_DIR,size);
    //Salida del texto ya con fuente modificada, ubicacion en el centro de x.
    outtextxy(midx,100,font);


    //Boton Nuevo

}
void DrawGrill(Posiciones P)       //Parametro de estructura con las variables de X & Y asi como de altura, base y longitud.
{
    int i,j;
    for(i=0;i<(P.base);i++)
    {
        for(j=0;j<(P.altura);j++)
        {
            line(P.Pix,P.longitud*(j+1),P.Pfx,P.longitud*(j+1)); //Posicion inicial de X,
        }
            line(P.longitud*(i+1),P.Piy,P.longitud*(i+1),P.Pfy);
    }
}

/*void DrawPalletOfColors(int Pfx,int Pix,int PfyPlus) //Se pasa la posicion final de 2
{

}*/

void ClickGrill()
{
        if(ismouseclick(WM_LBUTTONDOWN)) //Se comprueba que se presiono
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=(P.Pix)&&x<=(P.Pfx)&&y>=(P.Piy)&&y<=(P.Pfy))
            {
                setcolor(GREEN);
              floodfill(x,y,GREEN);
               break;
            }
            //bar(100,100,100,100);
        }
}
