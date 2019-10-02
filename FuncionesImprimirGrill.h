#ifndef FUNCIONESIMPRIMIRGRILL_H_INCLUDED
#define FUNCIONESIMPRIMIRGRILL_H_INCLUDED

void DividirPantalla(int quartx, int midy,int maxx,int maxy,int quarty,TMalla *Grill,TMalla *VistaPrevia)
{

        /**Barra de Herramientas**/
        //Altura (Posicion Final en Y)
       int Altura_Bar_Herramientas=50;

       //Tipo de relleno en barra.
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        //la barra ocupa la anchura de la dispocion del proyecto con una altura considerable para botones visibles.
        bar(0,0,maxx,Altura_Bar_Herramientas);

        /**Proyecto**/
         //Margen exterior de Grill
        // setfillstyle(SOLID_FILL,BLACK);
        //bar(0,Altura_Bar_Herramientas,(quartx*3),maxy);

        /**Asignar valores de x1, y1,x1,y2 para grill**/
        Grill->xi=10;
        Grill->yi=Altura_Bar_Herramientas+10;
        Grill->xf=(quartx*3)-10;
        Grill->yf=maxy-10;

        //Limite de Grill
        setfillstyle(SOLID_FILL,WHITE);
       // bar(Grill->xi,Grill->yi,Grill->xf,Grill->yf);
        setcolor(WHITE);
        rectangle(Grill->xi,Grill->yi,Grill->xf,Grill->yf);


        /**Separacion Area de Trabajo y Recursos**/
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        //Barra continua de la separacion
        bar((quartx*3)+1,Altura_Bar_Herramientas,(quartx*3)+10,maxy);

        /**Recursos**/

        /**Asignar valores de x1, y1, x2, y2 para Previsualizador**/
        VistaPrevia->xi=(quartx*3)+20;
        VistaPrevia->yi=Altura_Bar_Herramientas +20;
        VistaPrevia->xf=maxx-20;
        VistaPrevia->yf=(quarty*3)-200;

        /*Previsualizador*/
        setfillstyle(SOLID_FILL,WHITE);
        //bar(VistaPrevia->xi,VistaPrevia->yi,VistaPrevia->xf,VistaPrevia->yf);
        setcolor(WHITE);
        rectangle(VistaPrevia->xi,VistaPrevia->yi,VistaPrevia->xf,VistaPrevia->yf);
         //cuadro de previsualizacion centrado y adecuado para diferentes tamaños de pantalla.

        /*Paleta de colores*/
        //Cuadro para indicar color actual.
        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar((quartx*3)+20,(quarty*3)-60,maxx-20, (quarty*3)-10);

        //Grill con colores para elegir
        rectangle((quartx*3)+20,quarty*3,maxx-20,maxy-20);
}

void DibujarOpciones(int x1,int y1,int x2,int y2,int maxx)
{
    //Variables
    int font=8,size=3;
    int auxx=0;
    y1=5;
    x1=5;

    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
  //Se dibuja el cuadro para simular boton
  for(auxx=0;auxx<4;auxx++)
  {
          bar((x2*auxx)+x1,y1,(x2*(auxx+1))-x1,y2-5);
  }
      //Recuadro para boton Salir
    bar(maxx-200,5,maxx-20,45);

    /**Texto**/
    char bottom[4][10]={"New","Open","Save","Save As"};
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    settextstyle(font,HORIZ_DIR,size);

  //Se imprime el texto de cada boton
  for(auxx=0;auxx<4;auxx++)
  {
      outtextxy((x2*auxx)+110,y2-15,bottom[auxx]);
  }
        //Texto para Boton Salir.
    outtextxy(maxx-130,y2-15,"Exit");
}

void DibujarColores(int x1,int y1, int x2, int y2)
{
    int i,j;
    int alto=(y2-y1)/4,ancho=(x2-x1)/4;
   //Se ponen las lineas en blanco.
    setcolor(WHITE);

    for(i=1;i<4;i++)
    {
            line(x1+(i*ancho),y1,x1+(i*ancho),y2); //Lineas horizontales.
    }
    for(j=1;j<4;j++)
    {
        line(x1,y1+(j*alto),x2,y1+(j*alto));      //Lineas verticales.
    }

    int Px,Py;
    int color=0;
    //Ciclo para rellenar de colores el miniGrill
    for(i=1;i<=4;i++)
    {
        Py=y1+((i*alto)-(alto/2));
        for(j=1;j<=4;j++)
        {
            Px=x1+((j*ancho)-(ancho/2));
            setfillstyle(SOLID_FILL,color);
            //if(color!=15)
            //{
                    floodfill(Px,Py,WHITE);
                    color++;
            //}else{
               //     bar(x1+((i-1)*ancho)+1,y1+((j-1)*alto)+1,x1+(i*ancho)-1,y1+(j*alto)-1);
            //}
        }
    }
}

void DisposicionColorActual(int x1,int y1, int x2, int y2,int color)
{
    //Longitud desde punto final a inicial.
    int longitud=x2-x1;
    //Tipo de fuente y tamaño
    int font=8,size=3;
    //Justificacion de texto
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    //Saliida de texto
    settextstyle(font,HORIZ_DIR,size);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(x1+(longitud/3),y1+20,"Actual: ");

    BarColorActual(x1,y1,x2,y2,color);
    //Color obtenido con getpixel(x,y);
    //floodfill(x2-(longitud/3)+(longitud/2),y1+15,WHITE);
}

void DibujarGrill(TMalla *Grill, int **Colores)
{
        int i,j,color;

        /**distancia total entre numero de renglones/columnas**/
        Grill->largo=(Grill->xf-Grill->xi)/Grill->NCol;
        Grill->alto=(Grill->yf-Grill->yi)/Grill->NRen;


        setcolor(WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        /**Lineas que indican la cantidad de Renglones y Columnas para el proyecto**/
            for(i=1;i<=Grill->NRen-1;i++)
        {
            for(j=1;j<=Grill->NCol-1;j++)
            {
                line(Grill->xi+((Grill->largo)*j),Grill->yi, Grill->xi+((Grill->largo)*j),Grill->yf);
            }
                line(Grill->xi,Grill->yi+((Grill->alto)*i),Grill->xf,Grill->yi+((Grill->alto)*i));
        }


        /**Bars de color que indican **/
        for(i=0;i<Grill->NRen;i++)
        {
            for(j=0;j<Grill->NCol;j++)
            {
                color=(*(*(Colores+i)+j));
                setfillstyle(SOLID_FILL,color);
                bar(Grill->xi+((Grill->largo)*j)+1,Grill->yi+((Grill->alto)*i)+1,Grill->xi+(Grill->largo*(j+1))-1,Grill->yi+((Grill->alto)*(i+1))-1);
            }
        }
}

void BarColorActual(int x1,int y1, int x2, int y2, int color)
{
        int longitud=x2-x1;
        setfillstyle(SOLID_FILL,color);
        bar(x2-(longitud/3),y1+5,x2-50,y2-5);
}


#endif // FUNCIONESIMPRIMIRGRILL_H_INCLUDED
