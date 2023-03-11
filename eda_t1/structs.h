#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct registo
{
	int codigo;
	char tipo[50];
	float bateria;
	float autonomia;
	float custo;
	char loc[50];
	struct registo* seguinte_m;
} meio;

typedef struct registo2 {
	int nif;
	char palavra_passe[50];
	char nome[50];
	char morada[50];
	float saldo;
	struct registo2* seguinte;
} cliente;

cliente* inserircliente(cliente* inicio,int nif,char palavra_passe[],char nome[],char morada[]);
void listarclientes(cliente* inicio);
int existecliente(cliente* inicio, int nif);
int c_confirmaconta(cliente* inicio, int nif,char palavra_passe[]);

typedef struct registo3
{
	int nif_g;
	char nome_g[50];
	char palavra_passe_g[50];
	struct registo3* seguinte_g;
}gestor;
gestor* inserirgestor(gestor* inicio,int nif_g,char palavra_passe_g[]);
typedef struct registo4
{
	int cod_a;
	int nif;
	char hora[10];
	char veiculo[50];
	struct registo4* seguinte_a;
}aluguer;
