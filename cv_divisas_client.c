/*
* This is sample code generated by rpcgen.
* These are only templates and you can use them
* as a guideline for developing your own functions.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cv_divisas.h"
#include "funciones_client.h"
void
divisas_1(char *host, char op)
{
//system(CLEAR);
CLIENT *clnt;
char * *result_1;
struct CompraVenta comprar_divisas_1_arg;
char * *result_2;
struct CompraVenta vender_divisas_1_arg;
char * *result_3;
char *listar_divisas_1_arg;
char * *result_4;
struct CompraVenta buscar_info_divisa_1_arg;
char * *resultado;

char straux[1000];
char op_origenaux[100];
#ifndef	DEBUG
clnt = clnt_create (host, CV_DIVISAS, CV_DIVISAS_VER, "udp");
if (clnt == NULL) {
clnt_pcreateerror (host);
exit (1);
}
#endif	/* DEBUG */
//Dependiendo de la opcion elegida en el menu, se elegira un servicio determinado.
// Si la opcion elegida es 1, se crearan las siguientes variables.
switch(op){
// Modulo de compras
	case 1:
//Si no mando str al server me genera error, solo por eso lo envio. Cuando realmente envie str sera cuando tenga que enviar multiples datos al server.
		comprar_divisas_1_arg.str = strdup("Cualquier Valor"); // Le paso el valor de 1 al *str . (COn strdup se pasan valores a char *str (en lugar de strcmpy que sirve para str[]))
		comprar_divisas_1_arg.caracter = '1'; //El que realmente envio es el caracter
		result_1 = compra_divisas_1(&comprar_divisas_1_arg, clnt); //Desplego datos al usuario.
		if (result_1 == (char **) NULL) {
			clnt_perror (clnt, "call failed");
		}

	
		int i, opcion_cantidad, opcion_origen, opcion_salida;
		sprintf(straux,"%s", (char *) *result_1); //La salida de la funcion la transformo en un string cuyo formato es %s.
		do{
		system(CLEAR);
		printf("Usted ha elegido la opcion de comprar divisas\n");
		printf("================================\nEl usuario actualmente posee\n\n");
		printf("%s", straux);
		printf("================================\n");
		printf("OPCIONES\n\n1)CLP\n2)USD\n3)EUR\n9)Volver\n===================\nSeleccione una opcion que represente la moneda a comprar:\n");
		fflush(stdin);
		scanf("%s",op_origenaux);

				//if de validacion
				if(IsNaN_int(op_origenaux)==0 && IsNaN_float(op_origenaux)==0 && IsNaS(op_origenaux)==1){
				opcion_origen=atoi(op_origenaux);

		switch(opcion_origen){
			case 1:
						do{
							printf("Ingrese el monto a comprar:");
							fflush(stdin);
							scanf("%i",&opcion_cantidad);
							printf("\n");
						}while(opcion_cantidad<0);
						do{
							printf("===================\n");
							printf("OPCIONES\n\n2)USD\n3)EUR\n9)Volver\n===================\nSeleccione moneda con la que pagara: ");
							fflush(stdin);
							scanf("%s",op_origenaux);

							//if de validacion
							if(IsNaN_int(op_origenaux)==0 && IsNaN_float(op_origenaux)==0 && IsNaS(op_origenaux)==1){
							opcion_salida=atoi(op_origenaux);


							switch(opcion_salida){
									case 2:
											comprar_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
											sprintf(straux, "CLP-USD-%i", opcion_cantidad);
											comprar_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
											result_1 = compra_divisas_1(&comprar_divisas_1_arg, clnt); //Realizo la compra.
											if (result_1 == (char **) NULL) {
												clnt_perror (clnt, "call failed");
											}
											sprintf(straux,"%s", (char *) *result_1);
											printf("%s", straux); // Mostrar en pantalla la compra realizada
											scanf("%i", &i);
											opcion_salida=9;
											opcion_origen=9;
										break;
									case 3:
											comprar_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
											sprintf(straux, "CLP-EUR-%i", opcion_cantidad);
											comprar_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
											result_1 = compra_divisas_1(&comprar_divisas_1_arg, clnt); //Realizo la compra.
											if (result_1 == (char **) NULL) {
												clnt_perror (clnt, "call failed");
											}
											sprintf(straux,"%s", (char *) *result_1);
											printf("%s", straux); // Mostrar en pantalla la compra realizada
											scanf("%i", &i);
											opcion_salida=9;
											opcion_origen=9;
										break;
									case 9:
											opcion_salida=9;
										break;
									default:
											printf("La opcion %c no es valida.\n\n", opcion_salida);
										break;
								}

						//Else de la validacion
						}else{

						printf("opcion ingresada no valida\n");	
						}

						}while(opcion_salida!=9);
						system(CLEAR);
					break;
					case 2:
							do{
								printf("Ingrese el monto a comprar:");
								fflush(stdin);
								scanf("%i",&opcion_cantidad);
								printf("\n");
							}while(opcion_cantidad<0);
							do{
								printf("===================\n");
								printf("OPCIONES\n\n1)CLP\n3)EUR\n9)Volver\n===================\nSeleccione moneda con la que pagara: ");
								fflush(stdin);
								//if de validacion
								if(IsNaN_int(op_origenaux)==0 && IsNaN_float(op_origenaux)==0 && IsNaS(op_origenaux)==1){
								opcion_salida=atoi(op_origenaux);
								switch(opcion_salida){
										case 1:
											comprar_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
											sprintf(straux, "USD-CLP-%i", opcion_cantidad);
											comprar_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
											result_1 = compra_divisas_1(&comprar_divisas_1_arg, clnt); //Realizo la compra.
											if (result_1 == (char **) NULL) {
												clnt_perror (clnt, "call failed");
											}
											sprintf(straux,"%s", (char *) *result_1);
											printf("%s", straux); // Mostrar en pantalla la compra realizada
											scanf("%i", &i);
											opcion_salida=9;
											opcion_origen=9;
											break;
										case 3:
											comprar_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
											sprintf(straux, "USD-EUR-%i", opcion_cantidad);
											comprar_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
											result_1 = compra_divisas_1(&comprar_divisas_1_arg, clnt); //Realizo la compra.
											if (result_1 == (char **) NULL) {
												clnt_perror (clnt, "call failed");
											}
											sprintf(straux,"%s", (char *) *result_1);
											printf("%s", straux); // Mostrar en pantalla la compra realizada
											scanf("%i", &i);
											opcion_salida=9;
											opcion_origen=9;
											break;
										case 9:
											opcion_salida=9;
											break;
										default:
											printf("La opcion %c no es valida.\n\n", opcion_salida);
											break;
											}
						
						//Else de la validacion
						}else{

						printf("opcion ingresada no valida\n");	
						}


						}while(opcion_salida!=9);
						system(CLEAR);
					break;
				case 3:
					do{
						printf("Ingrese el monto a comprar:");
						fflush(stdin);
						scanf("%i",&opcion_cantidad);
						printf("\n");
						}while(opcion_cantidad<0);
						do{
							printf("===================\n");
							printf("OPCIONES\n\n1)CLP\n2)USD\n9)Volver\n===================\nSeleccione moneda con la que pagara: ");
							fflush(stdin);
							scanf("%s",op_origenaux);

							//if de validacion
							if(IsNaN_int(op_origenaux)==0 && IsNaN_float(op_origenaux)==0 && IsNaS(op_origenaux)==1){
							opcion_salida=atoi(op_origenaux);

						switch(opcion_salida){
						case 1:
							comprar_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
							sprintf(straux, "EUR-CLP-%i", opcion_cantidad);
							comprar_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
							result_1 = compra_divisas_1(&comprar_divisas_1_arg, clnt); //Realizo la compra.
							if (result_1 == (char **) NULL) {
								clnt_perror (clnt, "call failed");
							}
							sprintf(straux,"%s", (char *) *result_1);
							printf("%s", straux); // Mostrar en pantalla la compra realizada
							scanf("%i", &i);
							opcion_salida=9;
							opcion_origen=9;
							break;
						case 2:
							comprar_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
							sprintf(straux, "EUR-USD-%i", opcion_cantidad);
							comprar_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
							result_1 = compra_divisas_1(&comprar_divisas_1_arg, clnt); //Realizo la compra.
							if (result_1 == (char **) NULL) {
								clnt_perror (clnt, "call failed");
							}
							sprintf(straux,"%s", (char *) *result_1);
							printf("%s", straux); // Mostrar en pantalla la compra realizada
							scanf("%i", &i);
							opcion_salida=9;
							opcion_origen=9;
							break;
						case 9:
							opcion_salida=9;
							break;
						default:
							printf("La opcion %c no es valida.\n\n", opcion_salida);
							break;
							}

						//Else de la validacion
						}else{

						printf("opcion ingresada no valida\n");	
						}

			}while(opcion_salida!=9);
			system(CLEAR);
			break;
		
	case 9:
		opcion_origen=9;
		break;
	

	default:
	break;	
	}
	

						//Else de la validacion
						}else{

						printf("opcion ingresada no valida\n");	
						}

}while(opcion_origen!=9);
break;
//	result_2 = vender_divisas_1(&vender_divisas_1_arg, clnt);
//	if (result_2 == (char **) NULL) {
//	clnt_perror (clnt, "call failed");
//	}


				//MODULO DE VENTAS
	case 2:  

//Si no mando str al server me genera error, solo por eso lo envio. Cuando realmente envie str sera cuando tenga que enviar multiples datos al server.
		vender_divisas_1_arg.str = strdup("Cualquier Valor"); // Le paso el valor de 1 al *str . (COn strdup se pasan valores a char *str (en lugar de strcmpy que sirve para str[]))
		vender_divisas_1_arg.caracter = '1'; //El que realmente envio es el caracter
		result_2 = venta_divisas_1(&vender_divisas_1_arg, clnt); //Despliega datos al usuario.
		if (result_2 == (char **) NULL) {
			clnt_perror (clnt, "call failed");
		}
		
		
		sprintf(straux,"%s", (char *) *result_2); //La salida de la funcion la transformo en un string cuyo formato es %s.
		do{
		system(CLEAR);
		printf("Usted ha elegido la opción de vender divisas\n");
		printf("================================\nEl usuario actualmente posee\n\n");
		printf("%s", straux);
		printf("================================\n");
		printf("OPCIONES\n\n1)CLP\n2)USD\n3)EUR\n9)Volver\n===================\nSeleccione una opción que represente la moneda a comprar:\n");
		fflush(stdin);
		scanf("%i",&opcion_origen);
			switch(opcion_origen){
				case 1:
						do{
							printf("Ingrese el monto a vender:");
							fflush(stdin);
							scanf("%i",&opcion_cantidad);
							printf("\n");
						}while(opcion_cantidad<0);
						do{
							printf("===================\n");
							printf("OPCIONES\n\n2)USD\n3)EUR\n9)Volver\n===================\nSeleccione moneda con la que pagará: ");
							fflush(stdin);
							scanf("%i",&opcion_salida);
							switch(opcion_salida){
									case 2:
											vender_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
											sprintf(straux, "CLP-USD-%i", opcion_cantidad);
											vender_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
											result_2 = venta_divisas_1(&vender_divisas_1_arg, clnt); //Realizo la venta.
											if (result_2 == (char **) NULL) {
												clnt_perror (clnt, "call failed");
											}
											sprintf(straux,"%s", (char *) *result_2);
											printf("%s", straux); // Mostrar en pantalla la venta realizada
											scanf("%i", &i);
											opcion_salida= 9 ;
											opcion_origen= 9;
										break;
									case 3:
											vender_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
											sprintf(straux, "CLP-EUR-%i", opcion_cantidad);
											vender_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
											result_2 = venta_divisas_1(&vender_divisas_1_arg, clnt); //Realizo la venta.
											if (result_2 == (char **) NULL) {
												clnt_perror (clnt, "call failed");
											}
											sprintf(straux,"%s", (char *) *result_2);
											printf("%s", straux); // Mostrar en pantalla la venta realizada
											scanf("%i", &i);
											opcion_salida=9;
											opcion_origen=9;
										break;
									case 9:
											opcion_salida=9;
										break;
									default:
											printf("La opción %i no es válida.\n\n", opcion_salida);
										break;
								}
						}while(opcion_salida!=9);
						system(CLEAR);
					break;
					case 2:
							do{
								printf("Ingrese el monto a vender:");
								fflush(stdin);
								scanf("%i",&opcion_cantidad);
								printf("\n");
							}while(opcion_cantidad<0);
							do{
								printf("===================\n");
								printf("OPCIONES\n\n1)CLP\n3)EUR\n9)Volver\n===================\nSeleccione moneda con la que pagará: ");
								fflush(stdin);
								scanf("%i",&opcion_salida);
								switch(opcion_salida){
										case 1:
											vender_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
											sprintf(straux, "USD-CLP-%i", opcion_cantidad);
											vender_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
											result_2 = venta_divisas_1(&vender_divisas_1_arg, clnt); //Realizo la venta.
											if (result_2 == (char **) NULL) {
												clnt_perror (clnt, "call failed");
											}
											sprintf(straux,"%s", (char *) *result_2);
											printf("%s", straux); // Mostrar en pantalla la venta realizada											scanf("%i", &i);
											opcion_salida=9;
											opcion_origen=9;
											break;
										case 3:
											vender_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
											sprintf(straux, "USD-EUR-%i", opcion_cantidad);
											vender_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
											result_2 = venta_divisas_1(&vender_divisas_1_arg, clnt); //Realizo la venta.
											if (result_2 == (char **) NULL) {
												clnt_perror (clnt, "call failed");
											}
											sprintf(straux,"%s", (char *) *result_2);
											printf("%s", straux); // Mostrar en pantalla la ventaa realizada
											scanf("%i", &i);
											opcion_salida=9;
											opcion_origen=9;
											break;
										case 9:
											opcion_salida=9;
											break;
										default:
											printf("La opción %i no es válida.\n\n", opcion_salida);
											break;
											}
						}while(opcion_salida!=9);
						system(CLEAR);
					break;
				case 3:
					do{
						printf("Ingrese el monto a vender:");
						fflush(stdin);
						scanf("%i",&opcion_cantidad);
						printf("\n");
						}while(opcion_cantidad<0);
						do{
							printf("===================\n");
							printf("OPCIONES\n\n1)CLP\n2)USD\n9)Volver\n===================\nSeleccione moneda con la que pagará: ");
							fflush(stdin);
							scanf("%i",&opcion_salida);
						switch(opcion_salida){
						case 1:
							vender_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
							sprintf(straux, "EUR-CLP-%i", opcion_cantidad);
							vender_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
							result_2 = venta_divisas_1(&vender_divisas_1_arg, clnt); //Realizo la venta.
							if (result_2 == (char **) NULL) {
								clnt_perror (clnt, "call failed");
							}
							sprintf(straux,"%s", (char *) *result_2);
							printf("%s", straux); // Mostrar por pantalla la venta realizada
							scanf("%i", &i);
							opcion_salida=9;
							opcion_origen=9;
							break;
						case 2:
							vender_divisas_1_arg.caracter = '2'; //El submodulo del servicio a ejecutar en el server es el 2.
							sprintf(straux, "EUR-USD-%i", opcion_cantidad);
							vender_divisas_1_arg.str = strdup(straux); // Enviare multiples datos al server
							result_2 = venta_divisas_1(&vender_divisas_1_arg, clnt); //Realizo la venta.
							if (result_2 == (char **) NULL) {
								clnt_perror (clnt, "call failed");
							}
							sprintf(straux,"%s", (char *) *result_2);
							printf("%s", straux); // Mostrar por pantalla la venta realizada
							scanf("%i", &i);
							opcion_salida=9;
							opcion_origen=9;
							break;
						case 9:
							opcion_salida=9;
							break;
						default:
							printf("La opción %i no es válida.\n\n", opcion_salida);
							break;
							}
			}while(opcion_salida!=9);
			system(CLEAR);
			break;
		
	case 9:
		opcion_origen=9;
		break;
	

	default:
	break;	
	}
	
}while(opcion_origen!=9);
break;

case 3: //**************************************************MODULO LISTAR**************************************************
		system(CLEAR);
		int op_origen;//**cree una nueva opcion
		int var;
		int * a= &var;
			do{//mostramos el menu de listar y preguntamos por la accion a seguir
				printf("Opcion Listar\n");
				printf("===================\n");
				printf("1)Cuenta Usuario\n2)Disponibilidad Sistema\n3)Cambio Divisas\n4)Volver\n");
				printf("Ingrese su opcion:");
				fflush(stdin);
				scanf("%s",op_origenaux);

				//if de validacion
				if(IsNaN_int(op_origenaux)==0 && IsNaN_float(op_origenaux)==0 && IsNaS(op_origenaux)==1){
				op_origen=atoi(op_origenaux);

				switch(op_origen){
					case 1:

					*a=1;
					
					result_3 = listar_divisas_1(a,clnt);
					if (result_3 == (char **) NULL) {
					clnt_perror (clnt, "call failed");
					}
					sprintf(straux,"%s", (char *) *result_3);
					printf("%s", straux); // Mostrar en pantalla la compra realizada
					
						
						break;
					case 2:
						*a=2;
						result_3 = listar_divisas_1(a,clnt);
						if (result_3 == (char **) NULL) {
					clnt_perror (clnt, "call failed");
					}
					sprintf(straux,"%s", (char *) *result_3);
					printf("%s", straux); // Mostrar en pantalla la compra realizada
						
						break;
					case 3:
						*a=3;
						result_3 = listar_divisas_1(a,clnt);
						if (result_3 == (char **) NULL) {
						clnt_perror (clnt, "call failed");
						}
						sprintf(straux,"%s", (char *) *result_3);
						printf("%s", straux); // Mostrar en pantalla la compra realizada
						break;
						
					case 4:
						op_origen=4;
						
						break;
					default:
						printf("opcion ingresada no valida\n");
						break;			
					
					
				}

				//Else de la validacion
				}else{

				printf("opcion ingresada no valida\n");	
				}

			}while(op_origen!=4);
			system(CLEAR);
	break;		

//Se usa basicamente el mismo codigo del servicio 3, sin embargo las diferencias recaen en el servidor.
case 4: //****************MODULO LISTAR INFORMACION DE UNA MONEDA**************************************************
		system(CLEAR);
		int op_origen2;

			
			do{//Se muestra el menu de listar la informacion de un tipo de moneda
				printf("Opcion Listar informacion sobre un tipo de moneda\n");
				printf("=================================================\n");
				printf("OPCIONES\n\n1)CLP\n2)USD\n3)EUR\n4)Volver\n===================\nSeleccione una opcion:\n");
				fflush(stdin);
				scanf("%s",op_origenaux);

				//if de validacion
				if(IsNaN_int(op_origenaux)==0 && IsNaN_float(op_origenaux)==0 && IsNaS(op_origenaux)==1){
				op_origen2=atoi(op_origenaux);

				switch(op_origen2){
					case 1:
					system(CLEAR);
					buscar_info_divisa_1_arg.str = strdup("CLP");
										
					result_4 = listardetalles_divisas_1(&buscar_info_divisa_1_arg, clnt);
					if (result_4 == (char **) NULL) {
					clnt_perror (clnt, "call failed");
					}
					sprintf(straux,"%s", (char *) *result_4);
					printf("%s", straux); // Mostrar en pantalla la informacion del tipo de moneda seleccionado
					printf("\n\n");	

					break;


					case 2:
					system(CLEAR);
					buscar_info_divisa_1_arg.str = strdup("USD");
										
					result_4 = listardetalles_divisas_1(&buscar_info_divisa_1_arg, clnt);
					if (result_4 == (char **) NULL) {
					clnt_perror (clnt, "call failed");
					}
					sprintf(straux,"%s", (char *) *result_4);
					printf("%s", straux); // Mostrar en pantalla la informacion del tipo de moneda seleccionado
					printf("\n\n");	
					break;


					case 3:
					system(CLEAR);
					buscar_info_divisa_1_arg.str = strdup("EUR");
					
					
					result_4 = listardetalles_divisas_1(&buscar_info_divisa_1_arg, clnt);
					if (result_4 == (char **) NULL) {
					clnt_perror (clnt, "call failed");
					}
					sprintf(straux,"%s", (char *) *result_4);
					printf("%s", straux); // Mostrar en pantalla la informacion del tipo de moneda seleccionado
					printf("\n\n");	


					break;
						

					case 4:
						op_origen2=4;
						
						break;
					default:
						system(CLEAR);
						printf("opcion ingresada no valida\n");
						break;			
					
					
					}

						//Else de la validacion
						}else{

						printf("opcion ingresada no valida\n");	
						}


					}while(op_origen2!=4);
					system(CLEAR);

				break;	


				default:
				break;
}


#ifndef	DEBUG
clnt_destroy (clnt);
#endif	/* DEBUG */
}



int
main (int argc, char *argv[])
{
char op_origenaux[100];
char *host;
if (argc < 2) {
	printf ("usage: %s server_host\n", argv[0]);
	exit (1);
}
host = argv[1];
//Desde aqui empieza la ejecucion del client en si.
int opcion;
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

scanf("%s",op_origenaux);

if(atoi(op_origenaux)==5){ //Si quiero salir del programa
		break; //Hago break al do-while y salgo del programa
	}


//if de validacion
if(IsNaN_int(op_origenaux)==0 && IsNaN_float(op_origenaux)==0 && IsNaS(op_origenaux)==1){
opcion=atoi(op_origenaux);
printf("%i", opcion);

//Se ejecutara el modulo divisas_1 que contiene los 4 servicios de este sistema.
divisas_1 (host, opcion);

//Else de la validacion
}else{
printf("opcion ingresada no valida\n");	
}


}while(opcion!=5);
exit (0);
} 