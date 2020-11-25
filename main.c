#include "metodosimplex.h"
#include <stdio.h>
int main(){
	float funcion[LIM],restriccion[LIM][LIM],constante[LIM];
	float rcons[LIM],nfp[LIM][LIM],nfp2[LIM],z2;
	int i,n,v,r;
	float menor,menor2;
	int aux=0,aux2=0;
	printf("-----------------------------------------------------------\n");
	printf("\t\t\tMetodo Simplex\n");
	printf("-----------------------------------------------------------\n");
	printf("Numero de variables: ");
	scanf("%d",&v);
	for(n=0; n<v; n++){
		printf("Variable x%d de Z: ", n+1);
		scanf("%f",&funcion[n]);
	}
	printf("\nNumero de restricciones: ");
	scanf("%d",&r);
	for(i=0; i<r; i++){
		printf("\n\t\t\tRestriccion #%d\n",i+1);
		printf("-----------------------------------------------------------\n");
		for(n=0; n<v; n++){
			printf("n%d: ",n+1);
			scanf("%f",&restriccion[i][n]);
		}
		printf("Constante: ");
		scanf("%f", &constante[i]);
	}
	printf("-----------------------------------------------------------\n");
	imprimir_tabla_simplex_uno(funcion,restriccion,constante,v,r);
	printf("-----------------------------------------------------------\n");
	buscar_menor( funcion, v);
	menor = buscar_menor( funcion, v);
	printf("\n%f",menor);
	aux = buscar_posicion(funcion,v);
	printf("\n%d",aux);
	do{
		columna_pivote(restriccion,r,aux);
		fila_pivote(restriccion,constante,rcons,r,aux);
		menor2 = buscar_menor2(rcons,v);
		aux2 = buscar_posicion2(rcons,v);
		printf("\n%d",aux2);
		elemento_pivote(restriccion,aux2,aux);
		nueva_fila_pivote(nfp,nfp2,restriccion,constante,aux2,aux,v);
		obtener_nueva_tabla(funcion,restriccion,constante,menor,nfp,nfp2,v,r,aux2,aux);
		obtener_resultado_z(z2,rcons,menor,aux2);
		z2 = obtener_resultado_z(z2,rcons,menor,aux2);
		buscar_menor( funcion, v);
		menor = buscar_menor( funcion, v);
		aux = buscar_posicion(funcion,v);
	}while (menor < -1);
	printf("-----------------------------------------------------------\n");
	imprimir_tabla_simplex_dos(funcion,restriccion,constante,v,r,z2);
	printf("-----------------------------------------------------------\n");
	return 0;
}