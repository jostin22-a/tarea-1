/* TORRE DE HANOY

Escribe un programa (se recomienda que sea recursivo) que d� soluci�n al problema de las torres de Hanoi.
El enunciado es el siguiente: Se dispone de una torre formada por varios discos de diferentes di�metros denominada torre O (origen),
donde cada disco es de di�metro inferior a todos los que est�n por debajo. Se dispone de otras dos torres para dejar discos, una denominada torre A (auxiliar) y otra torre D (destino).
El problema consiste en pasar todos los discos de la torre O a la torre D respetando dos normas muy simples:

Los discos se pasan de una torre a otra de uno en uno.
Nunca un disco de mayor di�metro puede estar sobre otro de menor di�metro.
Se preguntar� al inicio del programa por el tama�o de la torre O (entendiendo que tendr� el n�mero de discos indicados, con alg�n l�mite preestablecido).
Las torres A y D estar�n inicialmente vac�as.
Se debe ofrecer la soluci�n que da el programa a este problema paso a paso, mostrando el resultado de una forma gr�fica. El inicio podr�a ser algo as�:

*
    ***
   *****
*******
*********
    ===========		==========		==========
O				A				D


Formula para calcular movimientos m�nimos necesarios:
m = 2^n -1

http://www.rodoval.com/heureka/hanoi/
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void imprime( int *tab, int fil, int col, int ultNum )
/*tab: pntero a la madriz 1D que simula una matriz 2D de torres y discos */
/*fil: 3 torres */
/*col: cantidad de ruedas */
/*ultNum: sierve para centrar visualmente */
{
    /*
    Precondici�n:
    *tab	Puntero a una matriz de tipo entero.
    fil		Entero que indica el numero de filas de la matriz.
    col		Entero que indica el numero de columnas de la matriz.
    disc	Par�metro de tipo entero que indica el numero de discos usados.
    ultNum	Entero que indica el numero que esta usando el disco mas grande.
    */


    int f, c; /*f: indice de filas. c: indice de columnas*/
    int i, esp; /* paa bucles internos. esp: cantidad de espacios para centrar cada disco*/


    for( c=col-1; c >= 0; c-- )//Itera desde la parte superior de las torres hasta abajo (de arriba hacia abajo en las columnas).
    {
        for( f=0; f < fil; f++ ) //Itera por cada torre (fil son las filas reales pero representan las torres aqu�).
        {
            esp = ( ultNum - tab[col*f+c] )/2; // Calcula cu�ntos espacios necesita imprimir antes de cada disco, para centrarlo visualmente.

// Espacios a la izquierda
            for( i=0; i < esp; i++ )// Imprime espacios a la izquierda del disco
                printf( " " );

// Imprime los comodines
            for( i=0; i < tab[col*f+c]; i++ ) // Imprime el disco como una l�nea de asteriscos.
                printf( "*" );

// Espacios a la derecha
            for( i=0; i < esp; i++ )// Espacios a la derecha para centrar el disco.
                printf( " " );

            printf( "\t" );
        };

        printf( "\n" );
    };


};


void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest ) // para mover un disco de una fila a otra y la imprime
{
    /*
    Precondici�n:
    *tab	Puntero a una matriz de tipo entero.
    fil		Entero que indica el numero de filas de la matriz.
    col		Entero que indica el numero de columnas de la matriz.
    disc	Par�metro de tipo entero que indica el numero de discos usados.
    ultNum	Entero que indica el numero que esta usando el disco mas grande.
    filOrig	Entero que indica el numero de fila de la matriz en la cual hay que coger el numero/disco
    filDest	Entero que indica el numero de fila de la matriz en la cual hay que dejar el numero/disco.
    Poscondici�n:
    Se mueve el disco y se llama a la funci�n que imprime el tablero.
    */


    int cO=col-1, cD=col-1;
    //c0: columna origen
    //cD: columna destino


// Se busca el disco que se encuentre mas arriba y por lo tanto el mas peque�o de la fila de origen.
    while( cO >= 0  &&  tab[col*filOrig+cO] == 0 )
    {
        cO--;
    };
    if( cO < 0 )
        cO = 0;// Busca el primer disco no vac�o en la torre origen filOrig.

// Ahora se calcula cual es la posici�n libre mas arriba de la fila de destino
    while( cD >= 0  &&  tab[col*filDest+cD] == 0 )
    {
        cD--;
    };

// Se mueve el disco de la fila de origen a la de destino:
    tab[col*filDest+cD+1] = tab[col*filOrig+cO];
    tab[col*filOrig+cO] = 0;//Borra la posici�n anterior

// Se imprime el tablero:
    imprime( tab, fil, col, ultNum );
};


void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )
{
    /*
    Precondici�n:
     *tab	Puntero a una matriz de tipo entero.
     fil		Entero que indica el numero de filas de la matriz.
     col		Entero que indica el numero de columnas de la matriz.
     disc	Par�metro de tipo entero que indica el numero de discos usados.
     ultNum	Entero que indica el numero que esta usando el disco mas grande.
     O,A,D	Tres enteros que indican la fila desde donde se ha de coger el disco y a donde se ha de traspasar. La primera vez que se llama a hanoi tienen los valores de: 0 ,1 y 2 respectivamente.
    Poscondici�n:
     Se llama recursivamente a hanoi hasta resolver el tablero.
    */


    if( disc==1 )// si hay un solo disco lo mueve directamente
    {
// Se borra la pantalla, se imprime la tabla y se hace una pausa que varia dependiendo del numero de discos:
        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );// limpia pantalla y mueve e disco
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
        // Ajusta el retardo dependiendo del n�mero de discos para que sea m�s o menos r�pido.
    }
    else
    {
        hanoi( tab, fil, col, disc-1, ultNum, O, D, A );// Ajusta el retardo dependiendo del n�mero de discos para que sea m�s o menos r�pido.

        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);

        hanoi( tab, fil, col, disc-1, ultNum, A, O, D );
    };

};
//Bucle doble para consumir tiempo
void delay(int tiempo)
{

    int c, d;
    while(tiempo >= 0)
    {
        for (c = 1; c <= 10000; c++)
            for (d = 1; d <= 10000; d++)
            {}
        tiempo--;
    }

}

main()
{
    int fil=3, col, *tablero = NULL;
    int f, c, disc=1, ultNum;
    /* fil = 3: n�mero de torres
       col: se pedir� al usuario
       tablero: puntero a la matriz din�mica que representa las torres.
       disc: valor del disco inicial
       ultNum: se usar� para centrar discos al imprimir.*/


    printf( "Indique el numero de discos: " );
    scanf( "%i", &col );


    tablero = (int *)malloc( sizeof(int)*fil*col ); // reserva memoria para una matriz de 3 x col


// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
    for( f=0; f < fil; f++ )
        for( c=col-1; c >= 0; c-- )
            if( f==0 )
            {
                tablero[col*f+c] = disc;
                disc+=2;
            }
            else
                tablero[col*f+c] = 0;

    ultNum = disc;

// Se imprime el tablero antes de iniciar ning�n movimiento:
    system("cls");
    imprime( tablero, fil, col, ultNum );
    delay(6);


// Se llama a hanoi para comenzar "la partida":
    hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 );
};
