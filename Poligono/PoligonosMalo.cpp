#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#define pi 3.14159265358979323846264338

int main()
{
    //Variables necesarias para initgraphic, el circulo y el poligono.
    int gd=DETECT,gm,centroxy=200,radio=150,lados,contador=0;
    float PIx,PIy,PFx,PFy;
    double angulo;

    initgraph(&gd,&gm,"C:\\TC\\BGI");
    delay(1000);
    //Pedir al usuario el numero de lados para dibujar el poligono.
    printf("Inserta el numero de lados: ");
    scanf("%d",&lados);


    //Abrir consola
    if(lados<=0)
    {
        printf("\nInserta un numero valido.\n");
    }else if(lados==1)
    {
        //Se inica la consola de graficos.
        //Creacion del circulo.
        circle(centroxy,centroxy,radio);
    }else
    {
        //Se definen los puntos iniciales
        for(angulo=0;angulo<=2*pi+0.1;angulo+=(2*pi/lados))
        {
            //Coordenadas de puntos finales en X y Y.
            PIx=cos((double)angulo)*(radio)+centroxy; //cateto adyascente para componentes en X
            PIy=sin((double)angulo)*(radio)+centroxy; //cateto opuesto para componentes en Y.
            if(contador!=0)
            {
                line(PIx,PIy,PFx,PFy);
            }
            //al momento de que contador sea 1 PFx & PFy tendran un valor y se trazara la linea.
            PFx=PIx;
            PFy=PFy;
            contador++;
        }
    }
    getch();
    closegraph();
    return(0);
}
