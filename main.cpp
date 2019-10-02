/**
Proyecto editor de imagenes.
Creado por: Ulises Uriel Dominguez Perez.
Lenguajes de Programacion.  3°Semestre.
**/

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include  "Cabecera.h"
#include "AsignacionMemAndValue.h"
#include "FuncionesBotonesSiNo.h"
#include  "FuncionesImprimirGrill.h"

int main()
{
    cleardevice();
    //Declarar apuntadores.
    TMalla *Grill;
    TMalla *VistaPrevia;
    TPantalla *PantallaDim;

    int bol;
    //Se declara la estructura para la disposicion de elementos en la pantalla.


    //Se asigna memoria a los apuntadores.
    bol=AsignaMemDis(&PantallaDim);

        /**Arreglo dinamico bidimensional de enteros**/
    int ** ColoresProyecto;  //Guarda el numero de color en cada posicion (i,j) del Grill.

    //Se abre la pantalla ejecutable.
    initwindow(1920,1080," PIXLANT ");

    AsignarValoresPantalla(PantallaDim);

    /**Declaracion de variables**/
    char NombreFile[30]="NULL";

        //Se llama a menu para imprimir recursos
        Menu(PantallaDim);

        //Se declaran las variables para posicion.
        int x,y,tipo;
    /**Ciclo donde se detecta que boton se presiono**/
    while(1)
    {
        delay(1);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            //Funcion que detecta NUEVO, ABRIR, SALIR.
            tipo=CheckMouseMENU(x,y,PantallaDim);
            break;
        }
    }//Fin de while
    //Manda a la funcion de acuerdo al boton presionado.
    OpcionDeInicio(tipo,PantallaDim, Grill,VistaPrevia,ColoresProyecto,NombreFile);
}


/**--------------------------------------------------------Funciones para MENU Proyecto--------------------------------------------------------**/

    //Recursos graficos para el menu **/
void Menu(TPantalla *Pantalla)
{
    //Justificacion del texto alineado al centro.
       settextjustify(CENTER_TEXT, CENTER_TEXT);

    //Tipo de fuente y tamaño para texto
    int font= 4;  //BOLD_FONT 	 ->   10 	Stroked bold font
   int size=5;

    //settextstyle(int font , int direction , int charsize);
    settextstyle(font,HORIZ_DIR,size);
    //Salida del texto ya con fuente modificada, ubicacion en el centro de x.
    outtextxy(Pantalla->midx,Pantalla->midy-50,"PIXL-ANT");

    //tipos de botones
    char bottom[3][30]={"Nuevo","Abrir","Salir"};
    Pantalla->midy+=50;
    size=1;

    int i;
    //Ciclo para imprimir botones
    int midy=Pantalla->midy;
    for(i=0;i<3;i++)
    {

           rectangle(Pantalla->midx-60,midy,Pantalla->midx+60,midy+40);
            midy+=30;
            settextstyle(font,HORIZ_DIR,size);
            outtextxy(Pantalla->midx,midy,bottom[i]);
            midy+=30;
    }

}

    //Detecta el boton presionado en el menu principal y lo envia a las funciones segun corresponda**/
int CheckMouseMENU(int x, int y, TPantalla *P)
{
           int bol,cont=0;
            //Posiciones en X para detectar que esta en el rango
            if(x>=(P->midx-60)&&x<=(P->midx+60))
            {
                //Boton Nuevo
                if(y>=(P->midy+cont)&&y<=(P->midy+40+cont))
                {
                            cleardevice();
                            bol=1;
                }

                //Boton Abrir
                cont+=60;
                  if(y>=(P->midy+cont)&&y<=(P->midy+40+cont))
                {
                            cleardevice();
                           bol=2;
                }

                //BotonSalir
                cont+=60;
                if(y>=(P->midy+cont)&&y<=(P->midy+40+cont))
                {
                            cleardevice();
                           bol=3;
                }
            }
return bol;
}

