#include "metodosimplex.h"
void imprimir_tabla_simplex_uno(float num[LIM],float num_dos[LIM][LIM],float num_tres[LIM],int v,int r){
	int i,n;
	printf("\t\t\tTabla simplex #1\n");
	for(i=0; i<r; i++){
		for(n=0; n<v; n++){
			printf("%.3f\t",num_dos[i][n]);
		}
		printf("%.3f\n",num_tres[i]);
	}
	for(n=0; n<v; n++){
		printf("%.f\t",num[n]*(-1));
	}
	printf("\n");
}

void imprimir_tabla_simplex_dos(float num[LIM],float num_dos[LIM][LIM],float num_tres[LIM],int v,int r,float z2){
	int i,n;
	printf("\t\t\tTabla simplex #2\n");
	for(i=0; i<r; i++){
		for(n=0; n<v; n++){
			printf("%.3f\t",num_dos[i][n]);
		}
		printf("%.3f\n",num_tres[i]);
	}
	for(n=0; n<v; n++){
		printf("%.f\t",num[n]*(-1));
	}
	printf("%f\n",z2);
}
int buscar_menor(float num[LIM],int v){
	int n;
	float menor=num[0];
	for (n=0; n<v; n++){
	    if (num[n] > menor){
	    	menor=num[n];
	    }
	}
	return menor*(-1);
}

int buscar_posicion(float num[LIM], int v){
	int n,aux=0;
	float menor;
	menor=num[0];
	for (n=0; n<v; n++){
	    if (num[n] > menor){
	    	menor=num[n];
	    	aux=n;
	    }
	}
	return aux;
}

int buscar_menor2(float num[LIM],int v){
	int n;
	float menor=num[0];
	for (n=0; n<v; n++){
	    if (num[n] < menor){
	    	menor=num[n];
	    }
	}
	return menor*(-1);
}

int buscar_posicion2(float num[LIM], int v){
	int n,aux=0;
	float menor;
	menor=num[0];
	for (n=0; n<v; n++){
	    if (num[n] < menor){
	    	menor=num[n];
	    	aux=n;
	    }
	}
	return aux;
}
void columna_pivote(float num[LIM][LIM], int r, int aux){
	int i;
	printf("\nColumna pivote\n");
	for(i=0; i<r; i++){
		printf("%.3f\t",num[i][aux]);
		}
}

void fila_pivote(float num[LIM][LIM],float num_dos[LIM],float rcons[LIM],int r,int aux){
	int i;
	printf("\nMenor para la fila pivote\n");
	for(i=0; i<r; i++){
	rcons[i]=num_dos[i]/num[i][aux];
	printf("%.3f\t",rcons[i]);
	}
}

void elemento_pivote(float num[LIM][LIM],int aux2,int aux){
	printf("\nElemento pivote\n");
	printf("%.3f\n",num[aux2][aux]);
}

void nueva_fila_pivote(float nfp[LIM][LIM],float nfp2[LIM],float num[LIM][LIM],float num_dos[LIM],int aux2,int aux,int v){
	int n,i=0,k;
	printf("\nNueva fila pivote\n");
	for(n=0;n<v;n++){
		nfp[aux2][n]=num[aux2][n]/num[aux2][aux];
		printf("%.3f\t",nfp[aux2][n]);
	}
	nfp2[k]=num_dos[aux2]/num[aux2][aux];
	printf("%.3f \n",nfp2[k]);
}

void obtener_nueva_tabla(float funcion[LIM],float restriccion[LIM][LIM],float constante[LIM],float menor,float nfp[LIM][LIM],float nfp2[LIM],int v,int r,int aux2,int aux){
	int i,n,k=0;
	float res,res2;
	double l[10][10];
	for(i=0; i<r; i++){
	l[i][aux]=restriccion[i][aux];
	}
	for(i=0; i<r; i++){
		for(n=0; n<v; n++){
			res=restriccion[i][aux]*nfp[aux2][n];
			restriccion[i][n]=restriccion[i][n]-res;
		}
		res2=l[i][aux]*nfp2[k];
		constante[i]=constante[i]-res2;
	}
	for(n=0;n<v;n++){
		restriccion[aux2][n]=nfp[aux2][n];
	}
	constante[aux2]=nfp2[k];
	for(n=0;n<v;n++){
		res=menor*nfp[aux2][n];
		res=res*(-1);
		funcion[n]=funcion[n]-res;
	}
}

int obtener_resultado_z(float z2,float num[LIM],float menor,int aux2){
	float res;
	res=menor*num[aux2];
	z2=z2-res;
	return z2;
}
