# include <stdio.h>
int multiplo(int, int);
void main(void)
{
int NU1, NU2, RES;
printf("\nIngresa los dos n�meros: ");
scanf("%d %d", &NU1, &NU2);
RES = multiplo(NU1, NU2);
if (RES)
printf("\nEl segundo n�mero es m�ltiplo del primero");
else
printf("\nEl segundo n�mero no es m�ltiplo del primero");
}
int multiplo(int N1, int N2)
{
int RES;
if ((N2 % N1) == 0)
RES = 1;
else
RES = 0;
return (RES);
}