void  OpcionDeInicio(int tipo,TPantalla *P, TMalla *Grill,TMalla *VistaPrevia,  int **ColoresProyecto,char NombreFile[30])
{
    cleardevice();
    /*Renglones, Columnas, bandera, color inicial*/
    int NR,NC,band,bol,bol1,bol2,color=0;

    switch(tipo)
    {
        /**Nuevo**/
    case 1:
            //Auxiliares para obtener renglones y columnas;
            PedirDimensiones(&NR,&NC,P);
            bol1=AsignaMem(&Grill);
            bol2=AsignaMem(&VistaPrevia);
            bol=AsignaMemBidimensional(&ColoresProyecto,NR,NC);
            if(bol==1&&bol1==1&&bol2==1)
            {
                delay(50);
                // bol=AsignaMemBidimensional(&ColoresProyecto,NR,NC);
                SetBlackColor(ColoresProyecto,NR,NC,Grill);
                Proyecto(P,Grill,VistaPrevia,ColoresProyecto,NombreFile,&color);
            }
        break;
        /**Abrir Archivo**/
    case 2:
                PedirNombre(NombreFile,P);
                bol=CompararNombre(NombreFile);
                if(bol==1){
                     band=Abrir_Comparar(NombreFile,P,Grill,ColoresProyecto);
                    bol1=AsignaMem(&Grill);
                    bol2=AsignaMem(&VistaPrevia);
                    if(band==1)
                    {
                            Proyecto(P,Grill,VistaPrevia,ColoresProyecto,NombreFile,&color);
                    }else{
                            free(P);
                            main();
                    }
                }
        break;
    /**Salir**/
    case 3:
        Mensaje(P,0);
        delay(1000);
        closegraph();
        break;

    }

}


/**** --------------------------------------------------------Funciones para NUEVO Proyecto--------------------------------------------------------*****/

    //Pide al usuario el ancho y alto, se actualiza los datos ingresados por el usuario.

void PedirDimensiones(int *ren, int *col, TPantalla *Pantalla)
{
	//se definen cadenas de caracteres para cada elemento.
	char strRen[5];
    char strCol[5];

	setcolor(WHITE);
	settextstyle(4, 0, 5);

	/**Capturar Renglones y columnas. **/
	//Pide al usuario el numero de renglones primero.
	outtextxy(Pantalla->midx-250, Pantalla->midy-100, "Pixeles de alto: ");
	//Funcion para capturar cada char ingresado por el usuario.
	intextxy(Pantalla->midx+150, Pantalla->midy-100, strRen);

    //Despues pide el numero de columnas.
    outtextxy(Pantalla->midx-250, Pantalla->midy+100, "Pixeles de ancho: ");
    intextxy(Pantalla->midx+150, Pantalla->midy+100, strCol);

    /**El texto capturado se convierte a numero entero**/
	//se convierte la cadena capturada a un numero entero.
	*ren=atoi(strRen);
    *col=atoi(strCol);

    settextstyle(4, 0, 3);
    //Proceso de espera.
    cleardevice();
	outtextxy(Pantalla->midx, Pantalla->midy, "Procesando...");
    delay(1000);
    outtextxy(Pantalla->midx, Pantalla->midy+200, "Enter para avanzar");

    //Se pone getch para detener la animacion y con un enter continuar.
	getch();
}

    //Captura las teclas ingresadas para ancho y altura
