#include "euler.h"

double tumorDinamica(double x, double y)
{
	return (LAMBDA * exp(-ALPHA*x)) * y;
}

double fPrueba(double x, double y){

    return 2*x - 3*y + 1;
}

double fSenoCoseno(double x, double y){

    return cos(x)*cos(x) - sin(y)*sin(y);
}

int main( int argc, char* argv[] )
{

    struct Coord p0;
	double h;
	int n, i, mode, prm1,  prm2, option;


	// Verifica si se solicita ayuda
	if(argc == 2 && !DEBUG)
	{
		if(strcmp(argv[1], "-h") == 0)
		{
			mostrar_ayuda();
			return EXIT_FAILURE;
		}
	}

	// Tiene todos los parámetros requeridos?
	if(argc != 11 && !DEBUG)
	{
		printf("No se ingresaron todos los parametros obligatorios\n");
		sintaxis();
		return EXIT_FAILURE;
	}

	// Determino las variables ingresadas
	while ((option = getopt(argc, argv, "x:y:h:n:m:")) != -1)
	{
		switch (tolower(option))
		{
			case 'x':
				p0.x = atof(optarg);
				break;
			case 'y':
				p0.y = atof(optarg);
				break;
			case 'h':
				h = atof(optarg);
				break;
			case 'n':
				n = atoi(optarg);
				break;
			case 'm':
				mode = atoi(optarg);
				break;
			default:
				printf("Opciones incorrectas\n");
				exit(EXIT_FAILURE);
		}
	}


	if(mode < 1 || mode > 3)
	{
		printf("Opciones incorrectas\n");
		exit(EXIT_FAILURE);
	}

	printf("Valores ingresados:\nx=%.2f y=%.2f h=%.2f n=%d\n", p0.x, p0.y, h, n);

	p0.dxdy = 0.0;

	struct Coord eul[n];

	switch(mode)
	{
		case 1:
			eulerMethod(eul, h, p0, &fPrueba, n);
			break;

		case 2:
			eulerMethod(eul, h, p0, &tumorDinamica, n);
			break;

		case 3:
			eulerMethod(eul, h, p0, &fSenoCoseno, n);
			break;
        /*
		case 4:
			eulerMethod(eul, h, p0, &f, n);
			break;

		case 5:
			eulerMethod(eul, h, p0, &f, n);
			break;*/
	}

	for(i = 0; i < n; i++){
       printf("N: %d. x=%.2f y=%.2f dxdy=%.2f\n", i+1,
              eul[i].x, eul[i].y, eul[i].dxdy );
	}

	return EXIT_SUCCESS;
}
