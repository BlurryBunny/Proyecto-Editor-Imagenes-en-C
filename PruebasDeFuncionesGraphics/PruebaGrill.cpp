#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

//Estructura para grill
typedef struct
{
    int Pix;
    int Piy;
    int Pfx;
    int Pfy;
    int longitud;
}TPosiciones;

int Menu(int midx,int midy);
void DividirPantalla(int midx, int midy,int maxx,int maxy);
int ClickBotones(int midx,int midy);

int main()
{
    //Se inicializa la ventana.
    int gd = DETECT, gm,i;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    //Se definen variables que pasaran como parametros iniciales en funciones
    int base, altura;
    CapturaDimension(&base,&altura);
    //Mitades y maximos de pantalla.
        int midx,midy,maxx,maxy,midx2;
       midx = getmaxx() / 3;    //Se divide en 3 la pantalla en el eje x.
       midx2=getmaxx()/2;       //Se divide en 2 la pantalla para el eje x.
        midy=getmaxy()/4;       //Se divide en 4 la pantalla en el eje y.
        maxx=getmaxx();            //Maximo de pixeles en el eje X.
        maxy=getmaxy();             //Maximo de pixeles en el eje Y.


        bol=Menu(midx2,midy);  //Eje x dividido en 2 y eje y dividido en 4
        if(bol==1)
        {
            cleardevice();

                  //Division de pantalla para separacion de elementos.
                    DividirPantalla(midx,midy,maxx,maxy);
        }else if(bol==-1)
        {

        }else{
                    cleardevice();
                    outtextxy(midx2,midy*2,"Saliendo...");
                    delay(1000);
                    exit();
        }
          //Division de pantalla para separacion de elementos.
        DividirPantalla(midx,midy,maxx,maxy);

    //Declaracion de estructura para grill
   // TPosiciones Grill;
   // DrawGrill(Grill);
   getch();
   closegraph();
   return(0);
}

int Menu(int midx,int midy)
{
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
    /*Click en botones*/
    int bol;
    bol=ClickBotones(midx,midy);
    return(bol);
}

int ClickBotones(int midx,int midy)
{
    int cont=0;
    //Boton Nuevo.
        if(mousex()>(midx-60)&&mousex()<(midx+60)+cont&&mousey()>midy&&mousey()<(midy+40)+cont&&ismouseclick(WM_LBUTTONDOWN))
        {
            bol=1;
        }
        //Boton Abrir
        cont+=60
        if(mousex()>(midx-60)&&mousex()<(midx+60)+cont&&mousey()>midy&&mousey()<(midy+40)+cont){
            bol=-1;
        }
        //Boton Salir
        cont+=60
        if(mousex()>(midx-60)&&mousex()<(midx+60)+cont&&mousey()>midy&&mousey()<(midy+40)+cont){
            bol=0;
        }
        return(bol);
}

void CapturaDimension(int *base, int *altura)
{
        outtextxy();

        outtextxy();
}
void DividirPantalla(int midx, int midy,int maxx,int maxy)
{
        /*barra de herramientas.*/

        //Altura (Posicion Final en Y)
       int Altura_Bar_Herramientas=50;

       //Tipo de relleno en barra.
        setfillstyle(SOLID_FILL,LIGHTGRAY);
        //la barra ocupa la anchura de la dispocion del proyecto con una altura considerable para botones visibles.
        bar(0,0,(midx*2)+2,Altura_Bar_Herramientas);

        //Barra continua de la separacion
        bar((midx*2)+10,0,maxx,Altura_Bar_Herramientas);

        /*Disposicion del proyecto*/
        //Rectangulo que define la posicion
        setcolor(WHITE);
        rectangle(0,Altura_Bar_Herramientas,midx*2,maxy);

        //Division de proyecto
        setfillstyle(SOLID_FILL,DARKGRAY);
        bar((midx*2)+2,0,(midx*2)+10,maxy);

        /*Previsualizador*/
        //(Pix,Piy,Pfx,Pfy);
        setcolor(WHITE);
        rectangle((midx*2)+20,Altura_Bar_Herramientas+10,maxx-10,(midy*3)-50); //cuadro de previsualizacion centrado y adecuado para diferentes tamaños de pantalla.

        /*Paleta de colores*/
        //Cuadro para indicar titulo
        rectangle((midx*2)+20,(midy*3)-40,maxx-10, (midy*3)-10);
        //Grill con colores para elegir
        rectangle((midx*2)+20,midy*3,maxx-10,maxy-10);
}

void DrawGrill(TPosiciones P)       //Parametro de estructura con las variables de X & Y asi como de altura, base y longitud.
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
