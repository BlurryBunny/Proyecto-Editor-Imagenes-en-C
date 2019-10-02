#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED


//Disposicion de la pantalla.
typedef struct
{
        int maxx;
        int maxy;
        int midx; //Pantalla maxx/2.
        int midy;
        int quartx; //Pantalla maxx/4.
        int quarty;
}TPantalla;

//Estructura que se utilizara para la malla  y previsualizador
typedef struct
{
    int xi;
    int xf;
    int yi;
    int yf;
    //Numero de renglones y columnas
    int NRen;
    int NCol;
    //Diferencia entre (xf-xi)/NCol ó  (yf-yi)/NRen;
    int largo;
    int alto;
}TMalla;

/**Asignacion de memoria**/
int AsignaMem(TMalla **ptr);
int AsignaMemBidimensional(int ***ptr, int NR, int NC);
int AsignaMemDis(TPantalla **ptr);
void LiberarMemoria(TMalla *Grill, TMalla *VistaPrevia, int **Ptr);

/**Opciones de Menu (Imprimir, Click en opciones, Verificar funciones)**/
void Menu(TPantalla *Pantalla);
int Click(int *x,int *y, TPantalla PantallaDim);
int CheckMouseMENU(int x, int y, TPantalla *P);
void  OpcionDeInicio(int tipo,TPantalla *P, TMalla *Grill,TMalla *VistaPrevia,  int **ColoresProyecto,char NombreFile[30]);

/**Nuevo Proyecto**/
void AsignarValoresPantalla(TPantalla *Pantalla);
void PedirDimensiones(int *ren, int *col, TPantalla *Pantalla);
void SetBlackColor(int **Colores,int NR, int NC, TMalla *Grill);
void Proyecto(TPantalla *Pantalla,TMalla *Grill, TMalla *VistaPrevia, int **ColoresProyecto,char Nombre[30],int *color);

/**Abrir **/
void PedirNombre(char NFile[30],TPantalla *Pantalla);
int  Abrir_Comparar(char NombreArchivo[30], TPantalla *P,TMalla *Grill,int **Colores);

//Se manda llamar a Proyecto().

/**Cerrar**/
void Mensaje(TPantalla *P,int opcionmensaje);

/**Acciones dentro de proyecto**/

int ClickEnProyecto(int x, int y, TPantalla *P, TMalla *Grill, TMalla *VistaPrevia, int **Colores,char Nombre[30],int *color);
void intextxy(int x, int y, char text[5]);

/*Impresion de proyecto*/

void DividirPantalla(int quartx, int midy,int maxx,int maxy,int quarty,TMalla *Grill,TMalla *VistaPrevia);
void DibujarOpciones(int x1,int y1,int x2,int y2,int maxx);
void DibujarColores(int x1,int y1, int x2, int y2);
void DisposicionColorActual(int x1,int y1, int x2, int y2,int color);
void DibujarGrill(TMalla *Grill, int **Colores);
void BarColorActual(int x1,int y1, int x2, int y2, int color);


/*Guardar*/
void GuardarNombreGenerico( TPantalla *Pantalla,char Nombre[30], int **Colores, TMalla *Grill,int tipoSave);
void Guardar(char Nombre[30], int **Colores, TMalla *Grill);
void InsertarColores(int **Colores, char Nombre[30],TMalla *Grill);
int CompararNombre(char Nombre[30]);
void InsertarEnNombres(char Nombre[30]);

/*Modificar colores*/
void ColoreaBarAndSave(int  x,int y,TPantalla *P, int color, TMalla *Grill,int **Colores, TMalla *VistaPrevia);
void  ActualizarVistaPrevia(TMalla *VistaPrevia, int ren, int col);
void ImprimirColores(int **Colores, TMalla *Grill);

/*Botones*/
int Aviso(TPantalla *P, int opcion);
int Respuesta(TPantalla *P);
int CompararRespuesta(int x, int y,TPantalla *P);
void DibujarBotonesSiNo(TPantalla *P, char RPositiva[],char RNegativa[]);

#endif // CABECERA_H_INCLUDED
