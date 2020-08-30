#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h> 

char *CI;
bool b64;
int cotaSuperior=500000;
int cotaInferior=111111;

char *parseCI()
{
	return NULL;
}

int verifDigit(int ciRaw)
{
	return 0;
}

int calcRandomCI(bool valorAcotado)
{
	time_t sec;
	time(&sec);
	srand((unsigned int) sec);
	int randomCiRaw = rand() % (cotaSuperior - cotaInferior + 1) + cotaInferior; 
	return randomCiRaw;
}

void optHelp()
{
	printf("Utilidad para CI Uruguayas.\nAgustin Perez Prieto - 2020.\nNo me hago responsable por usos ilicitos e irresponsables de este programa.\nEl objetivo de esto es para testing de validaciones relacionadas con CI.\nEj: validaciones en el ingreso de un ABML.\n\n-g: Genera una CI completamente valida aleatoria (UTILIZAR CON RESPONSABILIDAD).\n-G: Genera una CI aleatoria la cual puede estar fuera de rango, respecto a las CI existentes en el registro nacional.\n-v: Valida si una CI es correcta:\n	Sintaxis: -v [CI]\n	Ej: -v 1.111.111-1\n\n-d: Genera un digito verificador a una CI dada como argumento:\n	Sintaxis: -d: [CI]\n	Ej: -d 1.111.111\n\nLicenciado bajo GPL v3.0, hace lo que quieras con esta ranciada.\nhttps://github.com/agustin-perez/utilidadciv2\n");
}

int main (int argc, char **argv)
{
	char *cvalue = NULL;
	int index;
	int c;

	opterr = 0;

	while ((c = getopt (argc, argv, "gGvdbh-:")) != -1)
	{
		switch (c)
		{
			case 'g':
				printf("Ci generada: %d",calcRandomCI(true));
				return 0;
			case 'G':
				printf("Ci generada: %d",calcRandomCI(false));
				return 0;
			case 'v':
				cvalue = optarg;
				break;
			case 'd':
				cvalue = optarg;
				break;
			case 'b':
				b64=true; 
				break;
			case 'h':
				optHelp();
				return 0;
			case '-': 	
				optHelp();
				return 0;
			case '?':
				if (optopt == 'c')
				{
					fprintf (stderr, "Dicha opcion requiere un argumento.\nUtilice \"-h\" para ver ayuda\n", optopt);
					return 1;
				}
				if (isprint (optopt))
				{
					fprintf (stderr, "Parametro invalido `-%c'.\nUtilice \"-h\" para ver ayuda\n", optopt);
					return 1;
				}
				fprintf (stderr,"Parametro incorrecto.\nUtilice \"-h\" para ver ayuda\n", optopt);
				return 1;
			default:
				abort();
		}
	}
	return 0;
}