void intextxy(int x, int y, char text[])
{
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

    //Pone el grill en color negro, para simular vacio
void SetBlackColor(int **Colores,int NR, int NC, TMalla *Grill)
{
        int i,j;
        for(i=0;i<NR;i++)
        {
            printf("\n");
            for(j=0;j<NC;j++)
            {
                //Se recorre la columna de renglones y se asigna a cada valor de la fila 0 el cual es el valor para el color negro.
                (*(*(Colores+i)+j))=8;
                printf("| %d |",*(*(Colores+i)+j));
            }
        }
        Grill->NRen=NR;
        Grill->NCol=NC;
        printf("\nRen: %d \nCol: %d",Grill->NRen,Grill->NCol);
}

/**** --------------------------------------------------------Funciones para ABRIR ARCHIVO Proyecto--------------------------------------------------------*****/

    //Pide al usuario el nombre del proyecto
void PedirNombre(char NFile[30],TPantalla *Pantalla)
{
    //Acomodar texto
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    int size=4;
    settextstyle(8,HORIZ_DIR,size);
    //Se imprime el mensaje para insertar el texto
    outtextxy(Pantalla->midx, Pantalla->midy-100, "Nombre del Proyecto: ");
    //Se captura letra por letra el texto ingresado
    intextxy(Pantalla->midx, Pantalla->midy+150, NFile);

    printf(" \n-------->Nombre capturado : %s\n",NFile);
}

    //Compara el nombre ingresado con el de la lista de nombres en donde se almacenan
int CompararNombre(char Nombre[30])
{
    //Axuliares
        int bol=0;
        int longcadena;

        //Se genera el nombre+.txt;
        char auxnombre[30];
        strcpy(auxnombre,Nombre);
        longcadena=strlen(auxnombre);
        auxnombre[longcadena-1]='\0';
        strcat(auxnombre,".txt");

        char strnombre[30];

    //Archivo de lectura
        FILE * ListaNombres;
        ListaNombres=fopen("NombresArchivos.txt","r");

        //debug
    printf("Nombre ingresado .txt:%s\n",auxnombre);

    //Extraer nombre por nombre
         if(ListaNombres)
        {
            while(!feof(ListaNombres))
            {
                fscanf(ListaNombres,"%s",strnombre);
                printf("\nNombre a comparar .txt:%s\n",strnombre);
                bol=strcmp(strnombre,auxnombre);
                printf("Boleano: %d",bol);
                if(bol==0)
                {
                    printf("\nEncontrado! ");
                        bol=1;
                    //Se encontro el nombre.
                    break;
                }
            }//Fin de while
    }
    printf("\nboleano: %d",bol);
    fclose(ListaNombres);
    return bol;
}

    //Funcion para buscar el proyecto que guardo el usuario si es que se encontro en la lista.
int  Abrir_Comparar(char NombreArchivo[30], TPantalla *P,TMalla *Grill,int **Colores)
{
    int i,j,color,bol=0,longcadena,band;

    char strnombre[30];

    strcpy(strnombre,NombreArchivo);
    longcadena=strlen(strnombre);
    strnombre[longcadena-1]='\0';
    strcat(strnombre,".txt");

    printf("\nNombre Archivo Ingresado: %s\n\n",strnombre);
    char auxnombre[30];

    /**Archivo solo de lectura ya existente **/
    FILE *NombresProyectos;
    NombresProyectos=fopen(strnombre,"r");

    if(NombresProyectos!=NULL)
    {
        printf("\nHola");
                    /**Se extraen numero de renglones y columnas**/
                    fscanf(NombresProyectos,"%d",&Grill->NRen);
                    fscanf(NombresProyectos,"%d",&Grill->NCol);
                    printf("\Proyecto cargado: Ren->%d  Col ->%d",Grill->NRen,Grill->NCol);
                    band=AsignaMemBidimensional(&Colores,Grill->NRen,Grill->NCol);
                /**Se encontro el archivo de texto**/
                    Mensaje(P,1);
                    bol=1;

            if(band==1)
                {
                         /**Se extraen los colores **/
                    printf("\n\nColores leidos: ");
                    for(i=0;i<Grill->NRen;i++)
                    {
                        printf("\n");
                            for(j=0;j<Grill->NCol;j++)
                            {
                                fscanf(NombresProyectos,"%d",&color);
                                (*(*(Colores+i)+j))=color;
                                printf("| %d |",*(*(Colores+i)+j));
                            }
                    }
                }

    }else{
                /**El archivo no existe**/
                   // Mensaje(P,-2);
    }
     fclose(NombresProyectos);
     printf("\nProyecto Cerrrado");
    /**No se encontro el nombre del archivo ingresado. **/
    if(bol==0)
    {
        //Mensaje(P,-1);
    }


    return(band);
}


/**** --------------------------------------------------------Funciones para RECURSOS EN PROYECTO --------------------------------------------------------*****/

//Funcion que imprime el espacio de trabajo y sobre el cual se maneja el programa. **/
void Proyecto(TPantalla *Pantalla,TMalla *Grill, TMalla *VistaPrevia, int **ColoresProyecto,char Nombre[30],int *color)
{
        printf("\nYa estamos en proyecto");
        cleardevice();
        delay(1500);
        int x,band,y;
        //Funcion que divide el proyecto y crea margenes
        DividirPantalla(Pantalla->quartx, Pantalla->midy, Pantalla->maxx, Pantalla->maxy,Pantalla->quarty,Grill,VistaPrevia);
          printf("\nDividirPantalla");
        //Funcion que dibuja la barra de opciones.
        DibujarOpciones(0,0,((Pantalla->quartx)*(3))/4,50,Pantalla->maxx); //Pix,Piy,Pfx,Pfx,Pfx;
        //Imprime los colores disponiles en la pantalla.
        DibujarColores((Pantalla->quartx*3)+20,Pantalla->quarty*3,Pantalla->maxx-20,Pantalla->maxy-20);
        //Imprime el color que se esta utilizando en el momento.
        DisposicionColorActual((Pantalla->quartx*3)+20,(Pantalla->quarty*3)-40,Pantalla->maxx-10, (Pantalla->quarty*3)-10,0);

        DibujarGrill(Grill,ColoresProyecto);

        VistaPrevia->NRen=Grill->NRen;
        VistaPrevia->NCol=Grill->NCol;

        DibujarGrill(VistaPrevia,ColoresProyecto);

        while(1)
        {
            delay(1);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN,x,y);
                //Se detecta el click del mouse
                band=ClickEnProyecto(x,y,Pantalla,Grill,VistaPrevia,ColoresProyecto,Nombre,&*color);
                if(band==0)
                {
                    break;
                }
            }
        }
}

