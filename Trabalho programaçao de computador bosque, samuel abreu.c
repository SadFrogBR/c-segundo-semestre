#include <stdio.h>

typedef struct y
{
	char especie[25];
	char nomeplantador[25];
	char porte[25];
	int anoplantio;
	
}arvore;

typedef struct x
{
	float largura;
	float altura;
	char nome[25];
	int quantidadeArvore;
	int quantidadeConstrucao;
	int numero;
	arvore a[10];
}setor;

void Menu();
void cadastrarSetor(setor s[10],int quantidadeSetor);
void cadastrarArvore(setor s[10],int indiceSetor);
int setorIndice(setor s[10],int quantidadeSetor,int numeroSetor);
void listarSetor(setor s[10],int quantidadeSetor);
void listarArvore(setor s[10],int indiceSetor);
void listartudo(setor s[10],int quantidadeSetor,int indiceSetor);

int main(){
	
setor s[10];
int quantidadeSetor=0,op,numeroSetor,indice;

do{
		Menu();
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastrarSetor(s,quantidadeSetor);
				quantidadeSetor++;
				break;
			case 2:
				listarSetor(s,quantidadeSetor);
				break;
			case 3:
				printf("Numero do setor: ");
				scanf("%d",&numeroSetor);
				indice=setorIndice(s,quantidadeSetor,numeroSetor);
				if(indice<0){
					printf("Setor nao encontrado\n");
				}else{
					cadastrarArvore(s,indice);
				}
				break;
			case 4:
				printf("Numero do setor: ");
				scanf("%d",&numeroSetor);
				indice=setorIndice(s,quantidadeSetor,numeroSetor);
				if(indice<0){
					printf("Setor não encontrado\n");
				}else{
					listarArvore(s,indice);
				}	
			case 5:
				listartudo(s,quantidadeSetor,indice);
				break;
			
		}

	}while(op!=0);
	
	
	return 0;	
}


void Menu(){
printf("\n------------menu--------------\n\n");
	printf("1. Cadastrar setor\n");
	printf("2. Listar Setores\n");
	printf("3. Cadastrar arvores\n");
	printf("4. Listar arvores\n");
	printf("5. Listar setores e arvores\n");	
	printf("0. Sair \n");
}

void cadastrarSetor(setor s[10],int quantidadeSetor){
	printf("\n----------------------\n");
	printf("Numero: ");
	scanf("%d",&s[quantidadeSetor].numero);
	printf("Setor: ");
	scanf(" %[^\n]s",s[quantidadeSetor].nome);
	printf("Largura: ");
	scanf("%f",&s[quantidadeSetor].largura);
	printf("Altura: ");
	scanf("%f",&s[quantidadeSetor].altura);
	printf("Quantidade de construcao: ");
	scanf("%d",&s[quantidadeSetor].quantidadeConstrucao);
	s[quantidadeSetor].quantidadeArvore=0;

}

void cadastrarArvore(setor s[10],int indiceSetor){
	int i=s[indiceSetor].quantidadeArvore;
	printf("-------------Arvore----------\n");
	printf("Especie:");
	scanf(" %[^\n]s",s[indiceSetor].a[i].especie);
	printf("Porte:");
	scanf(" %[^\n]s",s[indiceSetor].a[i].porte);
	printf("Ano de plantio:");
	scanf("%d",&s[indiceSetor].a[i].anoplantio);
	printf("Quem plantou:");
	scanf(" %[^\n]s",s[indiceSetor].a[i].nomeplantador);
	s[indiceSetor].quantidadeArvore++;

}

int setorIndice(setor s[10],int quantidadeSetor,int numeroSetor){
	int i;
	for (i = 0; i < quantidadeSetor ; ++i)
	{
		if(s[i].numero==numeroSetor){
			return i;
		}
	}
	return -1;
}

void listarSetor(setor s[10],int quantidadeSetor){
	int i;
	for (i = 0; i < quantidadeSetor	; ++i)
	{	
	
		printf("\n----------------------\n");
		printf("Numero: %d\n",s[i].numero);
		printf("Setor: %s\n",s[i].nome);
		printf("Largura: %.2f\n",s[i].largura);
		printf("Altura: %.2f \n",s[i].altura);
		printf("Quantidade de construcao: %d \n",s[i].quantidadeConstrucao);
		printf("Quantidade de Arvores Plantadas: %d",s[i].quantidadeArvore);
	}
}

void listarArvore(setor s[10],int indiceSetor){
	int i ;
	for (i = 0; i < s[indiceSetor].quantidadeArvore; ++i)
	{
		printf("\n-------------Arvore %d----------\n",i);
		printf("Especie: %s\n",s[indiceSetor].a[i].especie);
		printf("Porte: %s\n",s[indiceSetor].a[i].porte);
		printf("Ano de plantio: %d \n",s[indiceSetor].a[i].anoplantio);
		printf("Nome de quem plantou: %s\n",s[indiceSetor].a[i].nomeplantador);
	}
}

void listartudo(setor s[10],int quantidadeSetor, int indiceSetor){
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < quantidadeSetor	; ++i)
	{	
	
		printf("\n----------------------\n");
		printf("Numero: %d\n",s[i].numero);
		printf("Setor: %s\n",s[i].nome);
		printf("Largura: %.2f\n",s[i].largura);
		printf("Altura: %.2f \n",s[i].altura);
		printf("Quantidade de construcao: %d \n",s[i].quantidadeConstrucao);
		printf("Quantidade de Arvores Plantadas: %d",s[i].quantidadeArvore);
		
		for(j = 0; j < s[i].quantidadeArvore; ++j)
		{
			k = j+1;
			printf("\n-------------Arvore %d----------\n",k);
			printf("Especie: %s\n",s[i].a[j].especie);
			printf("Porte: %s\n",s[i].a[j].porte);
			printf("Ano de plantio: %d \n",s[i].a[j].anoplantio);
			printf("Nome de quem plantou: %s\n",s[i].a[j].nomeplantador);
		}
	}
}

