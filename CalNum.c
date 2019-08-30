#include <stdlib.h>
#include <stdio.h>

double **alocaMatriz(int l, int c){ 
	/*se houver memoria disponivel, aloca uma matriz bidimensional de double 
	com l linhas e c colunas e devolve um ponteiro para essa matriz; caso contrario devolve um ponteiro nulo*/
	double **M;
	int i,j;
	M = malloc(sizeof(M)*l);
	if(M==NULL){ /*Falta de memoria*/
		return NULL;
	}
	for(i=0;i<l;i++){ /*alocando as linhas*/
		M[i] = malloc(sizeof (double)*c);
		if(M[i]==NULL){ /*liberando as memorias alocadas anteriormente*/
			for(j=0;j<i;j++){
				free(M[j]);
			}
			free(M);
			return NULL;
		}
	}
	return M;	
} /* fim alocaMatriz */

void leMatriz(double **M, int l, int c){
	/*lê valores para uma matriz M de double alocada dinamicamente, com l linhas e c colunas*/
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("M[%d][%d]: ", i+1, j+1);
			scanf("%lf", &M[i][j]);
		}
	}
} /* fim leMatriz */

void imprimeMatriz(double **M, int l, int c){
	/* imprime uma matriz M de double, com l linhas e c colunas */
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%10.4lf ", M[i][j]);
		}
		printf("\n");
	}
} /* fim imprimeMatriz */

int main(){
	int n;
	double **A;
	printf("Quantidade de variaveis: ");
	scanf("%d", &n);
	A = alocaMatriz(n,n+1);
	
	if(A==NULL){/* falta de memoria */
		printf("Deu pau!\n\n Falta de memoria!");
		return 1;		
	}
	
	leMatriz(A, n, n+1);
	imprimeMatriz(A, n, n+1);
	return 0;
	}