//Divide las acciones segun en donde cickleo el usuario.
int ClickEnProyecto(int x, int y, TPantalla *P, TMalla *Grill, TMalla *VistaPrevia, int **Colores,char Nombre[30],int *color)
{
    int band;
    int xBarra=(P->quartx*3)/4;
    int bol;
    /**Abajo de la barra de herramientas**/
    if(y>60&&y<P->maxy-10)
    {
        band=1;
        /**Area de Grill**/
        if(x>10&&x<(P->quartx*3)-10)
        {
            ColoreaBarAndSave(x,y,P,*color,Grill,Colores,VistaPrevia);
        }

        /**Area de colores**/
        if(x>(P->quartx*3)+20&&y>P->quarty*3&&x<P->maxx-10&&y<P->maxy-10)
        {
                    /*Se obtiene el color donde se clickeo*/
                   (*color)=getpixel(x,y);
                    /*Se asigna el color al color actual*/
                    BarColorActual((P->quartx*3)+20,(P->quarty*3)-40,P->maxx-10, (P->quarty*3)-10,*color);
        }
    /**Barrra de Herramientas**/
    }else
    {
        band=0;
            if(y>5&&y<45)
            {
                cleardevice();
                /**New**/
                if(x>5&&x<xBarra-5)
                {
                        bol=Aviso(P,1);
                        if(bol==1)
                        {
                            LiberarMemoria(Grill,VistaPrevia,Colores);
                           OpcionDeInicio(1,P,Grill,VistaPrevia,Colores,Nombre);
                        }
                            Proyecto(P,Grill,VistaPrevia,Colores,Nombre,&*color);
                }
                /**Open**/
                if(x>xBarra+5&&x<(xBarra*2)-5)
                {
                        bol=Aviso(P,2);
                        if(bol==1)
                        {
                            LiberarMemoria(Grill,VistaPrevia,Colores);
                           OpcionDeInicio(2,P,Grill,VistaPrevia,Colores,Nombre);
                        }
                            Proyecto(P,Grill,VistaPrevia,Colores,Nombre,&*color);
                }
                /**Save **/
                if(x>(xBarra*2)+5&&x<(xBarra*3)-5)
                {
                    /**Guarda los cambios y regresa al proyecto **/
                        GuardarNombreGenerico(P,Nombre,Colores, Grill,1);
                        delay(100);
                         Proyecto(P,Grill,VistaPrevia,Colores,Nombre,&*color);
                }
                /**Save As**/
                if(x>(xBarra*3)+5&&x<(xBarra*4)-5)
                {
                        GuardarNombreGenerico(P,Nombre,Colores, Grill,2);
                        delay(100);
                        Proyecto(P,Grill,VistaPrevia,Colores,Nombre,&*color);
                }
                /**Salir**/
                if(x>P->maxx-200&&x<P->maxx-5)
                {
                        bol=Aviso(P,4);
                        if(bol==1)
                        {
                            LiberarMemoria(Grill,VistaPrevia,Colores);
                            OpcionDeInicio(3,P,Grill,VistaPrevia,Colores,Nombre);
                        }
                          Proyecto(P,Grill,VistaPrevia,Colores,Nombre,&*color);
                }
            }
    }

}

