#include "grafo.h"

// Privado //
int **copiar_matriz(int **m1, int **m2, int n){

  for(int i = 0; i < n; i ++ )
    for(int j = 0; j < n; j ++)
      m2[i][j] = m1[i][j];
}

// Produto booleano de linha por coluna.
int prod_bool(int *l, int *c, int n){
 int res = 0;
  for(int i = 0; i < n;i ++){
      if(res == 1) break;
      res = res || (l[i] && c[i]);
  }

  return res;
}


// Privado //


grafo criar_matriz(int n) {
  grafo adj = (grafo)malloc(sizeof(int *) * n);

  if (adj == NULL) {
    printf("Houve um erro na alocação da matriz de adjacencia.\n");
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    *(adj + i) = (int *)calloc(n, sizeof(int)); // Espaços zerados.
    if (*(adj + i) == NULL) {
      printf("Erro de alocação.\n");
      limpar_matriz(adj, n);
      return NULL;
    }
  }

  return adj;
}
grafo join(grafo adj, int a, int b) {
  if (adj == NULL || adj[a] == NULL)
    return NULL;

  adj[a][b] = 1;

  return adj;
}
grafo remov(grafo adj, int a, int b) {

  if (adj == NULL || adj[a] == NULL)
    return NULL;

  adj[a][b] = 0;

  return adj;
}
grafo limpar_matriz(grafo adj, int n) {
  if (adj == NULL)
    return NULL;

  for (int i = 0; i < n; i++)
    free(*(adj + i));

  free(adj);

  return NULL;
}

void print(grafo adj, int n) {
  if (adj == NULL)
    return;

  printf("     ");
  for (int j = 0; j < n; j++) {
    printf("%8d", j);
  }
  printf("\n");

  printf("%6c", '+');

  printf("\n");

  for (int i = 0; i < n; i++) {
    printf("%4d |", i);
    for (int j = 0; j < n; j++) {
      printf("%8d", adj[i][j]);
    }
    printf("\n");
  }
}

grafo warshall(grafo adj, grafo path, int n){

  copiar_matriz(adj, path, n);

  for(int k = 0; k < n; k++) // Nós intermediários.
    for(int i = 0; i < n; i++)
        if(path[i][k]) // Se não houver caminho de i para k, então é inútil continuar verificação.
         for(int j = 0; j < n; j++){
          if(path[i][j]) continue; // Se houver caminho de i para j, ok!
         
          path[i][j] = path[k][j]; // Se tem caminho de i para k, depende apenas da existência do caminho de k para j.
        }


  return path; 
}