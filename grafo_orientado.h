#include <stdio.h>
#include <stdlib.h>

typedef int** grafo;

grafo criar_matriz( int n);
grafo join(grafo adj, int a, int b);
grafo remov(grafo adj, int a, int b);
grafo warshall(grafo adj, grafo path, int n); // Path deve ser uma matriz criada.
grafo limpar_matriz(grafo adj, int n);
void print(grafo adj, int n);