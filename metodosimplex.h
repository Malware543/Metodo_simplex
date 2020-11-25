#ifndef __METODOSIMPLEX_H
#define __METODOSIMPLEX_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define LIM 5

void imprimir_tabla_simplex_uno(float num[LIM],float num_dos[LIM][LIM],float num_tres[LIM],int v,int r);
void imprimir_tabla_simplex_dos(float num[LIM],float num_dos[LIM][LIM],float num_tres[LIM],int v,int r,float z2);
int buscar_menor(float num[LIM],int v);
int buscra_posicion(float num[LIM],int v);
int buscar_menor2(float num[LIM],int v);
int buscra_posicion2(float num[LIM],int v);
void columna_pivote(float num[LIM][LIM], int r,int aux);
void fila_pivote(float num[LIM][LIM],float num_dos[LIM],float rcons[LIM],int r,int aux);
void elemento_pivote(float num[LIM][LIM],int aux2,int aux);
void nueva_fila_pivote(float nfp[LIM][LIM],float nfp2[LIM],float num[LIM][LIM],float num_dos[LIM],int aux2,int aux,int v);
void obtener_nueva_tabla(float funcion[LIM],float restriccion[LIM][LIM],float constante[LIM],float menor,float nfp[LIM][LIM],float nfp2[LIM],int v,int r,int aux2,int aux);
int obtener_resultado_z(float z2,float num[LIM],float menor,int aux2);

#endif
