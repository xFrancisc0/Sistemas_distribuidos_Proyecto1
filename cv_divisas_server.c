/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "cv_divisas.h"

int *
compra_divisas_1_svc(struct CompraVenta *argp, struct svc_req *rqstp)
{
	static int  result;

	FILE * conversor = fopen("./datos/conversion.txt","a+");
	FILE * f= fopen("./datos/usuario.txt","a+");
	FILE * f2 = fopen("./datos/sistema.txt","a+");

	int i=0,j=0,i_aux=0, j_aux=0, l, cantidad_usuario_cambio, cantidad_usuario_origen, cantidad_sistema,cantidad_sistema_pago,tipo_cambio_aux ;
	char tipo_aux[4],tipo_aux2[4],tasa_cambio[15];
	float conversion;
	while(strcmp(argp->user[i].tipo_moneda, argp->moneda_pago)!=0){
		i++;	
	}
	while(strcmp(argp->sistem[j].tipo_moneda, argp->moneda_compra)!=0){
		j++;
	}
	if(argp->cantidad>=atoi(argp->user[i].cantidad)){
		printf("Usted dispone de %s de la moneda %s\n", argp->user[i].cantidad,argp->user[i].tipo_moneda);
	}else{
		
		if(conversion>=atoi(argp->sistem[j].cantidad)){
			printf("Nuestro sistema no dispone de %f de la moneda %s\n",conversion,argp->sistem[j].tipo_moneda);
		}else{
				while(fscanf(conversor,"%s %s %s",tipo_aux,tipo_aux2,tasa_cambio)!=EOF){
					
						if(strcmp(tipo_aux2,argp->moneda_pago)==0 && strcmp(tipo_aux,argp->moneda_compra)==0){
							printf(" %s==%s && %s==%s\n",tipo_aux2,argp->moneda_pago,tipo_aux,argp->moneda_compra);
							break;
						}
						strcpy(tipo_aux,"");
				}
				fclose(conversor);
			//	printf("tasa cambio %f\n",atof(tasa_cambio));
				conversion=argp->cantidad*atof(tasa_cambio);
				cantidad_usuario_cambio = atoi(argp->user[j].cantidad)+argp->cantidad;
				cantidad_usuario_origen = atoi(argp->user[i].cantidad)-conversion;
				cantidad_sistema = atoi(argp->sistem[j].cantidad)-argp->cantidad;
				cantidad_sistema_pago = atoi(argp->sistem[i].cantidad)+conversion;
				//system("cls");
				printf("Ahora se posee\nUsuario = %i %s\nUsuario = %i %s\nSistema= %i %s\nSistema= %i %s\n",cantidad_usuario_cambio, argp->moneda_compra, cantidad_usuario_origen,argp->moneda_pago, cantidad_sistema,argp->moneda_compra,cantidad_sistema_pago,argp->moneda_pago);
				//system("pause");
				//system("cls");
			}
			//printf("i=%i J=%i\n\n",i,j);
			fclose(f);
			fclose(f2);
			if(remove("./datos/usuario.txt")==0 && remove("./datos/sistema.txt")==0){
			
			FILE * nuevo_cliente=fopen("./datos/usuario.txt","a+");
			FILE * nuevo_servidor=fopen("./datos/sistema.txt","a+");
			for(l=0;l<3;l++){
				if(l==j){
					fprintf(nuevo_cliente,"%s %i\n",argp->user[l].tipo_moneda,cantidad_usuario_cambio);
					fprintf(nuevo_servidor,"%s %i\n",argp->sistem[l].tipo_moneda,cantidad_sistema);
				
				}else{
					if(l==i){
						fprintf(nuevo_cliente,"%s %i\n",argp->user[l].tipo_moneda,cantidad_usuario_origen);
						fprintf(nuevo_servidor,"%s %i\n",argp->sistem[l].tipo_moneda,cantidad_sistema_pago);
						
					}else{
					
					fprintf(nuevo_cliente,"%s %s\n",argp->user[l].tipo_moneda,argp->user[l].cantidad);
					fprintf(nuevo_servidor,"%s %s\n",argp->sistem[l].tipo_moneda,argp->sistem[l].cantidad);
				
				}
				
			}
		}
			fclose(nuevo_cliente);
			fclose(nuevo_servidor);
		}
		}			
		return 0;
		

	return &result;
}

int *
venta_divisas_1_svc(struct CompraVenta *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

void *
listar_divisas_1_svc(struct CompraVenta *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}

void *
listardetalles_divisas_1_svc(struct CompraVenta *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}
