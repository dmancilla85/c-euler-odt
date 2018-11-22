#ifndef EULER_H_INCLUDED
#define EULER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <getopt.h>
#include <float.h>

#define DEBUG 		0 		// Modo DEBUG
#ifndef ALPHA
#define ALPHA	1
#endif

#ifndef LAMBDA
#define LAMBDA	1
#endif

struct Coord {
	double x;
	double y;
	double dxdy;
};

void mostrar_ayuda()
{
	printf("<< MODO DE USO - ALGORITMO DE EULER >>\n\n"
	"Sintaxis:\n\t./euler -x xValue -y yValue -h deltaX -n nVeces -m ecuacion\n"
	"OPCIONES:\n"
	"\t-x xValue\tValor inicial de x.\n"
	"\t-y yValue\tValor inicial de y.\n"
	"\t-h deltaX\tIncremento delta h.\n"
	"\t-n nVeces\tCantidad de iteraciones a realizar.\n"
	"\t-m ecuacion\tSeleccionar ecuación a resolver.\n"
	"\t\t 1 y' = 2x - 3y + 1\tPara prueba.\n"
	"\t\t 2 V' = (l*exp(-a*t))V\tDinamica del crecimiento de tumores.\n"
	"\t\t 3 y' = cos(x)^2 - sen(y)^2\tPrueba 2.\n"
	"\nEjemplo:\n\t./euler -x 1 -y 5 -h 0.1 -n 10 -m 1\n");
}

void sintaxis()
{
	printf( "Ejemplo de uso:\n\teuler -x 1 -y 5 -h 0.1 -n 10 -m 1\nAyuda:\n\teuler -h\n");
}

/* Método de EULER - Implementación 1
 * h = x(n) - x(n-1) 	Es el incremento
 * x0 					Punto inicial
 * y0					Punto inicial
 */
void eulerMethod(struct Coord *eul, double h, struct Coord p0, 
	double (* fp)(double, double), int n){

	int i = 0;

	for(i = 0; i < n; i++){
		
		// Paso inicial
		if(i == 0){
			eul[i].x = p0.x;
			eul[i].y = p0.y;
			eul[i].dxdy = 0.0;
		} else {
			// Calculo xi = x(i-1) + h
			eul[i].x = eul[i - 1].x + h;
			
			// Calculo yi = y[i-1] + h * f(x[i-1], y[i-1])
			eul[i].y = eul[i - 1].y + h * fp(eul[i - 1].x, eul[i - 1].y);
			
			// Calculo dxdy(i) = f(xi, yi)
			eul[i].dxdy = fp(eul[i].x, eul[i].y);

		}
	}
}

/*
 * Obtener el error relativo de un punto calculado
 */
double relativeError(double simulatedValue, double realValue){

	double relError = DBL_MAX; // Infinito

	if(realValue != 0.0)
		relError = (double)(abs(simulatedValue - realValue)/realValue) * 100;

	return relError;
}

double rungeKutta(){
	return 0.0;
}

#endif // EULER_H_INCLUDED

