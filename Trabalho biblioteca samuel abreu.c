#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct x
{

	char nome[50];

	
}livro;

typedef struct y
{
	int livrosdia;
	int dia;
	int mes;
	int ano;
	livro *x;

}leitura;

int dias(leitura *l, int numDias, int *soma);
void resultado(leitura *l, int maior, int *soma);
void listartudo(leitura *l, int numDias);

int main()
{
	leitura *l;
	int soma;
	int numDias = 0, maior, op;

	printf("Quantos dias voce leu nesse mes? \n");
	scanf("%d", &numDias);
	l=(leitura *)malloc(sizeof(leitura)*numDias);
	if(l==NULL){
		printf("erro ao alocar dias\n");
		return -1;
	}

	maior = dias(l, numDias, &soma);
	resultado(l, maior, &soma);
	printf("Digite 1 caso queira ver a lista de dias e livros completa \n"); 
	printf("Digite 2 para encerrar o codigo \n");
	scanf("%d", &op);
	switch(op){
		case 1:
			listartudo(l, numDias);
			break;
		case 2:
			break;
			
			}
	free(l);
	return 0;
}

int dias(leitura *l, int numDias, int *soma){
int i = 0;
int j = 0;
int q = 0;
int maior = 0;
int indicemaior = 0;

for(i = 0; i < numDias; i++){
	printf("---------------------------Dia %d--------------------------- \n", i+1);
	printf("Digite a data do dia que deseja cadastrar(exemplo: 01/08/2003) \n");
	scanf("%d/%d/%d", &l[i].dia,&l[i].mes,&l[i].ano);
	
	printf("Quantos livros leu neste dia? \n");
	scanf("%d", &l[i].livrosdia);
	
	l[i].x=(livro *)malloc(sizeof(livro)*l[i].livrosdia);
	if(l[i].x ==NULL){
		printf("Erro ao alocar livros\n");
		for (q = 0; q < l[i].livrosdia ; ++q)
		{
			free(l[i].x);
		}
		free(l);
		return -1;
		}
	for(j = 0; j < l[i].livrosdia ; j++){
		
		printf("Digite o titulo do livro %d: ", 1+j);
		scanf(" %[^\n]s", &l[i].x[j].nome);
		
	}
	
	if(l[i].livrosdia > maior ){
		
		maior = l[i].livrosdia;
		indicemaior = i;
	}
		*soma += l[i].livrosdia;
}		
	return indicemaior;
}

void resultado(leitura *l, int maior, int *soma){
	int i = 0;
	printf("-------------------------------------------------------------- \n");
	printf("Voce leu %d livros nesse mes \n", *soma);
	printf("O dia que voce mais leu livros foi no dia %d/%d/%d \n", l[maior].dia, l[maior].mes, l[maior].ano);
	printf("Voce leu %d livros nesse dia \n", l[maior].livrosdia);
	
	for(i = 0; i < l[maior].livrosdia ; i++){
		
		printf("Livro %d lido neste dia: %s \n", 1+i, l[maior].x[i].nome );
		
	}
	
	
}

void listartudo(leitura *l, int numDias)
{
	int i;
	int j;

for (i = 0; i < numDias	; ++i)
	{	
	
			printf("-----------------------Dia %d/%d/%d--------------------------- \n", l[i].dia, l[i].mes, l[i].ano);
			printf("Voce leu %d livros nesse dia \n", l[i].livrosdia );

		for(j = 0; j < l[i].livrosdia; ++j)
		{
			printf("Livro %d: %s \n", j+1, l[i].x[j].nome );
			
		}
	}
	
}