//Actualiza la pantalla con los colores guardados en el arreglo bidimensional apuntador a enteros que guarda el codigo del color
void ImprimirColores(int **Colores, TMalla *Grill)
{
    int i,j;
    printf("\n\nActualizacion de colores.");
    for(i=0;i<Grill->NRen;i++)
    {
        printf("\n");
        for(j=0;j<Grill->NCol;j++)
        {
            printf("|%d|",*(*(Colores+i)+j));
        }
    }
}

//Actualiza la vista del grill si se hizo alguna modificacion en colores.
void  ActualizarVistaPrevia(TMalla *VistaPrevia, int ren, int col)
{
        int i,j;
        for(i=0;i<VistaPrevia->NRen;i++)
        {
            for(j=0;j<VistaPrevia->NCol;j++)
            {
                if(i==ren&&j==col)
                {
                    bar((VistaPrevia->xi+((VistaPrevia->largo)*j))+1,(VistaPrevia->yi+((VistaPrevia->alto)*i))+1,(VistaPrevia->xi+(VistaPrevia->largo*(j+1)))-1,(VistaPrevia->yi+((VistaPrevia->alto)*(i+1)))-1);
                }
            }
        }
}

//Se busca donde se clickeo y se guarda
void ColoreaBarAndSave(int  x,int y,TPantalla *P, int color, TMalla *Grill,int **Colores, TMalla *VistaPrevia)
{
        int i,j;
        for(i=0;i<Grill->NRen;i++)
        {
            for(j=0;j<Grill->NCol;j++)
            {
                /**Si cumple la condicion se encuentra en el bar i,j **/
                if(x>Grill->xi+((Grill->largo)*j)&&x<Grill->xi+(Grill->largo*(j+1)))
                   {
                       if(y>Grill->yi+((Grill->alto)*i)&&y<Grill->yi+(Grill->alto*(i+1)))
                          {
                              setfillstyle(SOLID_FILL,color);
                            bar((Grill->xi+((Grill->largo)*j))+1,(Grill->yi+((Grill->alto)*i))+1,(Grill->xi+(Grill->largo*(j+1)))-1,(Grill->yi+((Grill->alto)*(i+1)))-1);
                            (*(*(Colores+i)+j))=color;
                            ActualizarVistaPrevia(VistaPrevia,i,j);
                            ImprimirColores(Colores,Grill);
                          }
                   }
            }
        }
}


/**** --------------------------------------------------------Funciones para BOTONES EN PROYECTO --------------------------------------------------------*****/

/**GUARDAR & GUARDAR COMO**/

