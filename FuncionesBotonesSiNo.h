#ifndef FUNCIONESBOTONESSINO_H_INCLUDED
#define FUNCIONESBOTONESSINO_H_INCLUDED

int Aviso(TPantalla *P, int opcion)
{
        int bol=0;
        int size=4;
        settextstyle(8,HORIZ_DIR,size);
        setcolor(WHITE);

        switch(opcion)
        {
        case 1:
            outtextxy(P->midx,P->quarty+200,"¿Estas seguro de crear un archivo nuevo?");
            size=3;
            outtextxy(P->midx,P->midy,"Todos los cambios sin guardar se perderan.");
            DibujarBotonesSiNo(P,"Si","No");
            bol=Respuesta(P);
            break;
        case 2:
            outtextxy(P->midx,P->quarty+200,"¿Estas seguro de abrir un archivo ya existente?");
            size=3;
            outtextxy(P->midx,P->midy,"Todos los cambios sin guardar se perderan.");
            DibujarBotonesSiNo(P,"Si","No");
            bol=Respuesta(P);
            break;
        case 3:
           DibujarBotonesSiNo(P,"Aceptar","Cancelar");
            bol=Respuesta(P);
            break;
        case 4:
            outtextxy(P->midx,P->quarty+200,"¿Estas seguro que deseas salir?");
            size=3;
            outtextxy(P->midx,P->midy,"Todos los cambios sin guardar se perderan.");
            DibujarBotonesSiNo(P,"Si","No");
            bol=Respuesta(P);
            break;
        case 5:
            outtextxy(P->midx,P->quarty+200,"Ya existe un archivo con el mismo nombre.");
            size=3;
            outtextxy(P->midx,P->midy,"¿Deseas sobreescribir los datos en el archivo?");
            DibujarBotonesSiNo(P,"Si","No");
            bol=Respuesta(P);
            break;
        }
        return bol;
}

int Respuesta(TPantalla *P)
{
    int x,y,bol;
    clearmouseclick(WM_LBUTTONDOWN);
        while(1)
        {
            delay(1);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN,x,y);
                bol=CompararRespuesta(x,y,P);
                if(bol!=0)
                {
                  break;
                }
            }
        }
        return bol;
}

int CompararRespuesta(int x, int y,TPantalla *P)
{
    int bol=0;
        if(x>P->midx-250&&x<P->midx-150)
        {
            if(y>P->midy+200&&y<P->midy+250)
            {
                bol=1;
            }
        }
        if(x>P->midx+150&&x<P->midx+250)
        {
             if(y>P->midy+200&&y<P->midy+250)
            {
                bol=-1;
            }
        }
    return bol;
}

void DibujarBotonesSiNo(TPantalla *P, char RPositiva[],char RNegativa[])
{
    setfillstyle(SOLID_FILL,WHITE);
    //Boton izquierda.
    bar(P->midx-250,P->midy+200,P->midx-150,P->midy+250);
    //Boton derecha.
    bar(P->midx+250,P->midy+200,P->midx+150,P->midy+250);

     int size=3;
    settextstyle(8,HORIZ_DIR,size);
    setcolor(BLACK);
    outtextxy(P->midx-220,P->midy+230,RPositiva);
    outtextxy(P->midx+180,P->midy+230,RNegativa);
}

#endif // FUNCIONESBOTONESSINO_H_INCLUDED
