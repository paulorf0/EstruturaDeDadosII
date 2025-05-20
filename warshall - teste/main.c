#include "../grafo_orientado.h"

int main(){
	int n = 5;
	grafo adj = criar_matriz(n);
  	grafo path = criar_matriz(n);

  	adj = join(adj, 0, 1);
  	adj = join(adj, 0, 3);
  	adj = join(adj, 1, 2);
  	adj = join(adj, 1, 3);
  	adj = join(adj, 2, 3);
  	adj = join(adj, 2, 4);
  	adj = join(adj, 3, 0);

  	path = warshall(adj, path, n);
  	print(adj, n);
  	printf("\n\n");
  	print(path, n);

	return 0;
}