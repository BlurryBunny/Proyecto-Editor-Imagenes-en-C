#ifndef ASIGNACIONMEMANDVALUE_H_INCLUDED
#define ASIGNACIONMEMANDVALUE_H_INCLUDED

/**Divide la pantalla en las secciones para poder trabajar con el editor**/
void AsignarValoresPantalla(TPantalla *Pantalla)
{
        Pantalla->maxx=getmaxx();
        Pantalla->maxy=getmaxy();
        Pantalla->midx=getmaxx()/2;
        Pantalla->midy=getmaxy()/2;
        Pantalla->quartx=getmaxx()/4;
        Pantalla->quarty=getmaxy()/4;
}

int AsignaMemDis(TPantalla **ptr)
{
        int band=0;
        *ptr=(TPantalla*)malloc(sizeof(TPantalla));
        if(*ptr!=NULL)
        {
            band=1;
        }
    return band;
}

int AsignaMem(TMalla **ptr)
{
    //bandera negada (sin memoria).
    int band=0;
    //Se asigna memoria al apuntador.
    *ptr=(TMalla*)malloc(sizeof(TMalla));

    if(*ptr!=NULL)     //ptr!=NULL
    {
        band=1;
    }

    return band;
}

int AsignaMemBidimensional(int ***ptr, int NR, int NC)
{
    //bandera negada (sin memoria).
    int i ,bol=0;
    *ptr=(int **)malloc(sizeof(int*)*NR); //Se agrega memoria al apuntador por el numero de renglones que tendra.
    if(*ptr!=NULL)
    {
        bol=1;
         /* Si el ciclo detecta que bol!=1 entonces se detendra y no asiganara memoria ya que se libero previamente la asignada a los valores posteriores y al apuntador.*/
        for(i=0;i<NR&&bol==1;i++)
        {
            *(*ptr+i)=(int*)malloc(sizeof(int)*NC);  //Se asigna memoria a cada renglon por el numero de columnas. de esta manera se tendra la dimension NRxNC
            if(*(*ptr+i)==NULL) //detecta que no se le asigno la memoria indicada al apuntador.
            {
                while((i--)>=0) //loop que recorre las asignaciones de memoria anteriores.
                {
                    free(*(*ptr+i)); //Se libera primero la asignacion de memoria de los renglones.
                }
                free(*ptr); //Se libera la memoria del apuntador.
                bol=0; //Por lo tanto la asignacion no fue exitosa bol=0;
            }
        }
    }
    return(bol);
}

void LiberarMemoria(TMalla *Grill, TMalla *VistaPrevia, int **Ptr)
{
    free(Grill);
    free(VistaPrevia);

    int i; // >> i es el contador del for. >> cont=0 para que aumente con cada liberacion de apuntador a entero en el arreglo dinamico.
    int bol=1;      //Boleano en 1 indicando que existe memoria desiganada para el arreglo dinamico de apuntador a enteros.
    for(i=Grill->NRen-1;i>=0&&bol==1;i--)
    {
        if(*(Ptr+i)!=NULL)
        {
            while(--i>=0)
            {
                free(*(Ptr+i));
                bol=0;
            }
            free(Ptr);
        }

    }
}


#endif // ASIGNACIONMEMANDVALUE_H_INCLUDED