void GuardarNombreGenerico( TPantalla *Pantalla,char Nombre[30], int **Colores, TMalla *Grill,int tipoSave)
{
    int bol,bol1;
    char Nullvacio[30]="NULL";
    /**Nombre identico a vacio,  ->Archivo sin guardar ó seleccion de boton Save As**/
        if(!strcmp(Nombre,Nullvacio) && tipoSave==1)
        {
             Guardar(Nombre,Colores,Grill);
        }else{
                PedirNombre(Nombre,Pantalla);
                bol=CompararNombre(Nombre);
                if(bol==1)
                {
                    /**Se encontro un archivo con el nombre ingresado**/
                    cleardevice();
                    bol1=Aviso(Pantalla,5);
                    /**El usuario desea sobreescribir los datos del archivo ya existente.**/
                    if(bol1==1)
                    {
                         Guardar(Nombre,Colores,Grill);
                    }

                }else{
                    /**Nombre sin guardar, por lo tanto se agrega a lista y guarda archivo**/
                        InsertarEnNombres(Nombre);
                        Guardar(Nombre,Colores,Grill);
                }

        }
}

void InsertarEnNombres(char Nombre[30])
{
    int longcadena;
    FILE *ListaNombres;
    /**Abre archivo al final del documento, para escritura.**/
    ListaNombres=fopen("NombresArchivos.txt","a");

    char txt[5]=".txt";
    char auxnombre[30];
    strcpy(auxnombre,Nombre);
    longcadena=strlen(auxnombre);

    auxnombre[longcadena-1]='\0';
    strcat(auxnombre,txt);

    /**Se agrega nombre al final del documento.**/
    fprintf(ListaNombres,auxnombre);
    fprintf(ListaNombres,"\n");
    fclose(ListaNombres);
}

void Guardar(char Nombre[30], int **Colores, TMalla *Grill)
{
    int longcadena;
      /**Una vez que se encuentra el nombre o se desea guardar se añade la extension.txt a un auxiliar y no perder el nombre original**/
        char NombreAux[30];
         char txt[5]=".txt";
        strcpy(NombreAux,Nombre);

    longcadena=strlen(NombreAux);
    NombreAux[longcadena-1]='\0';
    strcat(NombreAux,txt);

    FILE *GuardarProyecto;
    GuardarProyecto=fopen(NombreAux,"w");

    int i,j;

    fprintf(GuardarProyecto,"%d ",Grill->NRen);
    fprintf(GuardarProyecto,"%d\n",Grill->NCol);
    for(i=0;i<Grill->NRen;i++)
    {
        for(j=0;j<Grill->NCol;j++)
        {
            fprintf(GuardarProyecto,"%d\t",(*(*(Colores+i)+j)));
        }
        fprintf(GuardarProyecto,"\n");
    }
    fclose(GuardarProyecto);
}


/**** --------------------------------------------------------ALERTAS CAMBIOS EN PROYECTO --------------------------------------------------------*****/
void Mensaje(TPantalla *P,int opcionmensaje)
{
        cleardevice();
        int size=4;
        settextstyle(8,HORIZ_DIR,size);
        switch (opcionmensaje)
        {
            //Archivo encontrado
        case 1:
            outtextxy(P->midx,P->midy,"Abriendo proyecto...");
            delay(500);
            size=1;
            outtextxy(P->midx,P->midy+150,"Cargando recursos...");
            delay(1000);
            break;
            //Salir
            case 0:
                outtextxy(P->midx, P->midy, "Cerrando...");
                delay(500);
                size =1;
                outtextxy(P->midx,P->midy+150,"PIXLANT V2.1.0");
                delay(1500);
                break;
            //Error Archivo no existente
            case -1:
                    outtextxy(P->midx,P->midy,"Nombre no existente intente de nuevo.");
                    delay(1500);
                break;
            //Archico corrupto
            case -2:
                outtextxy(P->midx,P->midy,"Archivo de nombres corrupto. Verifique codigo. ");
                delay(1500);
                closegraph();
                break;
        }
}



