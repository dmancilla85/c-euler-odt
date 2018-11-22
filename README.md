# eulerMethod
A quick C implementation of the Euler method to solve ODE.
Compiled with GCC.

INSTRUCCIONES
=============
a. El ejecutable se encuentra en la carpeta /bin y está compilado en Linux.
b. Para ejecutar ./Euler

c. Sintaxis:
./Euler -x xValue -y yValue -h deltaX -n nVeces -m ecuacion

OPCIONES:
-x xValue		Valor inicial de x.
-y yValue		Valor inicial de y.
-h deltaX		Incremento delta h.
-n nVeces		Cantidad de iteraciones a realizar.
-m ecuacion		Seleccionar ecuación a resolver:

1 	y' = 2x - 3y + 1			(Para prueba).
2 	V' = (l*exp(-a*t))V			(Dinamica del crecimiento de tumores).
3	y' = cos(x)^2 - sen(y)^2	(Prueba 2).
	
d. Ejemplo de uso:
./Euler -x 1 -y 5 -h 0.1 -n 10 -m 1
 
e. Para ayuda:
./Euler -h

