/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "divisas.h"
#include "funciones_client.h"

void
divisas_1(char *host, char op)
{
	//system(CLEAR);
	CLIENT *clnt;
	char * *result_1;
	struct EstructuraDatos  comprar_divisas_1_arg;
	char * *result_2;
	struct EstructuraDatos  vender_divisas_1_arg;
	char * *result_3;
	char *listar_divisas_1_arg;
	char * *result_4;
	struct EstructuraDatos  buscar_info_divisa_1_arg;

	char * *resultado;

#ifndef	DEBUG
	clnt = clnt_create (host, DIVISAS, DIVISAS_VER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */





//Dependiendo de la opcion elegida en el menu, se elegira un servicio determinado.

// Si la opcion elegida es 1, se crearan las siguientes variables.


switch(op){
    

    // Modulo de compras
	case '1':
	comprar_divisas_1_arg.str = strdup("1"); // Le paso el valor de 1 al *str . (COn strdup se pasan valores a char *str (en lugar de strcmpy que sirve para str[]))
	
	result_1 = comprar_divisas_1(&comprar_divisas_1_arg, clnt); //Recibo el string result_1 correspondiente a la entrada de *str = 1.
	if (result_1 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
	}

	char str2[1000];
	char opcion1_origen, opcion1_salida;
	int i;
	sprintf(str2,"%s", (char *) *result_1);

	do{
	system(CLEAR);
	printf("Usted ha elegido la opcion de comprar divisas\n");
	printf("================================\nEl usuario actualmente posee\n\n");
	printf("%s", str2);
	printf("================================\n");
	printf("OPCIONES\n\n1)CLP\n2)USD\n3)EUR\n9)Volver\n===================\nSeleccione una opcion que represente la moneda a comprar:\n");
	fflush(stdin);
	scanf("%c",&opcion1_origen);

		switch(opcion1_origen){
			case '1':
			break;
			case '2':
			break;
			case '3':
			break;
			default:
			break;	
		}

	}while(opcion1_origen!='9');


//	strcpy(str2,*resultado);
//	printf("================================\nEl usuario actualmente posee\n");
//	printf("%s", str2);
//	scanf("%i", &i);
	break;

//	result_2 = vender_divisas_1(&vender_divisas_1_arg, clnt);
//	if (result_2 == (char **) NULL) {
//		clnt_perror (clnt, "call failed");
//	}
//	result_3 = listar_divisas_1((void*)&listar_divisas_1_arg, clnt);
//	if (result_3 == (char **) NULL) {
//		clnt_perror (clnt, "call failed");
//	}
//	result_4 = buscar_info_divisa_1(&buscar_info_divisa_1_arg, clnt);
//	if (result_4 == (char **) NULL) {
//		clnt_perror (clnt, "call failed");
//	}

	case 5:

	break;

	default:

	break;
}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}





int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

//Desde aqui empieza la ejecucion del client en si.
	char opcion;
do{ system(CLEAR);
	printf("MENU\n");
	printf("==================\n");
	printf("Bienvenido al sistema de gestion de divisas.\n");
	printf("Ingrese una opcion para continuar:\n");
	printf("1) Compra de divisas.\n");
	printf("2) Venta de divisas.\n");
	printf("3) Listar divisas.\n");
	printf("4) Buscar una divisa y desplegar su informacion.\n");
	printf("5) Salir.\n");
	fflush(stdin);
	scanf("%c",&opcion);

	if(opcion=='5'){ //Si quiero salir del programa
		break;       //Hago break al do-while y salgo del programa
	}
//Se ejecutara el modulo divisas_1 que contiene los 4 servicios de este sistema.
	divisas_1 (host, opcion);
}while(opcion!='9');


exit (0);
}
